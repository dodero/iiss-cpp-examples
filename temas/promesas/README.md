Promesas en C++
===============

Introducción
------------


En este ejemplo de programación veremos el uso de promesas, futuros y async para la creación de una función que realice el cálculo de un factorial.


Mecanismos a utilizar
---------------------

Para la realización de este ejercicio necesitaremos 3 mecanismos que nos proporciona la biblioteca std::future de C++

* std::promise<T> : Este mecanismo nos permite declarar una promesa, la cual "prometerá" el paso de un parámetro en el futuro a una función determinada. La promesa obtiene un tipo future, el cual se obtendrá en el futuro y la función lo procesará. En la siguiente imagen mostramos la declaración de nuestra promesa principal.
![](https://github.com/gonzalouli/iiss-cpp-examples/blob/promesas/temas/promesas/imgs/promise1.png)


* std::future<T> : El tipo futuro nos permite declarar una variable de un tipo T, la cual será procesada en el futuro por una funcion asincrona (en este caso). Y a este le asignamos el futuro de una promesa ya declarada.
![](https://github.com/gonzalouli/iiss-cpp-examples/blob/promesas/temas/promesas/imgs/promise2.png)


* std::async() : Este metodo nos permite crear un nuevo hilo (o no ...) y procesar una función. En este caso, vamos a realizar una función asincrona con un tipo futuro. Async puede realizarse creando un hilo, o realizando la funcion en diferido; esto dependerá del primer parámetro que le pasemos a async: std::launch::async o std::launch::deferrec. En este caso realizaremos el asincrono. También pasaremos a async la funcion a ejecutar, asi como la referencia (std::red(f)) a un valor futuro, el cual lo tomaremos de la promesa con get_future();
![](https://github.com/gonzalouli/iiss-cpp-examples/blob/promesas/temas/promesas/imgs/promise3.png)


* Realizamos un uso de captura de excepciones si la toma del valor de la promesa o la devolucion del valor futuro del hilo asincrono produden un error. En caso afirmativo tomaremos con el metodo set_exception de la promesa la excepcion actual.
![](https://github.com/gonzalouli/iiss-cpp-examples/blob/promesas/temas/promesas/imgs/factorial4.png)


Explicacion del ejemplo
-----------------------
En primer lugar, realizaremos nuestro main para llamar a la funcion _functionFactorial_ a la cual pasaremos un parámetro de tipo _future<int>_.
En este main, instanciaremos el valor del factorial a calcular, por ejemplo 5, y declararemos una variable para recibir este valor posteriormente.
![](https://github.com/gonzalouli/iiss-cpp-examples/blob/promesas/temas/promesas/imgs/flujo1.png)

A continuacion, empezaremos a preparar nuestra promesa para el valor futuro. Para ello, declararemos un tipo _promise<int>_ y un tipo _future<int>_, ambos de la biblioteca estándar. A la declaracion del futuro le asignatremos un valor futuro que esperará de nuestra promesa cuando esta ultima se cumpla.
 
 ![](https://github.com/gonzalouli/iiss-cpp-examples/blob/promesas/temas/promesas/imgs/promise1.png)
 ![](https://github.com/gonzalouli/iiss-cpp-examples/blob/promesas/temas/promesas/imgs/promise2.png)

Realizadas las operaciones anteriores nos reparamos la ejecución asincrona de nuestra función. Dicha ejecución, devolverá un falor _future<int>_ el cual su plantilla será proporcionada por nuestra función. Para preparar la ejecucion asincrona debemos realizar la siguiente llamada al método _std::async_:
![](https://github.com/gonzalouli/iiss-cpp-examples/blob/promesas/temas/promesas/imgs/flujo2.png)
En esta llamada, realizaremos el lanzamiento de _async_ de forma _std::launch::async() (por defecto), después, le indicaremos la función para realizar dentro de esta envoltura asincrona, y seguidamente, los parametros de dicha función. En este caso, tendremos que pasar la promesa de futuro _promiseOfFuture_ declarada anteriormente envuelta en la función _std::ref()_ para pasarla por referencia.

Al realizar lo anterior, la función empezara a ejecutarse en otro hilo independiente al principal.
Dicha función no se ejecutara completamente debido a que esta necesita que el hilo principal aplique el valor deseado a la promesa, pudiendo esta realizar la devolución del futuro al valor del parametro de dicha función. Cuando se haya realizado todo lo anterior, operacion _promiseOfFuture.get()_ dentro de nuestra funcion proporcionara el valor deseado a la variable _numberFactorial_ y esta proseguira su flujo de ejecución.
![](https://github.com/gonzalouli/iiss-cpp-examples/blob/promesas/temas/promesas/imgs/flujo3.png)

Para funalizar la ejecución del programa, realizaremos la toma del valor futuro con _future.get()_ de nuestra función, y lo asignaremos a nuestra variable _factorial_ declarada anteriormente. Por ultimo, mostraremos el resultado o mostraremos una excepción dependiendo del caso, y terminaremos la ejecución de la función principal.
![](https://github.com/gonzalouli/iiss-cpp-examples/blob/promesas/temas/promesas/imgs/factorial4.png)




Compilación y ejecución
-----------------------

Para compilar este ejemplo simplemente tendremos que ejecutar este comando en el directorio donde se encuentra:
 > g++ -std=c++17 -O2 -Wall -pedantic -pthread main.cpp && ./a.out

Cabe decir que solamente funcionará este programa si el computador en el que se compila y ejecuta tiene una version de C++ correcta.

Para mas facilidad de prueba, dirijase al compilador online [Coliru](http://coliru.stacked-crooked.com/)

