import java.io.EOFException;
import java.io.IOException;
import java.util.InputMismatchException;

public class excepciones {

	public static void main(String[] args) {
		System.out.println("*******************************************************");
		System.out.println("*****Excepciones que heredan de Throwable(CHECKED)*****");
		System.out.println("*******************************************************");
		
		System.out.println("Excepcion checked con codigo que la provoca");
		usoExcepcionChecked1();
		
		System.out.println();
		
		System.out.println("Excepcion checked creada y lanzada manualmente con mensaje personalizado");
		usoExcepcionChecked2();
		
		System.out.println();
		
		System.out.println("Excepcion checked creada por mi, con mensaje personalizado e imprimiendo la Stack Trace");
		usoExcepcionChecked3();
		
		System.out.println();
		
		System.out.println("****************************************************************");
		System.out.println("*****Excepciones que heredan de RuntimeException(UNCHECKED)*****");	
		System.out.println("****************************************************************");
		
		System.out.println("Excepcion unchecked con codigo que la provoca");
		usoExcepcionUnchecked1();
		
		System.out.println();
		
		System.out.println("Varias excepciones unchecked que dicen el tipo error que ha saltado y con finally");
		usoExcepcionUnchecked2();
		
		System.out.println();
		
		System.out.println("Excepcion unchecked creada por mi con mensaje personalizado y que no ha sido capturada");
		usoExcepcionUnchecked3();
	}	
	
	public static void usoExcepcionChecked1() {
		try{excepcionesChecked.excepcionIO();}
		catch(IOException e) {System.out.println("Capturada excepcion IOException");}
	}
	public static void usoExcepcionChecked2() {
		try {excepcionesChecked.excepcionEOF();}
		catch(EOFException e) {System.out.println(e.getMessage());}
	}
	public static void usoExcepcionChecked3() {
		try {excepcionesChecked.excepcionPropiaChecked("PCTR");}
		catch(nombreDeNuestraAsignaturaErroneo e) {e.printStackTrace();}	
	}
	
	public static void usoExcepcionUnchecked1() {
		try {excepcionesUnchecked.excepcionVector();}
		catch(ArrayIndexOutOfBoundsException e) {System.out.println("Capturada excepcion ArrayIndexOutOfBoundsException");}
	}
	public static void usoExcepcionUnchecked2() {
		try {excepcionesUnchecked.variasExcepciones();}
		catch(ArithmeticException e) {System.out.println("Como has introducido un 0 ha salido un error del tipo "+e.getClass().getName());}
		catch(InputMismatchException e) {System.out.println("Como no has introducido un numero ha salido un error del tipo "+e.getClass().getName());}
		finally {System.out.println("Hola soy un finally");}
	}
	public static void usoExcepcionUnchecked3() {
		excepcionesUnchecked.excepcionPropiaUnchecked("UNED");
	}
}
