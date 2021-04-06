# POOkemon
POOkemon es una pequeña demostración de cómo utilizar los mecanismos de herencia en C++. Se trata de un ejemplo basado en el famoso mundo de Pokémon. En él, tenemos una clase base llamada `Pokemon`, que se especializará en varias clases dependiendo de los tipos de pokemon que queramos representar. En este ejemplo, usaremos los `PokemonTipoPlanta`,`PokemonTipoFuego` y `PokemonTipoAgua`. En la demostración, instanciaremos objetos de cualquiera de las clases hijas y las pondremos a "combatir" entre ellas. El ganador hará una celebración distinta dependiendo de su tipo. ¿Quién ganará?

## Diseño
Durante la implementación del ejemplo, Juan Manuel Dodero me aconsejó el uso del patrón Mediator para conseguir el comportamiento deseado. Dicho patrón se ha utilizado y puede verse reflejado en las clases `AtaquesMediator` y `AtaquesImp`, las cuales se ocupan del comportamiento de los ataques teniendo en cuenta el Pokemon atacante y el objetivo. De esta forma conseguimos reducir el acoplamiento de las clases de forma que si en un futuro quisieramos añadir nuevos tipos de Pokemon o de ataques, apenas tendríamos que tocar la clase `AtaquesImp` y el tipo enumerado `Tipo`. Sin el patrón, tendríamos que tocar todas las implementaciones de `Pokemon` para añadir un nuevo tipo, ya que el comportamiento de los ataques se resolvería desde su lado.

## Compilación
En el paquete se proporciona un Makefile, por lo que si se tiene instalada la funcionalidad `make`, solo será necesariario utilizar la orden `make` desde la carpeta del proyecto.

## Uso
Para poner en funcionamiento el ejemplo del combate Pokémon, solo tendremos que ejecutar el archivo `combate.exe` que se generará tras la compilación.

## Autor
El ejemplo ha sido desarrollado por Jesús Serrano Gallán con la supervisión de Juan Manuel Dodero.

