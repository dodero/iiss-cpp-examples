import java.util.Scanner;

public class excepcionesUnchecked {

	excepcionesUnchecked(){}
	
	public static void excepcionVector(){
		int[] v = new int[10];
		System.out.print(v[130]);
	}

	public static void variasExcepciones() {
		Scanner s = new Scanner(System.in);
		int x;
		System.out.println("Introduce un dividendo erroneo, es decir LO QUE SEA menos un numero distinto de 0");
		x = s.nextInt();
		int y = 3/x;
	}

	public static void excepcionPropiaUnchecked(String name){
		if(name != "UCA") throw new nombreDeNuestraUniversidadErroneo("Esto no es la "+name+", ESTO ES LA UCA!!!");
	}
}

class nombreDeNuestraUniversidadErroneo extends RuntimeException{
	public nombreDeNuestraUniversidadErroneo() {}
	public nombreDeNuestraUniversidadErroneo(String mensajeDeError) {super(mensajeDeError);}
}