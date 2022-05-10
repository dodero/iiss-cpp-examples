# Promesas y Futuros en C++
## Promesas
Son utilizadas por el "productor/escritor" de la operación asíncrona.
Para crear funciones asíncronas de tipo "productor/escritos", podemos hacerlo de las siguientes maneras:
```c++
std::packaged_task<int()> suma([]{ return (4 + 6); });
```
```c++
std::promise<int> suma;
```

## Futuros
Son utilizados por el "consumidor/lector" de la operación asíncrona.
Una vez disponemos de funciones asíncronas de tipo "productor/escritor" tenemos que asignar su resultado para poder ser utilizado, para ello hacemos uso de los futuros de la siguiente manera:
```c++
std::future<int> f_suma = suma.get_future();
```
Posteriormente, para que la función sea ejecutada debemos lanzar un hilo que la envuelva lo que podemos hacer de varias formas:
```c++
std::thread hilo(std::move(suma));
```

```c++
std::thread( [&suma]{ suma.set_value_at_thread_exit(9 + 2); }).detach();
```
Como podemos comprobar, en esta segunda forma de lanzar el hilo también estamos implementando la función **suma**. Concretamente, establece el resultado en un valor específico mientras entrega la notificacion, pero sólo al salir del hilo.

Además, otra manera de obtener el resultado de una función de forma asíncrona haciendo uso de futuros es la siguiente:
```c++
 std::future<int> f_suma = std::async(std::launch::async, []{ return (8 + 4); });
```
Esta forma es más literal, ya que hacemos uso del método **async** que se encarga directamente de ejecutar la función de forma asíncrona y devolver el resultado de la misma en un futuro.

## Ejemplo
En el siguiente ejemplo podemos ver como usar las promesas y futuros usando las diferentes maneras explicadas anteriormente.
```c++
#include <iostream>
#include <future>
#include <thread>
 
int main()
{
    //Creamos una función asincrona suma
    std::packaged_task<int()> suma([]{ return (4 + 6); });
    //Asignamos el resultado de la funcion suma
    std::future<int> f_suma = suma.get_future();
    //Lanzamos un hilo con la funcion anterior
    std::thread hilo(std::move(suma));
 
    // Ejecuta uan funcion de forma asincrona y devuelve el resultado en un future
    std::future<int> f_resta = std::async(std::launch::async, []{ return (8 - 4); });
 
    //Creamos una funcion asincrona usando promise
    std::promise<int> multi;
    //Asignamos el resultado de la funcion multi
    std::future<int> f_multi = multi.get_future();
    //Lanzamos un hilo con la funcion multi
    std::thread( [&multi]{ multi.set_value_at_thread_exit(9 * 2); }).detach();//establece el resultado en un valor específico mientras entrega la notificación solo al salir del hilo
    
    //Esperamos a que los resultados de las funciones esten disponibles
    f_suma.wait();
    f_resta.wait();
    f_multi.wait();
    std::cout << "\nResultados: "
              << f_suma.get() << ' ' << f_resta.get() << ' ' << f_multi.get() << '\n';
    hilo.join();
}
```

### Salida
Para ejecutar el ejemplo, crearemos un fichero con extención **.cpp** y lo ejecutaremos con nuestro compilador g++. La salida obtenida es la siguiente:
```
Resultados: 10 4 18
```