##Explicación del ejercicio.

En mi proyecto trato los futures de forma asíncrona para ello he creado un programa que recibe un número y tras un pequeño periodo de tiempo te indica si el número es primo.
Para ello utiliza una función auxiliar booleana llamada "primo" que de una forma básica comprueba que un número sea o no primo.
Después tenemos la función main en la que creamos la variable fut mediante el futuro y llamamos de forma asíncrona con el método async a la función primo junto con el número a comprobar,
después entra el crono que genera un pequeño retardo en el programa para poder establecer el get en el future.

Finalmente llamamos al get sobre nuestro booleano fut creado como future y devolvemos el resultado.
