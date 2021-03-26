Promesas en C++
===============

Introducción
------------

En este ejemplo de programación veremos el uso de promesas, futuros y async para la creacion de una funcion que realice el calculo de un factorial. 

Mecanismos a utilizar
---------------------

Para la realización de este ejercicio necesitaremos 3 mecanismos que nos proporciona la biblioteca std::future de C++

* std::promise<T> : Este mecanismo nos permite declarar una promesa, la cual "prometerá" el paso de un parámetro en el futuro a una funcion determinada. La promesa obtiene un tipo future, el cual se obtendrá en el futuro y la función lo procesará.

* std::future<T> : El tipo futuro nos permite declarar una variable de un tipo T, la cual será procesada en el futuro por una funcion asincrona (en este caso).

* std::async() : Este metodo nos permite crear un nuevo hilo (o no ...) y procesar una funcion. En este caso, vamos a realizar una funcion asincrona con un tipo futuro. Async puede realizarse creando un hilo, o realizando la funcion en diferido; esto dependerá del primer parámetro que le pasemos a async: std::launch::async o std::launch::deferrec. En este caso realizaremos el asincrono. También pasaremos a async la funcion a ejecutar, asi como la referencia (std::red(f)) a un valor futuro, el cual lo tomaremos de la promesa con get_future();


Compilación y ejecución
-----------------------

Para compilar este ejemplo simplemente tendremos que ejecutar este comando en el directorio donde se encuentra:
 > g++ -std=c++17 -O2 -Wall -pedantic -pthread main.cpp && ./a.out

Cabe decir que solamente funcionará este programa si el computador en el que se compila y ejecuta tiene una version de C++ correcta.
Para mas facilidad de prueba, dirijase al compilador online [Coliru](http://coliru.stacked-crooked.com/)