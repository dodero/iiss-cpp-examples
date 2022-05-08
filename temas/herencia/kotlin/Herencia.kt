/* 
Compilar: kotlinc Herencia.kt -include-runtime -d Herencia.jar
Ejecutar: java -jar Herencia.jar 
*/

interface sabeLuchar{
    val fuerza: Int //Propiedad abstracta
    fun luchar(): Unit
}

interface sabeNadar{
    fun nadar(): Unit
}

interface sabeVolar{
    val modo: String //Propiedad abstracta
    fun volar(): Unit
}

open class personajeDeAccion{
    open fun luchar(){
        println("Soy un personaje de acción y voy a luchar.")
    }
}

//Si descomentamos el private, la extension function no funcionaria
class Heroe(/*private*/ val id: Int, override val fuerza: Int = 29, override val modo: String = "alas"): personajeDeAccion(), sabeLuchar, sabeNadar, sabeVolar
{

        override fun volar(){
            println("Heroe ${id} usa ${modo}!")
        }
        override fun nadar(){
            println("Heroe ${id} al agua!")
        }
        override fun luchar(){
            super<personajeDeAccion>.luchar()
            println("Heroe ${id} de fuerza ${fuerza} luchando!")
        }
}

public class Aventura{
    public companion object metodos{
        fun t (x: sabeLuchar){x.luchar()}
        fun u (x: sabeNadar){x.nadar()}
        fun v (x: sabeVolar){x.volar()}
        fun w (x: personajeDeAccion){x.luchar()}
    }
}


//Extension function
fun Heroe.presentacion(){
    println("Hola, soy el heroe ${id}")
}

fun main(){
    val hero = Heroe(1)
    val hero2 = Heroe(2,15,"Cohetes")

    hero.presentacion()
    hero2.presentacion()

    Aventura.t(hero)
    Aventura.u(hero)
    Aventura.v(hero2)
    Aventura.w(hero2)
}