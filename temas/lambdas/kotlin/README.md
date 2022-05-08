# Lambdas
Creado por Rubén Pérez Mercado

## Compilación
```
kotlinc Main.kt -include-runtime -d Main.jar
```
## Ejecución
```
java -jar Main.jar
```

Si no se dispone del compilador de Kotlin, se puede probar el código en el <a href="https://play.kotlinlang.org/">Playground de Kotlin</a>

## Explicación

En Kotlin, las funciones lambda tienen la siguiente sintaxis:
```
val sum: (Int, Int) -> Int = { x: Int, y: Int -> x + y }
```
- La expresión lambda estará delimitada por las llaves.
- Los parámetros de la expresión van dentro de ella, y como veremos más adelante existen ciertas maneras de escribirlos, aunque la que tenemos en este ejemplo sería la forma 'completa'.
- Tenemos el operador `->`, detrás del cual viene el cuerpo de la función.
- El valor de retorno será la última (y a poder ser, única) expresión dentro del cuerpo de la función.

La función anterior sería exactamente igual que la siguiente:
```
val sum = { x: Int, y: Int -> x + y }
```
En este caso, hemos quitado todos los elementos opcionales, y dejamos que el compilador los infiera a partir de los parámetros de la expresión y del valor de retorno.

También podemos hacer que infiera los parámetros dentro de la función a partir de los tipos a los que se asignan (en este caso, `Int, Int`):
```
val sum: (Int, Int) -> Int = { x, y -> x + y }
```
En cualquier caso, no pueden hacerse las dos omisiones a la vez, pues el compilador no podrá inferir los tipos:
```
val sum:  = { x, y -> x + y } // Compilation Error
```
Si nuestra función lambda consiste en llamar a otra función, podemos optar por hacer lo siguiente: 
```
val upperCase: (String) -> String = String::uppercase
```
Como vemos, aquí no usamos las llaves.
### Nombre implícito del parámetro
En las funciones lambda con un solo parámetro de entrada, podemos su nombre y utilizar la palabra `it`:
```
val upperCase: (String) -> String = { it.uppercase() }
```
Esto es especialmente interesante cuando tenemos una colección cualquiera de elementos, y tenemos que iterar sobre ella:
```
val ints: MutableList<Int> = mutableListOf(1, 2, 3, -1, 0, 4)
val filtrado = ints.filter { it > 0 }
print(filtrado) // Imprime [1, 2, 3, 4]
```
Podemos además hacer cosas como esta:
```
strings.filter { it.length == 5 }.sortedBy { it }.map { it.uppercase() }
```
En las que estaríamos utilizando el parámetro implícito en varias ocasiones a la vez.

### Valor de retorno específico
Como hemos dicho antes, en general dejamos que el valor de retorno sea la última expresión en el cuerpo de la función. No obstante, podemos indicar qué queremos devolver exactamente:
```
// Ambos fragmentos son equivalentes
ints.filter {
    val shouldFilter = it > 0
    shouldFilter
}

ints.filter {
    val shouldFilter = it > 0
    return@filter shouldFilter
}
```

### Funciones anónimas
En Kotlin, las funciones anónimas serían exactamente igual que una función normal, pero sin indicar el nombre de ella:
```
fun(x: Int, y: Int): Int = x + y
// o bien
fun(x: Int, y: Int): Int {
    return x + y
}
```
Donde usemos este tipo de funciones, debemos protegerlas con paréntesis.
```
ints.filter(fun(item) = item > 0)
```

### Scope Functions

Las scope functions son unos tipos de función que hacen uso de una expresión lambda. Existen 5 tipos:
- `with`
- `let`
- `run`
- `apply`
- `also`

Aunque sean bastante parecidas, existen algunas diferencias entre ellas, y cada una se utiliza en un contexto distinto.

### Código

En el código, hemos creado un ejemplo para cada uno de los temas anteriormente tratados, en lo que exponemos lo que hemos explicado anteriormente. En el caso de las scope functions, hemos utilizado `with`, que recibe como parámetro el objeto y al que hace referencia usando la palabra `this`, y `let`, que tiene una gran utilidad en caso de disponer de una collección de Nullables, ya que ignoraría a los elementos de la colección que sean nulos (eso sí, la llamada sería `?.let`, ya que si no se pone el interrogante se ejecutaría sin esa peculiaridad).

