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