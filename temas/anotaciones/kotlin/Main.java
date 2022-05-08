/*
Compilar:   kotlinc AnotJvm.kt
            javac Main.java
Ejecutar: java Main
*/

public class Main{
    public static void main(String[] args){
        //Ejemplo.sinJvmStatic(); //"Cannot find symbol" porque no esta anotado como @JvmStatic
        Ejemplo.Companion.sinJvmStatic(); //Obligatorio llamarlo con Companion
        Ejemplo.conJvmStatic(); // Como el metodo esta anotado, lo podemos llamar con o sin Companion
        Ejemplo.Companion.conJvmStatic();

        /*Cambiamos el nombre de la funcion 'FunKT' solo para el codigo Java,
        en Kotlin se seguiria llamando con el mismo nombre */
        Funciones.miFun();
        // Funciones.FunKT(); // Esto funciona solo si quitamos la anotacion @JvmName de la funcion FunKT, ya que la renombramos

        Ejemplo.prop1 = 1;
        //Ejemplo.prop2 = 1; // error: prop2 has private access in Ejemplo => debemos utilizar el setter
        Ejemplo.setProp2(1);
        System.out.println("Valor de Prop1: " + Ejemplo.prop1); // Accedemos directamente porque se comporta como un atributo publico
        System.out.println("Valor de Prop2: " + Ejemplo.getProp2()); // Debemos de llamar al getter porque es una propiedad privada
    }
    
}