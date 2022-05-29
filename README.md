# Ejercicios prácticos - Implementación 2022

Los ejercicios consistirán en construir y realizar la implementación de cuatro ejemplos, un ejemplo de cada uno de los bloques siguientes:

- Objetos
- Dependencias
- Calidad
- Funciones

De cada bloque se elegirá un solo tema sobre el que construir el ejemplo. 
La implementación se realizará en un lenguaje también a elegir. Los ejemplos serán similares a los estudiados en teoría, o propuestos por cada alumno. La elección de un tema para implementar un ejemplo no excluye utilizar elementos de otros temas, aunque se intentará centrar el ejemplo sobre todo en la implementación de elementos del tema elegido.

## Procedimiento

1. Elegir un tema de cada bloque, según la [lista de temas](#temas).
   - Notificar por correo en el campus al profesor los temas elegidos y esperar su confirmación.
   - Estudiar los ejemplos del tema estudiados en clases de teoría, o bien proponer un ejemplo alternativo.
2. Elegir al menos un lenguaje de implementación de entre los siguientes:
   - [Scala](https://www.scala-lang.org/)
   - [Python](https://www.python.org/)
   - [TypeScript](https://www.typescriptlang.org/) y JavaScript
   - [C#](https://docs.microsoft.com/en-us/dotnet/csharp/)
   - [Ruby](https://www.ruby-lang.org/)
   - Cualquier otro lenguaje que tenga un mecanismo útil de implementación del tema elegido y el ejemplo propuesto
3. Implementar los ejemplos empleando los mecanismos del lenguaje elegido.
   - Incluir una breve explicación escrita en [markdown](https://en.wikipedia.org/wiki/Markdown), que incluya instrucciones sobre cómo construir, compilar y ejecutar el ejemplo.
   - Incluir en el código un programa principal breve de demostración del ejercicio.
   - Ubicar los ficheros markdown y el código fuente del ejemplo en la carpeta con el nombre del tema situada bajo la carpeta `temas`.
   - Los nombres permitidos para las carpetas a situar bajo `temas/` son: 
     - `encapsulacion`,
     - `herencia`,
     - `delegacion`,
     - `uniones`,
     - `inyeccion`,
     - `anotaciones`,
     - `aspectos`,
     - `contratos`,
     - `undefined`,
     - `lambdas`,
     - `promesas` o `futuros`,
     - `observables`.
4. Publicar los ejemplos en un repositorio github
   - Todos los ficheros deben estar realizados sobre carpetas cuyos nombres coincidan con los nombres de los [temas](#temas) elegidos.
   - El repositorio debe incluir un fichero `README.md` con las instrucciones, el código implementado y los ficheros de configuración y makefiles necesarios para compilar y probar el ejemplo.
5. Hacer la presentación del ejercicio realizado de alguna de estas dos formas:
    - Pedir fecha al profesor para presentar el ejemplo en clase, o bien...
    - Grabar un video explicativo de menos de 8' y entregarlo a través del campus.

## Temas

### Bloque I. Objetos

#### Encapsulación

Implementar el ejemplo final de [Recorrido de listas](http://dodero.github.io/iiss/iiss-oop-1/#implementacion-alternativa-lista-v04) usando los mecanismos del lenguaje para definición de tipos de datos, ocultación de la implementación, aplicación del principio de acceso uniforme y especificación de la inmutabilidad del estado de un objeto. Por ejemplo:

- En Ruby, se podrían usar `:symbols`, `module`, `@variables` de instancia, `attr_accessor`, `attr_reader`, `attr_writer`, etc.
- En Scala, se podrían usar modificadores de visibilidad (`private`, `protected`), `var`, `val`, `type`, `abstract`, `sealed`, etc.
- En C#, se podrían usar modificadores de visibilidad y _properties_ `get`,`set` e `init`, etc.

#### Herencia

Implementar el ejemplo de [Aventura](http://dodero.github.io/iiss/iiss-oop-1/#ejemplo-aventura-v01) usando los mecanismos de herencia y polimorfismo de inclusión que proporcione el lenguaje. Por ejemplo:

- En Scala, podría usarse el mecanismo básico de herencia (`extends`), mixins (`traits`), `with`, etc.
- En C#, se podrían usar el mecanismo básico de herencia, `interface`, `base`, `override`, `virtual`, `new`, etc.

#### Delegación 

Implementar el ejemplo final de [Orquesta](http://dodero.github.io/iiss/iiss-oop-2/#implementacion-alternativa-orquesta-v06) usando los mecanismos del lenguaje para la delegación/composición. Intentará evitarse el uso de _lambdas_, que están destinadas a otro bloque. Por ejemplo:

- En C# podrían usarse `delegates`.
- En Scala, podrían usarse _first-class functions_.
- En Ruby, podrían usarse bloques, `proc`, `module` y `delegate`.

#### Uniones

Implementar un ejemplo de uso de uniones _type-safe_ empleando los mecanismos disponibles en el lenguaje. Por ejemplo:

- En C++17, usar [`std::variant`](https://en.cppreference.com/w/cpp/utility/variant).
- En Scala, usar [unions](https://docs.scala-lang.org/scala3/book/types-union.html) y _tagged unions_ de Scala 3.


### Bloque II. Dependencias

#### Inyección

 Implementar el ejemplo de la identificación de [BankAccount](http://dodero.github.io/iiss/iiss-oop-3/#ejercicio-identificador-de-bankaccount-con-inyeccion-de-dependencias) y que se puedan definir diversos atributos para comparar cuentas, usando los mecanismos del lenguage para inyectar como dependencia el criterio de comparación. Por ejemplo:
 
- En Java, puede usarse el framework [Guice](https://github.com/google/guice/wiki/) o [Weld CDI](http://weld.cdi-spec.org/)
- En Scala, puede usarse el framework [Play](https://www.playframework.com/) que implementa la inyección de dependencias [en tiempo de compilación](https://www.playframework.com/documentation/2.8.x/ScalaCompileTimeDependencyInjection).

 
#### Anotaciones

Implementar el ejemplo de [BankAccount](http://dodero.github.io/iiss/iiss-oop-3/#ejercicio-identificador-de-bankaccount-con-inyeccion-de-dependencias) con diversos atributos comparables, usando los  mecanismos de anotaciones que el lenguaje proporcione para inyectar como dependencia el comparador a usar. Por ejemplo:

- En Java, podrían definirse anotaciones a medida para inyección de dependencias en _runtime_, según el [JSR 330](http://javax-inject.github.io/javax-inject/). Ejemplo: [Creating a Custom Annotation in Java](http://baeldung.com/java-custom-annotation) de Baeldung
- En TypeScript, podrían usarse [_decorators_](https://www.typescriptlang.org/docs/handbook/decorators.html).
- En Scala, puede usarse el framework Play que implementa el [JSR 330](http://javax-inject.github.io/javax-inject/).

#### Aspectos

Implementar usando aspectos el ejemplo del caso [Editor de Figuras](http://dodero.github.io/iiss/iiss-aop/#caso-5-editor-de-figuras). Por ejemplo:

- En Java, usar intercepción de métodos con [Guice](https://github.com/google/guice/wiki/AOP)
- En Python, usar [Spring Python](https://docs.spring.io/spring-python/1.2.x/sphinx/html/aop.html#aspect-oriented-programming)


### Bloque III. Calidad 

#### Contratos

Implementar ejemplos de contratos, usando una librería disponible en el lenguaje de elección para programar contratos. Por ejemplo:

- En Java, podría usarse bibliotecas específicas para programar contratos como [Contracts for Java](https://github.com/nhatminhle/cofoja), [Oval](https://sebthom.github.io/oval/USERGUIDE.html#programming-by-contract) o [Valid4J](http://www.valid4j.org/).

- En Scala, podrían usarse los mecanismos del lenguaje disponibles en [Predef.scala](https://www.scala-lang.org/api/2.13.6/scala/Predef$.html), como por ejemplo: `assert`, `assume`, `require`, `ensuring`, etc.

- En Kotlin, podría usarse el mecanismo experimental [`contract`](https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.contracts/)


#### Undefined

Implementar el ejemplo del caso "MobileTester" del apartado [Optionals](http://dodero.github.io/iiss/iiss-err/#optionals) usando los mecanismos del lenguaje para resolver el problema de los valores _undefined_ y el mal uso de `null`. Por ejemplo:

- En C++, podría usarse [`std::optional`]((https://en.cppreference.com/w/cpp/utility/optional))
- En Scala, podrían usarse los mecanismos de la biblioteca del lenguaje como `Option`, `Some`, `None`, `Either`, `Left`, `Right`, etc.

### Bloque IV. Funcional y Asíncrono

#### Lambdas

Implementar ejemplos del uso de funciones anónimas (expresiones _lambda_) empleando los mecanismos disponibles en el lenguaje elegido. Por ejemplo:

- En C++, usar lambdas genéricas de C++11, lambdas variádicas de C++14/C++17 y lambdas mutables.
- En Scala, usar [funciones anónimas](https://docs.scala-lang.org/scala3/book/fun-anonymous-functions.html) de Scala 3
- En Ruby, usar `lambdas`.

#### Promesas y Futuros

Implementar un ejemplo de programación asíncrona, similar a los mostrados en [Promesas y futuros](http://dodero.github.io/iiss/iiss-evp-2/#promesas), que emplee los mecanismos disponibles en el lenguaje. Por ejemplo:

- En C++, usar [`std::async`](https://en.cppreference.com/w/cpp/thread/async) y [`std::promise`](https://en.cppreference.com/w/cpp/thread/promise) y [`std::future`](https://en.cppreference.com/w/cpp/thread/future)
- En Scala, usar [`Future`](https://docs.scala-lang.org/overviews/core/futures.html) o `Promise` de `scala.concurrent`.


#### Observables

Implementar un ejemplo de procesamiento de streams de eventos asíncronos empleando una biblioteca [ReactiveX](http://reactivex.io/intro.html) para el lenguaje elegido. Por ejemplo:
 
- En C++, usar los elementos _observable_ de la biblioteca [RxCpp](http://reactivex.io/RxCpp/index.html).
- En Scala, usar el framework [Akka](https://akka.io/) o el trait [`Observable`](https://reactivex.io/rxscala/scaladoc/index.html#rx.lang.scala.Observable) de las extensiones [RxScala](https://reactivex.io/rxscala/).

## Asignación

|   | Lenguaje  | Bloque I OBJETOS  | Bloque II DEPENDENCIAS  | Bloque III CALIDAD  | Bloque IV FUNCIONAL Y ASINC |
|---|---|---|---|---|---|
| [SANCHIDRIÁN HERRERA, PABLO](https://github.com/PaulSanHerr)  | TypeScript  | [Herencia](temas/herencia/typescript/)  | [Anotaciones](temas/anotaciones/typescript/)  | [Undefined](temas/undefined/typescript/) | [Arrow functions](temas/lambdas/typescript/) |
|   |   |   |   |   |   |
| [SAUCEDO GARCÍA, JUAN MANUEL](http://github.com/juanmanuelsaucedo)  | C++, Java  | [Unión (C++)](temas/uniones/cpp/)  | Aspectos (Java)  | [Undefined (C++)](temas/undefined/cpp/) | Observables (C++) |
|   |   |   |   |   |   |
| [ROBLES SORROCHE, LUIS](http://github.com/luisroblessorroche)        |   Python   |  [Delegación](temas/delegacion/python/) |  [Inyección](temas/inyeccion/python/)  | [Undefined](temas/undefined/python/) | [Observables](temas/observables/python/) |
|   |   |   |   |   |   |
| [VÁZQUEZ SÁEZ, MARÍA](http://github.com/mariavazquezss) | C#, Java, C++ | [Herencia(C#)](temas/herencia/csharp/)  | [Inyección (Java)](temas/inyeccion/java-di-1/)  | [Contratos(valid4j)](temas/contratos/java-valid4j/) | Promesas y Futuros (C++) |
|   |   |   |   |   |   |
| [BERNAL PÉREZ, FRANCISCO JOSÉ](http://github.com/FcoJoseBernalPerez)|   C#, Python, Java, C++   |  Delegación(C#)  |  [Aspectos(Python)](temas/aspectos/python/)  | [Contratos(Java)](temas/contratos/java-cofoja/) | Lambdas(C++) |
|	|	|	|	|	|	|
| [VELO HUERTA, CRISTÓBAL JOSÉ](http://github.com/CJVH-UCA)| Python, Java | [Herencia(Python)](temas/herencia/python/) | Aspectos(Java con Guice) | [Contratos(Python)](temas/contratos/python/) | [Lambdas(Python)](temas/lambdas/python/) |
|  |  |  |  |  |  |
| [PÉREZ MERCADO, RUBÉN](http://github.com/rubenperezm)| Kotlin | [Herencia](temas/herencia/kotlin) | [Anotaciones](temas/anotaciones/kotlin) | [Null Safety](temas/undefined/kotlin) | [Lambdas](temas/lambdas/kotlin) |
|  |  |  |  |  |  |
| [LOIZ JORDAN, CARLOS](https://github.com/carlosloiz97)| C# | Herencia | Inyección | Contratos | Lambdas |
|  |  |  |  |  |  |
| [CARO BARRERA, LUCÍA](https://github.com/luciacarobar)| Python, Java, Scala y C++ | Encapsulación(Python) | Inyección(Java) | Contratos(Scala) | Lambdas(C++) |