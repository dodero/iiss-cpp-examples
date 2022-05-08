/* Al compilar, todas las propiedades y metodos que no pertenezcan a clases los une en una clase con el mismo nombre del fichero,
   acabado en Kt. p.e. AnotJvmKt.class.
   Con la anotacion JvmName con target file, cambiamos ese nombre (en este caso, se genera un Funciones.class).
*/
@file:JvmName(name = "Funciones") // Si comentamos esta linea, se genera AnotJvmKt.class en vez de Funciones.class

// JvmName puede utilizarse para renombrar funciones (en Kotlin seguiria teniendo el mismo nombre)
@JvmName(name = "miFun")
fun FunKT(){println("Llamada a FunKT")}


class Ejemplo(){
    companion object{ // Todo lo que va dentro de un companion object, seria static traducido a Java

        /*Sin la anotacion JvmStatic en una propiedad o metodo, tendriamos que llamarla desde Java
          con className.Companion.method()
          
          La anotacion JvmField se utiliza para declarar atributos sin getter ni setter, cosa que Kotlin hace de manera automatica.
        */
        @JvmField // Equivalente en Java a public static prop1
        var prop1 = 0
        
        @JvmStatic // Equivalente en Java a private static prop2, con getter y setter. Se puede llamar sin escribir Companion
        var prop2 = 0

        // Debemos escribir Ejemplo.Companion.sinJvmStatic() para llamarla, ya que no usa la anotacion JvmStatic
        fun sinJvmStatic() {println("sin @JvmStatic")}

        @JvmStatic // No hara falta escribir Companion, solo Ejemplo.conJvmStatic()
        fun conJvmStatic() {println("con @JvmStatic")}
    }   
}