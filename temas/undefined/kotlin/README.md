# Null Safety ('Undefined')

Creado por Rubén Pérez Mercado

## Compilación
```
kotlinc NullSafety.kt -include-runtime -d NullSafety.jar
```
## Ejecución
```
java -jar NullSafety.jar
```
Si no se dispone del compilador de Kotlin, se puede probar el código en el <a href="https://play.kotlinlang.org/">Playground de Kotlin</a>
## Explicación

Uno de los objetivos de Kotlin, al igual que el de muchos de los nuevos lenguajes, es eliminar los problemas relacionados con `null`. Lenguajes más antiguos como Java o C++ han incorporado mecanismos para proporcionar lo que de forma nativa ya proporcionan lenguajes como Kotlin.

En Java, es común encontrarnos con excepciones de tipo `NullPointerException` (`NPE`). En Kotlin, esto se da en circunstancias muy concretas:
- Se lanza explícitamente una excepción de este tipo con `throw`.
- Se usa el operador `!!` descrito más adelante.
- Si existe inconsistencia en los datos (en constructores).
- Interoperabilidad con Java (como veremos ahora, Kotlin aborda de una manera especial los `null`).

### Nullable vs non-null

Kotlin realiza una distinción entre referencias que permiten el valor nulo (nullable) y referencias que no lo permiten (non-null). Veamos el siguiente ejemplo:
```
fun main(){
    var a = "Hola Mundo"
    a = null
    // Error: Null can not be a value of a non-null type String
}
```
En la línea 2 el compilador infiere la variable `a` es de tipo `String`, que es de tipo non-null. Al igualar la variable a `null`, da el error del comentario. Lo mismo pasaría si explícitamente declaramos `a` como `String`.

Para declarar una variable de tipo nullable, utilizamos el carácter `?` detrás del tipo de la variable:
```
fun main(){
    var b: String? = "abc" //Ahora sí puede valer null
    b = null // OK
    print(b) //imprime 'null'
}
```
En el caso de acceder a métodos, no tendríamos problemas con tipos non-null, puesto que nunca serán nulos. Con tipos nullable, en cambio, el compilador nos exige que utilicemos el operador `?.`, independientemente de si la variable vale `null` o no.
```
val l = a.length //OK
val l2 = b.length // Compilation Error: variable 'b' can be null
val l3 = b?.length // l3 = 'null'
```
En el ejemplo anterior, `l2` dará error por lo que hemos descrito anteriormente, `l` será de tipo `Int`, y `l3` será de tipo `Int?`. Esta última variable valdrá `null` en caso de serlo `b` también, o el resultado de aplicar el método (en este caso, `length`). Como curiosidad, si aplicamos el operador `?.` a una variable de tipo non-null, nos saltará un Warning, pero compilará. Como es de esperar, se pueden encadenar varios operadores `?.` con llamadas a métodos o acceso a propiedades, y si en algún punto se devuelve valor nulo, el resultado que devolverá será `null`
```
persona1?.nombre?.toUpperCase()
```
### Contenedores con valores nulos
Si tenemos un contenedor con valores nulos, y queremos iterar sobre él sin tener en cuenta los valores nulos, podemos utilizar el operador `?.` junto con `let`.
```
val listWithNulls: List<String?> = listOf("Kotlin", null, "language")
for (item in listWithNulls) {
    item?.let { println(it) } 
    /* Ignora los null e imprime:
    Kotlin
    language
    */
}
```
Si nos interesase eliminar esos valores nulos previamente, tenemos el método `filterNotNull()`, y así podríamos convertir el contenedor de tipo nullable a otro de tipo non-null:
```
val listWithNulls: List<String?> = listOf("Kotlin", null, "language")
List<String> listWithoutNulls = listWithNulls.filterNotNull()
```
### Operador Elvis
En Kotlin, no existe el operador ternario `condition ? case_true : case_false`. No obstante, tenemos un operador llamado Elvis operator (`?:`), mediante el cual podemos establecer un valor predeterminado a una variable si es nula, es decir, sería como un operador ternario pero con la condición `b != null`. Veamos un ejemplo:

Imaginemos que tenemos algo parecido a esto:
```
val l: Int = if (b != null) b.length else -1
```
Comprobamos primero que el valor de la variable `b` para asignarle un valor (en este caso, la longitud de la cadena), y si es nula la variable `b` asignamos a `l` el valor `-1`.
Con el Elvis operator, podríamos hacerlo de la siguiente manera:
```
val l = b?.length ?: -1
```
Recordamos que al ser `b` de tipo nullable, es necesario el uso del operador `?.` cuando usamos sus métodos. De esta manera, podemos acortar la expresión con un `if-else` de arriba, y convertirla en algo más corto.
Destacar que podemos utilizar palabras como return o throw en la parte de la derecha del Elvis operator (la parte del `else`), por si tenemos que controlar que el valor esperado no sea `null`.
### Operador !!
Como hemos dicho antes, existe un operador mediante el cual podemos lanzar excepción de tipo `NPE`. Lo que hace este operador es llamar al método como si la variable fuese de tipo non-null, y si el valor de esa variable era `null`, lanza esa excepción.
```
val l = b!!.length // Si b == null, lanza NPE
```
### Casts Seguros
En algunos casos, podemos realizar un cast y que lance un `ClassCastException` si el objeto no es del mismo tipo que el de destino. Para evitar esto existe el operador `as?`, que devuelve null en caso de no ser posible la conversión.
```
val contador: Int? = a as? Int //Si 'a' no puede convertirse en Int, contador = null
```

### Código

Para este bloque hemos implementado el ejemplo `MobileTester`.
Destacamos, antes de hablar sobre los aspectos del bloque, la particularidad de Kotlin con las propiedades, que se componen de getter, setter y el propio atributo, lo que hace que las clases auxiliares queden muy escuetas. En este <a href="https://www.geeksforgeeks.org/kotlin-setters-and-getters/">enlace</a> se explica con detalle esta característica.

En el ejemplo hemos hecho uso de:

- Nullables y non-nulls: Tenemos propiedades de ambos tipos en el código. En el `main` tenemos una instrucción comentada para ver el fallo de compilación en caso de asignar un `null` a una propiedad non-null.
- Concatenación del operador `?.` y del Elvis operator `?:` dentro de la función `getMobileScreenWidth`, lo que nos permite no lanzar un NPE y devolver siempre algo distinto a `null`.
- Concatenación del operador `?.` sin usar el Elvis operator `?:` dentro de la función `getMobileScreenHeight`, lo que nos permite no lanzar un `NPE` pero podemos devolver `null` en caso de que alguno de los operadores `?.` devuelva `null`. En el ejemplo, hemos creado un `Mobile` con `DispalyFeatures` nulo, pero podemos ver que no se lanzará en ningún momento un `NPE`, aunque imprimimos `null` en la ejecución.
- Operador `!!` en `getMobileScreenHeight`, con el que podemos lanzar un `NPE` en caso de valer `null` la propiedad en ese punto. Para probar esto, se necesita comentar el return anterior y descomentar el que viene debajo del comentario en la función anteriormente dicha.