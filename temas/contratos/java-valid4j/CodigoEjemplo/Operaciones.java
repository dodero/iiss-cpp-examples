import static org.valid4j.Assertive.*;
import java.util.Scanner;

public class Operaciones 
{
	private double p1,p2;
	
	public static double suma(double a, double b)
	{
		require(a >= 0 && b >= 0, "Ambos parametros deben ser positivos o 0");
		double sol = 0;
		sol = a + b;
		ensure(sol > 0, "El resultado de la suma debe ser positivo o 0");
		return sol;
	}
	
	public static double resta(double a, double b)
	{
		require(a >= 0 && b >= 0, "Ambos parametros deben ser positivos o 0");
		double sol = 0;
		sol = a - b;
		ensure(sol >= 0, "El resultado de la resta debe ser positivo o 0");
		return sol;
	}
	
	public static double multiplicacion(double a, double b)
	{
		require(a >= 0 && b >= 0, "Ambos parametros deben ser positivos o 0");
		double sol = 0;
		sol = a * b;
		ensure(sol >= 0, "El resultado de la multiplicacion debe ser positivo o 0");
		return sol;
	}
	
	public static double division(double a, double b)
	{
		require(a >= 0 && b > 0,"El numerador debe ser positivo o 0 y el numerador debe ser positivo");
		double sol = 0;
		sol = a / b;
		ensure(sol >= 0, "El resultado de la division debe ser positivo o 0");
		return sol;
	}
	public static void main(String[] args) 
	{
		System.out.println("Seleccione una de las siguientes opciones:");
		System.out.println("1.Suma");
		System.out.println("2.Resta");
		System.out.println("3.Multiplicacion");
		System.out.println("4.Division");
		Scanner lectura = new Scanner (System.in);
		int op = lectura.nextInt();
		double a,b,sol;
		
		switch(op)
		{
		case 1:
			System.out.println("Introduzca el primer sumando: ");
			a = lectura.nextLong();
			System.out.println("Introduzca el segundo sumando: ");
			b = lectura.nextLong();
			sol = suma(a,b);
			System.out.println("Resultado:" + sol);
			break;
			
		case 2:
			System.out.println("Introduzca el primer operando: ");
			a = lectura.nextLong();
			System.out.println("Introduzca el segundo operando: ");
			b = lectura.nextLong();
			sol = resta(a,b);
			System.out.println("Resultado:" + sol);
			break;
			
		case 3:
			System.out.println("Introduzca el primer operando: ");
			a = lectura.nextLong();
			System.out.println("Introduzca el segundo operando: ");
			b = lectura.nextLong();
			sol = multiplicacion(a,b);
			System.out.println("Resultado:" + sol);
			break;
			
		case 4:
			System.out.println("Introduzca el numerador: ");
			a = lectura.nextLong();
			System.out.println("Introduzca el denominador: ");
			b = lectura.nextLong();
			sol = division(a,b);
			System.out.println("Resultado:" + sol);
			break;
		}

	}
	
}
