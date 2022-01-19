# Ejercicios

## Procedimiento

1. Elegir un tema de cada bloque, según la [lista de temas](#temas).
   - Notificar por correo en el campus al profesor los temas elegidos y esperar su confirmación.
   - Estudiar el ejemplo del tema estudiado en clases de teoría, o bien proponer un ejemplo alternativo.
2. Elegir al menos un lenguaje de implementación de entre los siguientes:
   - Scala
   - Python
   - TypeScript/JavaScript
   - C#
   - Ruby
   - Cualquier otro lenguaje que contenga un mecanismo útil para implementar el tema elegido
3. Implementar los ejemplos empleando los mecanismos del lenguaje elegido.
   - Incluir una breve explicación escrita en [markdown](https://en.wikipedia.org/wiki/Markdown), que incluya instrucciones sobre cómo construir, compilar y ejecutar el ejemplo.
   - Incluir en el código un programa principal breve de demostración del ejercicio.
   - Ubicar los ficheros markdown y el código fuente del ejemplo en la  carpeta con el nombre del tema situada bajo la carpeta `temas`.
4. Publicar los ejemplos en un repositorio github
   - Todos los ficheros deben estar realizados sobre carpetas cuyos nombres coincidan con los nombres de los [temas](#temas) elegidos.
   - Los nombres permitidos para las carpetas a situar bajo `temas/` son: `ocultacion`, `herencia`, `delegacion`, `uniones`, `inyeccion`, `anotaciones`, `aspectos`, `contratos`, `undefined`, `lambdas`, `promesas`, `futuros`, `observables`.
   - El repositorio debe incluir las instrucciones, el código realizado y los ficheros de configuración y makefiles necesarios para compilar y probar el ejemplo.
5. Hacer la presentación del ejercicio realizado de alguna de estas dos formas:
    - Pedir fecha al profesor para presentar el ejemplo en clase, o bien...
    - Grabar un video explicativo de menos de 8' y entregarlo a través del campus.

## Temas

### Bloque I. Objetos

#### Ocultación

Implementar el ejemplo final de [Recorrido de listas](http://dodero.github.io/iiss/iiss-oop-1/#implementacion-alternativa-lista-v04) usando los mecanismos de ocultación de la implementación que ofrezca el lenguaje. Por ejemplo:

- Si se elige C++, se podrían usar modificadores de visibilidad (`protected`, `private` y `friend`), `namespaces`, iteradores de `std`, etc.

#### Herencia

Implementar el ejemplo de [Aventura](http://dodero.github.io/iiss/iiss-oop-1/#ejemplo-aventura-v01) usando los mecanismos de herencia que proporcione el lenguaje. Por ejemplo:

- Si se elige C++, se podrían usar herencia simple o múltiple, `dynamic_cast`, polimorfismo estático (_templates_) o dinámico para implementar [mixins](https://michael-afanasiev.github.io/2016/08/03/Combining-Static-and-Dynamic-Polymorphism-with-C++-Template-Mixins.html), etc.
- Si se elige Scala, podría usarse el mecanismo básico de herencia (`extends`), mixins (`traits`), etc.

#### Delegación 

Implementar el ejemplo final de [Orquesta](http://dodero.github.io/iiss/iiss-oop-2/#implementacion-alternativa-orquesta-v06) usando los mecanismos del lenguaje para la delegación/composición. Por ejemplo:

- Si se elige C++, podrían usarse métodos polimórficos, funciones virtuales, etc.
- Si se elige C# podrían usarse `delegates`.

### Uniones

Implementar un ejemplo de uso de uniones _type-safe_ empleando los mecanismos disponibles en el lenguaje. Por ejemplo:

- En C++17, usar [`std::variant`](https://en.cppreference.com/w/cpp/utility/variant).
- En Scala, usar [unions](https://docs.scala-lang.org/scala3/book/types-union.html) y _tagged unions_ de Scala 3.


### Bloque II. Dependencias

#### Inyección

 Implementar el ejemplo de la identificación de [BankAccount](http://dodero.github.io/iiss/iiss-oop-3/#ejercicio-identificador-de-bankaccount-con-inyeccion-de-dependencias) y que se puedan definir diversos atributos para comparar cuentas, usando los mecanismos del lenguage para inyectar como dependencia el criterio de comparación. Por ejemplo:
 
 - Si se elige C++, podría usarse: polimorfismo paramétrico (_templates_), sobrecarga de operadores binarios, objetos función o [functors](https://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html), etc.
 
#### Anotaciones

Implementar el ejemplo de [BankAccount](http://dodero.github.io/iiss/iiss-oop-3/#ejercicio-identificador-de-bankaccount-con-inyeccion-de-dependencias) con diversos atributos comparables, usando los  mecanismos de anotaciones que el lenguaje proporcione para inyectar como dependencia el comparador a usar. Por ejemplo:

- Si se elige Java, podrían usarse anotaciones a medida, definidas según el [JSR 330](http://javax-inject.github.io/javax-inject/). Ejemplo: [Creating a Custom Annotation in Java](http://baeldung.com/java-custom-annotation) de Baeldung
- Si se elige TypeScript, podrían usarse [_decorators_](https://www.typescriptlang.org/docs/handbook/decorators.html).

#### Aspectos

Implementar usando aspectos el ejemplo del caso [Editor de Figuras](http://dodero.github.io/iiss/iiss-aop/#caso-5-editor-de-figuras). Por ejemplo:

- En C++, usar [AspectC++](https://www.aspectc.org/)
- En Python, usar [Spring Python](https://docs.spring.io/spring-python/1.2.x/sphinx/html/aop.html#aspect-oriented-programming)


### Bloque III. Calidad 

#### Contratos

Implementar ejemplos de contratos, usando una librería disponible en el lenguaje de elección para programar contratos. Por ejemplo:

- Si se elige Java, podría usarse bibliotecas específicas para programar contratos como [Contracts for Java](https://github.com/nhatminhle/cofoja) u [Oval](https://sebthom.github.io/oval/USERGUIDE.html#programming-by-contract)

- Si se elige Scala, podrían usarse los mecanismos del lenguaje disponibles en [Predef.scala](https://www.scala-lang.org/api/2.13.6/scala/Predef$.html), como por ejemplo: `assert`, `assume`, `require`, `ensuring`, etc.

- Si se elige Kotlin, podría usarse el mecanismo experimental [`contract`](https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.contracts/)


#### Undefined

Implementar el ejemplo del caso "MobileTester" del apartado [Optionals](http://dodero.github.io/iiss/iiss-err/#optionals) usando los mecanismos del lenguaje para resolver el problema de los valores _undefined_ y el mal uso de `null`. Por ejemplo:

- Si se usa C++, podría usarse [`std::optional`]((https://en.cppreference.com/w/cpp/utility/optional))
- Si se usa Scala, podrían usarse los mecanismos de la biblioteca del lenguaje como `Option`, `Some`, `None`, `Either`, `Left`, `Right`, etc.

### Bloque IV. Funcional y Asíncrono

#### Lambdas

Implementar ejemplos del uso de funciones anónimas (expresiones _lambda_) empleando los mecanismos disponibles en el lenguaje elegido. Por ejemplo:

- En C++, usar lambdas genéricas de C++11, lambdas variádicas de C++14/C++17 y lambdas mutables.
- En Scala, usar [funciones anónimas](https://docs.scala-lang.org/scala3/book/fun-anonymous-functions.html) de Scala 3
- En Ruby, usar `blocks`, `procs` y `lambdas`.

#### Promesas y Futuros

Implementar un ejemplo de programación asíncrona, similar a los mostrados en [Promesas y futuros](http://dodero.github.io/iiss/iiss-evp-2/#promesas), que emplee los mecanismos disponibles en el lenguaje. Por ejemplo:

- En C++, usar [`std::async`](https://en.cppreference.com/w/cpp/thread/async) y [`std::promise`](https://en.cppreference.com/w/cpp/thread/promise) y [`std::future`](https://en.cppreference.com/w/cpp/thread/future)


#### Observables

Implementar un ejemplo de procesamiento de streams de eventos asíncronos empleando una biblioteca [ReactiveX](http://reactivex.io/intro.html) para el lenguaje elegido. Por ejemplo:
 
- En C++, usar los elementos `observable` de la biblioteca [RxCpp](http://reactivex.io/RxCpp/index.html).

