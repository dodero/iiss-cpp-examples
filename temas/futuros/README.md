Explicación del ejercicio de Futuros.

El programa que se muestra es una pequeña función que comprueba si un número es o no primo. 
Para ello se utiliza una función básica que comprueba si un número es primo comprobando restos en un bucle for.
A continuacion usando el future se crea un booleano fut y se llama de forma asíncrona a la funcion primo junto con el número a comprobar.
Una vez ocurre esto se inicia un temporizador esto se usa para que se ejecute otra tarea y asi el future pueda tomar el get().
Finalmente se devuelve si el número es primo o no.
