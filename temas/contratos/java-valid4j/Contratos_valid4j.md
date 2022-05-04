# Contratos en Java con Valid4j

## Cómo construir contratos con Valid4j

En primer lugar, debemos crear un proyecto **Maven**. Seguidamente, modificaremos el fichero **pom.xml**, donde añadiremos las dependencias con **valid4j**. Para ello, añadimos lo siguiente:
```xml
 <dependencies>
	<dependency>
	  <groupId>org.valid4j</groupId>
	  <artifactId>valid4j</artifactId>
	  <version>0.5.0</version>
	</dependency>
</dependencies>
```
Una vez hemos añadido las dependencias correspondientes a nuestro proyecto, necesitaremos añadir la siguiente librería a nuestros ficheros **.java**:

```java
import static org.valid4j.Assertive.*;
```
Y haremos uso de las siguientes intrucciones para crear las precondiciones y postcondiciones de nuestras funciones y métodos:
### Precondiciones
 - La responsabilidad de los clientes, es decir, lo que el cliente está obligado a cumplir.
 - Expresa lo que debe cumplirse antes de que se pueda llamar a un método.
 - Expresado como condición(es) sobre el estado del proveedor y/o parámetros de entrada.

Para expresar dichas condidiciones usaremos el siguiente comando, donde además podemos añadir un mensaje de aclaración de dichas condiciones:
```java
require(a >= 0 && b >= 0, "Ambos parametros deben ser positivos o 0");
```
### Postcondiciones
 - La responsabilidad de los proveedores, es decir, lo que el proveedor asegura que se cumplirá.
 - Expresa lo que se cumple después de que se haya ejecutado el método.
 - Expresado como condición(es) sobre el estado del proveedor y/o valores devueltos.

Para expresar dichas condidiciones usaremos el siguiente comando, donde además podemos añadir un mensaje de aclaración de dichas condiciones:
```java 
ensure(sol > 0, "El resultado de la suma debe ser positivo o 0");
```
## Ejemplo
A continuación podemos ver el usso de contratos a través del ejemplo de una calculadora que realiza la suma, resta, multiplicación y división de numeros reales.

### Operaciones.java
```java
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
}
```
## Ejecutar 
Para poder probar la clase **Operaciones.java** realizamos el siguiente método **main** y ejecutamos.
### Main.java
```java
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
```
### Salida
En el caso de que no se cumpla una de las precondicones o postcondiciones aparecerá un mensaje de error indicando cuales de las condiciones está siendo violada. A continuación podemos ver un ejemplo:
```
Seleccione una de las siguientes opciones:
1.Suma
2.Resta
3.Multiplicacion
4.Division
2
Introduzca el primer operando: 
5
Introduzca el segundo operando: 
6
Exception in thread "main" org.valid4j.errors.EnsureViolation: El resultado de la resta debe ser positivo o 0
	at org.valid4j.impl.EnsureViolationPolicy.handleViolation(EnsureViolationPolicy.java:19)
	at org.valid4j.impl.CheckingPolicy.check(CheckingPolicy.java:25)
	at org.valid4j.Assertive.ensure(Assertive.java:189)
	at Operaciones.resta(Operaciones.java:22)
	at Operaciones.main(Operaciones.java:71)
```
