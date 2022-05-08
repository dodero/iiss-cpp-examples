# Anotaciones JVM
Creado por Rubén Pérez Mercado

## Compilación
```
kotlinc AnotJvm.kt
javac Main.java
```
## Ejecución
```
java Main
```
## Explicación
### Anotaciones creadas por el desarrollador:
En Kotlin, las anotaciones que podemos crear sólo sirven para adjuntar metadatos al código. En Kotlin, declaramos anotaciones usando la palabra `annotation` delante de una clase.
```
annotation class Anot
```
Las anotaciones pueden tener meta-anotaciones:
```
@Target(AnnotationTarget.CLASS, AnnotationTarget.FUNCTION,
        AnnotationTarget.TYPE_PARAMETER, AnnotationTarget.VALUE_PARAMETER,
        AnnotationTarget.EXPRESSION)
@Retention(AnnotationRetention.SOURCE)
@MustBeDocumented
annotation class Anot

```
No obstante, vamos a jugar con las anotaciones que ya vienen en el lenguaje, con las que podremos hacer más cosas.
### Anotaciones de kotlin.jvm

Como ya hemos dicho en otros bloques, Kotlin es un lenguaje 100% interoperable con Java. Eso no quita que existan ciertos aspectos en los que Kotlin y Java difieran, y para los que se necesite indicar al compilador ciertas cosas. Por ello, existen las anotaciones del <a href="https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.jvm/">paquete kotlin.jvm</a>

### Código

En nuestro código, hemos creado un ejemplo sencillo con tres de las anotaciones de este paquete:

- JvmName: Es capaz de modificar el nombre de varios elementos del código. En nuestro caso, lo hemos usado para cambiar el nombre de la clase generada con las declaraciones de propiedades y métodos que no están englobadas en ninguna clase (`funKT`). Por defecto, se crearía el archivo `.class` con nombre `AnotJvmKt.class` (nombre del archivo seguido de 'Kt'), pero con esta anotación el archivo generado será `Funciones.class`. Además, hemos renombrado el propio nombre de la función funKT. Este renombramiento sólo afectará a las llamadas que se hagas desde código Java: En Kotlin, se seguirá llamando a la función como `FunKT`, mientras que en Java sólo funcionará cuando la llamemos como `miFun`.

- JvmField: En Kotlin, no existen los atributos sueltos. Cuando declaramos una propiedad, por dentro se está generando el atributo (privado siempre), un getter y un setter. El getter tendrá la visibilidad dada a la propiedad, y el setter sólo existirá en caso de ser una propiedad declarada con `var`, no con `val`. Esta es la razón por la que en el resto de bloques sólo se declaran las propiedades, y las clases quedan con tan poco código. 
Con esta anotación, podemos hacer que el compilador interprete la propiedad como un atributo igual que en Java. En nuestro ejemplo, hemos creado ese atributo (`prop1`), que será público y estático (por estar dentro del `companion object`).

- JvmStatic: Gracias a esta anotación, podemos referirnos los métodos y propiedades declaradas dentro de un `companion object` desde código Java igual que los usaríamos si pertenecieran a una clase de Java y fuesen estáticos. Si no se usa la anotación, tendríamos que escribir `Companion` (o el nombre asignado al `companion object`) entre el nombre de la clase y el método o propiedad (por ejemplo, `Ejemplo.Companion.JvmSinStatic()`).


