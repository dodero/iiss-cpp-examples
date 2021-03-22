# Ejercicios

## Procedimiento

1. Elegir un tema de teoría de la [lista de temas](#temas).
2. Elegir el ejemplo del tema estudiado en clases de teoría, o bien proponer un ejemplo alternativo.
3. Implementar el ejemplo empleando los mecanismos del lenguaje que se proponga.
4. Explicar el ejemplo en [markdown](https://en.wikipedia.org/wiki/Markdown).
5. Ubicar los ficheros markdown y el código fuente del ejemplo en una carpeta con el nombre del tema.
6. Publicar el ejemplo en este repositorio, haciendo un pull request. Todos los ficheros (markdown y código fuente) deben estar en una carpeta cuyo nombre coincida con el nombre del [tema](#temas), en minúsculas y sin acentos: `ocultacion`, `herencia`, `delegacion`, `functors`, `anotaciones`, `undefined`, `aspectos`, `lambdas`, `mixins`.
7. Pedir fecha al profesor para presentar el ejemplo en clase, o bien grabar un video explicativo de menos de 8' y entregarlo a través del campus.

## Temas

### 1. Ocultación

Implementar en C++ el ejemplo final de [Recorrido de listas](http://dodero.github.io/iiss/iiss-oop-1/#implementacion-alternativa-lista-v04) usando los siguiente mecanismos de ocultación de la implementación en C++:

- Modificadores de visibilidad: `protected`, `private`, `friend`
- Iteradores de `std`

> Referencias: Capítulo 5 de _Bruce Eckel-Thinking in C++_

### 2. Herencia

Implementar en C++ el ejemplo de [Aventura](http://dodero.github.io/iiss/iiss-oop-1/#ejemplo-aventura-v01) usando los siguientes mecanismos de C++:

- Herencia simple
- Dynamic casting

>  Referencias: Capítulo 14 de _Bruce Eckel-Thinking in C++_


### 3. Delegación 

Implementar en C++ el ejemplo final de [Orquesta](http://dodero.github.io/iiss/iiss-oop-2/#implementacion-alternativa-orquesta-v06) usando los siguientes mecanismos de C++ para la delegación/composición: 

- Métodos polimórficos
- Funciones virtuales

> Referencias: Capítulo 15 de _Bruce Eckel-Thinking in C++_

### 4. Functors

 Implementar en C++ el ejemplo de la identificación de [BankAccount](http://dodero.github.io/iiss/iiss-oop-3/#ejercicio-identificador-de-bankaccount-con-inyeccion-de-dependencias) y que se puedan definir diversos atributos para comparar cuentas, usando los siguientes mecanismos de C++ para inyectar como dependencias el criterio de comparación:

- polimorfismo paramétrico (_templates_)
- sobrecarga de operadores binarios
- objetos función o _functors_
 
> Referencias:
>  - Capítulo 16 de _Bruce Eckel-Thinking in C++_
>  - Capítulo 12 de _Bruce Eckel-Thinking in C++_
>  - [Functors](https://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html) en C++

### 5. Anotaciones

Implementar en Java el ejemplo de [BankAccount](http://dodero.github.io/iiss/iiss-oop-3/#ejercicio-identificador-de-bankaccount-con-inyeccion-de-dependencias) con diversos atributos comparables, usando los siguientes mecanismos de Java para inyectar como dependencia el comparador a usar:

- anotaciones definidas a medida según el [JSR 330](http://javax-inject.github.io/javax-inject/) 

> Referencia: [Creating a Custom Annotation in Java](baeldung.com/java-custom-annotation) de Baeldung

### 6. Undefined

Implementar en C++ el ejemplo del caso "MobileTester" del apartado [Optionals](http://dodero.github.io/iiss/iiss-err/#optionals) usando los siguientes mecanismos del lenguaje para resolver el problema de los valores no definidos y el mal uso de `null`:

- `std::optional`

> Referencia: [CppReference](https://en.cppreference.com/w/cpp/utility/optional)

### 7. Aspectos

Implementar en C++ usando aspectos el ejemplo del caso [Editor de Figuras](http://dodero.github.io/iiss/iiss-aop/#caso-5-editor-de-figuras).

> Referencia: [AspectC++](https://www.aspectc.org/)


### 8. Lambdas

Implementar ejemplos en C++ del uso de funciones anónimas (expresiones _lambda_) empleando los siguientes mecanismos del lemguaje:

- Lambdas genéricas de C++11
- Lambdas variádicas de C++14/C++17
- Lambdas mutables 

> Referencias:
>  - [All About Lambda Functions in C++](https://dzone.com/articles/all-about-lambda-functions-in-cfrom-c11-to-c17)
>  - [Lambdas: From C++11 to C++20: Part 1](https://www.bfilipek.com/2019/02/lambdas-story-part1.html)
>  - [Lambdas: From C++11 to C++20: Part 2](https://www.bfilipek.com/2019/03/lambdas-story-part2.html) + 

### 9. Mixins

Implementar en C++ un ejemplo de _mixin_ que permita mezclar distintos comportamientos en una misma clases, empleando los siguientes mecanismos del lenguaje:

- polimorfismo estático (templates)
- polimorfirmo dinámico

> Referencias:
>  - [DrDobbs Journal](https://www.drdobbs.com/cpp/mixin-based-programming-in-c/184404445)
>  - [Combining Static and Dynamic Polymorphism with C++ Mixin classes](https://michael-afanasiev.github.io/2016/08/03/Combining-Static-and-Dynamic-Polymorphism-with-C++-Template-Mixins.html)

