# Contratos

Autor : Carlos Loiz Jordán.

# Consejos

Tener extensiones de C++ y csharp si usas vs code para programarlo ya que hace que sea todo mas facil y sencillo.

# Código

using System;
public class ejeploDelegate  {

   // Declara un delegado para un método que recibe un int y devuelve una cadena.
   public delegate string delegate( int aux );


   public class delegateClass  {


      public string mostrarString ( int aux )  {
         if ( aux > 0 ) return( "positivo" );
         if ( aux < 0 ) return( "negativo" );
         return ( "no consta" );
      }

 
      public static string mostarOperacion ( int aux )  {
         if ( aux > 0 ) return( "+" );
         if ( aux < 0 ) return( "-" );
         return ( "" );
      }
   }

   public static void Main()  {

      // Crea un delegate para cada método
      delegateClass dgClass = new delegateClass();
      delegate var = new delegate( dgClass.mostrarString );
      delegate var2 = new delegate( delegateClass.mostarOperacion );

      Console.WriteLine( 5, var( 5 ), var2( 5 ) );
      Console.WriteLine( -3, var( -3 ), var2( -3 ) );
      Console.WriteLine( 0, var( 0 ), var2( 0 ) );
   }
}

# Explicación 

Un delegate es un tipo que representa referencias a métodos con una lista de parámetros determinada y un tipo de valor devuelto. Cuando se crea una instancia de delegate , puede asociar su instancia a cualquier método mediante una signatura compatible y un tipo de valor devuelto. Puede invocar (o llamar) al método a través de la instancia del delegado.

En el ejemplo siguiente se muestra cómo definir un delegado denominado delegate
 . Las instancias de este delegado se crean para un método de instancia y un método estático de la clase anidada delegateCalss . El delegate para el método de instancia requiere una instancia de delegateClass. La delegateClass instancia se guarda    una variable denominada dgClass.
