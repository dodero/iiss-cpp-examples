/* 
Compilar: kotlinc Lambdas.kt -include-runtime -d Lambdas.jar
Ejecutar: java -jar Lambdas.jar 
*/

fun main(){

    //Lambda expressions

    val upperCase1: (String) -> String = { str: String -> str.uppercase() }

    val upperCase2: (String) -> String = { str -> str.uppercase() }

    val upperCase3 = { str: String -> str.uppercase() }

    // val upperCase4 = { str -> str.uppercase() }

    val upperCase5: (String) -> String = { it.uppercase() }

    val upperCase6: (String) -> String = String::uppercase

    println(upperCase1("lam"))
    println(upperCase2("bda"))
    println(upperCase3("fun"))
    println(upperCase5("cti"))
    println(upperCase6("ons"))

    println("")

    val languages = listOf("kotlin", "java", "scala", "c++", "c#")

    //Closure
    var sum = 0
    languages.forEach {
        sum += it.length
    }
    println(sum)
    println("")

    // Implicit parameter
    languages
        .filter { it.startsWith("k")}
        .map { it.uppercase()}
        .forEach {println(it)}

    //Scope Functions

    val nombres: MutableList<String?> = mutableListOf("Pepe", "Ana", null, "Juan")
    println(nombres)
    val firstAndLast = with(nombres) {
        "El primer nombre de la lista es ${this?.first()}," +
        " el ultimo es ${this?.last()}"
    }
    println(firstAndLast)


    for (name in nombres){
        name?.let{ //Ignora nulls
            print(it)
        }

        name.let{ //No ignora nulls
            println("\t| ${it}")
        }
    }


}