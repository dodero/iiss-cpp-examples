# Herencia Kotlin 

Creado por Rubén Pérez Mercado

## Compilación
```
kotlinc Herencia.kt -include-runtime -d Herencia.jar
```
## Ejecución
```
java -jar Herencia.jar
```
Si no se dispone del compilador de Kotlin, se puede probar el código en el <a href="https://play.kotlinlang.org/">Playground de Kotlin</a>
## Explicación
### Conceptos previos
Antes de entrar en conceptos de herencia, es importante saber cómo funcionan los constructores en Kotlin. Tenemos constructores primarios y secundarios.
- Primarios: Si existe, sólo hay uno. Va después del nombre de la clase.
```
class Persona constructor(Nombre: String) { /*...*/ }
class Persona (Nombre: String) { /*...*/ } //Si no se define visibilidad o anotaciones, la palabra constructor puede omitirse
```
- Secundarios: Si existen, pueden haber varios. Se definen dentro de la propia clase. Siempre delega del constructor primario (incluso si no se ha definido).
```
class Persona (val mascotas: MutableList<Mascota> = mutableListOf()) // Ctor. Primario

class Mascota {  // Ctor. Primario no definido
    constructor(owner: Persona) { // Ctor. Secundario
        owner.mascotas.add(this) // Añade la mascota a la lista de su dueño
    }
}
```

Por otro lado, en Kotlin tenemos propiedades, no campos. La diferencia está en que cuando declaramos propiedades estamos declarando el campo, el getter y el setter (en caso de ser `var`, puesto que una propiedad declarada con `val` sólo tendrá getter). Estos métodos pueden ser modificados, pero eso queda fuera de esta explicación.

Con estos conceptos, tenemos suficiente para entender lo que ocurre en los próximos ejemplos. Destacar que no estamos utilizando los valores pasados al constructor, ya que queremos ver qué sucede en lo relacionado a la herencia.

### Aspectos básicos

Al igual que sucede en Java, por defecto todas las clases heredan de una superclase común. En Java tenemos la clase `Object`, y en Kotlin tenemos la clase `Any`. Esta clase contiene únicamente tres métodos, además del constructor por defecto: equals, hashCode y toString (si bien es cierto que existen más métodos y propiedades que extienden a esta clase. Más adelante veremos cuál es el mecanismo que utiliza).

Una de las diferencias que tiene con respecto a Java es que por defecto las clases son finales, es decir, no se pueden generar subclases de ellas. Para habilitar la herencia en una clase, debemos escribir la palabra `open`. Esto permite que se vea más fácilmente cuando estamos empleando herencia, y con qué clases. Veamos un ejemplo con y sin `open`, con una clase base y otra derivada:
```
class Animal // No permitirá que otras clases hereden de ella
class Perro : Animal() // compilation error: this type is final, so it cannot be inherited from class Perro : Animal()
```

```
open class Animal //Ahora sí que permite la herencia
class Perro : Animal()
```
Como podemos ver, debemos utilizar `:` en la clase derivada para poder heredar de la clase base (declarada con open). Son importantes los paréntesis a la hora de declarar esa herencia, pues de no ponerlos también dará error. Si queremos pasar parámetros al constructor primario, se hará de esta forma:

```
open class Animal(nombre: String)
class Perro(nombre: String, raza: String) : Animal(nombre)
```
Si la clase derivada no tiene constructor primario, se debe emplear la palabra `super` en todos los constructores secundarios para referenciar a la clase base.

```
open class Animal (s: String){
    constructor(age: Int) : this("Animal Desconocido")
}
class Perro : Animal {
    constructor(s: String) : super(s)
    constructor(age: Int) : super(age)
}
```
Insistimos en la idea de que estos códigos no tienen ningún propósito más que enseñar los mecanismos de la herencia. En el ejemplo de las carpetas existen ejemplos más elaborados.

### Overriding

Kotlin permite sobreescribir métodos y propiedades.

```
open class Base{
    ...
    open val i = 0
    open fun metodo1() {/*...*/}
    ...
}

open class Derivada : Base(){
    ...
    override val i = 4
    override fun metodo1() {/*...*/}
    ...
}
```
Como podemos ver, es necesaria la palabra open en los métodos y propiedades a sobreescribir. Destacar que `val` equivalía a un `const` de C++. Podríamos sobreescribirlo por un variable (`var`) y funcionaría. Como curiosidad, el proceso inverso no compilaría, pues implícitamente se declaran getters y setters por cada variable, y al convertir un `var` en `val` estaríamos "perdiendo" el setter.

Si quitásemos la palabra `override` el compilador nos indicaría lo siguiente: `'i' hides member of supertype 'Base' and needs 'override' modifier`.

Podremos hacer referencia a métodos de la superclase usando la palabra `super`
```
open class Rectangulo {
    open fun draw() { println("Pinto mi rectangulo") }
    val borderColor: String get() = "rojo"
}

class RectanguloRelleno : Rectangulo() {
    override fun draw() {
        super.draw()
        println("Relleno el rectangulo")
    }

    val fillColor: String get() = super.borderColor
}
```
### Herencia múltiple
Kotlin no permite herencia múltiple. Es decir, no podemos realizar algo así:
```
open class A
open class B

class C : A(), B()
// Error: Only one class may appear in a supertype list
```

### Clases Abstractas

Al igual que en otros lenguajes, también tenemos clases abstractas. En este caso, no es necesaria la palabra `open`:
```
abstract class Animal {
    abstract fun comer()
}

class Leon : Animal() {
    override fun comer() {
        /* Come carne */
    }
}
```
### Interfaces
También se permiten utilizar interfaces. Permiten opcionalmente implementar los métodos. Se permiten declarar propiedades abstractas, o proporcionar implementaciones de los métodos accesores.
```
interface MiInterfaz {
    val prop: Int // propiedad abstracta
    fun f1()
    fun f2() {
      // opcionalmente puede haber implementación
    }
}

class derivada: miInterfaz {
    override val prop: Int = 5
    override fun f2() {
        // implementación sobreescrita
    }
}
```
### Extensiones
En Kotlin podemos extender clases a las que no tenemos acceso de una forma muy sencilla. Por ejemplo, vamos a añadir el método `swap` a la clase `MutableList<T>`
```
fun <T> MutableList<T>.swap(index1: Int, index2: Int) {
    val tmp = this[index1] // 'this' es el objeto lista
    this[index1] = this[index2]
    this[index2] = tmp
}
```
También podemos añadir propiedades a las clases:
```
val <T> List<T>.lastIndex: Int
    get() = size - 1 
```

### Código
Hemos creado una versión de Kotlin de "Aventura", el ejemplo visto en clase. Hemos utilizado los siguientes conceptos relacionados:

- Interfaces: Anteriormente en Kotlin, existían los `traits`, pero en las últimas versiones han sido eliminados, teniendo que utilizar interfaces. No hemos creado ninguna implementación por defecto en las funciones declaradas e las interfaces, pero sí hemos creado dos variables abstractas en sendas clases `sabeLuchar` y `sabeVolar`, que en Heroe serán instanciadas.

- Función de extensión: Hemos creado una función de extensión para la clase `Heroe` llamada `presentacion`. Sólo funcionará si las propiedades que utilizamos son visibles, podemos probar a descomentar el `private` en la clase `Heroe` para comprobar que no funciona.

- Llamada a una función de la clase base desde el método de una clase derivada: Dentro de la función `Luchar` de Heroe, estamos llamando a la función homónima de la clase `personajeDeAccion` utilizando la palabra `super`.

- "Static" en Kotlin: Aunque no tenga tanta relación con respecto a la herencia, hemos creado un `companion object` en la clase `Aventura`, que es la manera de declarar métodos y propiedades como las estáticas de Java. Para acceder a los elementos en él, podemos ver cómo hemos llamado a las funciones en el `main`. En cuanto a compatibilidad con Java, existe un pequeño problema cuando se llama a un `companion object` desde Java, se puede hacer pero existe una diferencia. Esta diferencia la resolvemos con anotaciones, teniendo un ejemplo en la carpeta Anotaciones / Kotlin / Interoperabilidad.

En la función principal, llamamos a las funciones creadas, algunas de ellas usan las propiedades `fuerza`y `modo`, que eran las propiedades abstractas de las interfaces.