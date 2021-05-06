# Undefined, el mal uso de null y las respuestas de C++
## Contexto
Tal y como se ha comentado durante el curso y las sesiones concernientes a esta temática, la constante paranoia (justificada o no) de la posible existencia de valores nulos dentro de nuestros códigos en primera instancia nos puede llevar a realizar un tipo de programación defensiva que, aunque en primera instancia pudiera parecer sensata, viene con una mochila de problemas cuyas dimensiones nos acabarán desbordando.

En el propio material de la asignatura vemos los catastróficos antecedentes a estas situaciones que se originarían si no utilizásemos mecanismos alternativos. Se menciona el uso de asertos, que como comentábamos en clase han de ser utilizados (en caso de querer hacerlo correctamente) como herramientas de 'debug', no como herramientas para el control de errores. C++ por supuesto, incorpora estos asertos mediante `<casert>`, que no es más que la adaptación a C++ de la bilbioteca de C `<assert.h>`.

Hay quizás otras soluciones que podrían venir a nuestra cabeza a fin de intentar paliar estas situaciones, pero de la que trata el ejercicio que se me ha asignado es el uso de `std::optional`, incluida en la cabecera `<optional>`.

## La clase Optional
Tal y como se define en <a href="https://en.cppreference.com/w/cpp/utility/optional">la referencia de C++</a>, *es una clase plantilla con a que manipular un valor opcional contenido en ella que, bien puede estar o no presente*.

Además se nos comenta que es una solución más sencilla y menos pesada (en terminos de espacio en memoria) que hacer uso de soluciones menos elegantes como el uso de `std::pair<T, bool>`. En lugar de realiazar comparaciones complejas y ad hoc para cada situación, con *optional* tendremos maneras más sencillas de afrontar estas situaciones. Para mostrarlo, replicaremos el ejemplo mostrado en clase llamado *Mobile Tester*.

Para replicar este ejemplo se han definido todas las clases que figuraban en el ejemplo de clase con las adaptaciones necesarias debidas al lenguaje y a la propia implementación de los mecanismos como el *optional*.

La sintáxis de la clase en C++ es relativamente parecida a la que se tiene en Java, aunque ciertamente en C++ es más escueta y no aporta a priori ciertas operaciones que en Java son parte de la propia clase. Para nuestro ejemplo, no tenemos especial dificultad al adaptar el código, no así en el caso de la función *Mobile Service*, que al hacer uso de sintáxis más fluida ya de por sí implementada en la clase, no he sabido trasladar a C++. El resultado es el mismo pero, ciertamente, no es tan elegante.

## Los ficheros
Para mantener una mínima separación entre los distintos códigos de los que consta el ejemplo se han definido tres ficheros, *MobileTester_Optional.hpp*, *MobileService.hpp* y *Main.cpp*. Detro del primero se encuentran las clases utilizadas en el ejemplo con la implementación de los métodos que conciernen al mismo. En el segundo, la implementación del servicio que calcula de manera segura mediante los optional el ancho de la pantalla. Por último, el fichero *Main*, como sospechará un avispado lector, aglutina la propia puesta en acción del ejemplo.

## Compilación y ejecución.
Dada la pequeña escala del proyecto, el código se ha compilado mediante consola sin la ayuda de utilidades como *make* u otras del estilo. Como apunte, hay que tener en cuenta que ```<optional>``` llegó a C++ en su verión 17, con lo cual, es probable que debamos indicar a nuestro compilador que utilice esta versión o posterior. Como curiosidad, en lo personal la compilación se realizó en consola mediante la orden: ```g++ -std=c++17 -o Optionals Main.cpp```.