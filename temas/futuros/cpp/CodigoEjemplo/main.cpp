//
//  main.cpp
//  Prueba
//
//  Created by Maria V
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
