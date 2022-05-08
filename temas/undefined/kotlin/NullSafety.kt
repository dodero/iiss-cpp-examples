/* 
Compilar: kotlinc NullSafety.kt -include-runtime -d NullSafety.jar
Ejecutar: java -jar NullSafety.jar 
*/

class ScreenResolution(val width: Int, val height: Int)

class DisplayFeatures (val size: String, val resolution: ScreenResolution?)

class Mobile (val id: Long, val brand: String, val name: String, val displayFeatures: DisplayFeatures?)

class MobileService{
    //Con el elvis operator. No puede devolver null
    fun getMobileScreenWidth(mobile : Mobile?): Int{
        return mobile?.displayFeatures?.resolution?.width ?: 0
    }
    //Sin elvis operator. Es posible que devuelva null si alguno de los campos encadenados lo es
    fun getMobileScreenHeight(mobile : Mobile?): Int?{
        return mobile?.displayFeatures?.resolution?.height
        //Operador '!!': Posibilidad de lanzar NPE si encontramos null
        //return mobile!!.displayFeatures!!.resolution!!.height
    }
}


fun main() {
    val resolution = ScreenResolution(750,1334) //Infiere Non-null
    var dfeatures = DisplayFeatures("4.7", resolution) // var para poder probar la proxima linea
    //dfeatures = null; //no es posible hacer esto, pues el tipo por defecto es non-null
    val mobile = Mobile(2015001, "Apple", "iPhone 6s", dfeatures)
    val mService = MobileService()

    val width = mService.getMobileScreenWidth(mobile)
    println("Apple iPhone 6s Screen Width = ${width}")
    val mobile2 = Mobile(2015001, "Apple", "iPhone 6s", null) //No hay equivalente a Optional.empty()
    val width2 = mService.getMobileScreenWidth(mobile2)
    println("Apple iPhone 16s Screen Width = ${width2}")

    val height = mService.getMobileScreenHeight(mobile)
    println("Apple iPhone 6s Screen Height = ${height}")

    val height2 = mService.getMobileScreenHeight(mobile2)
    println("Apple iPhone 16s Screen Height = ${height2}")

    // Smart cast: Una conversion que daria lugar a un ClassCastException devuelve un nullable del tipo a convertir
    // (Probar a quitar el '?')
    val m = height as? Mobile
    println("La conversion de Int a Mobile devuelve: ${m}");
}
