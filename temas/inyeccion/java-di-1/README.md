# Inyección de dependencias usando Spring
En **Spring** podemos implementar la inyección de dependencias de varias maneras, en concreto, en nuestro ejemplo usaremos las **Anotaciones**.

## Para empezar a usar Spring
Para hacer uso de **Spring** necesitamos crear un proyecto **Maven** e incluir las dependencias de **SpringBoot**, para ello nos dirijimos al siguiente [Link](https://start.spring.io/) donde le daremos un nombre a nuestro proyecto y haremos click en **Generate**.
Seguidamente, se nos descargará el proyecto con las dependencias ya añadidas y este lo abriremos con **Eclipse**.

## Ejemplo

En primer lugar necesitaremos crear nuestra clase **BankAccount** y las clases donde implementaremos el método **compare** de la interfaz **Comparator**.

### BankAccount.java
```java
package com.example.inyeccion;
import java.util.*;
import java.time.*;
import org.springframework.beans.factory.annotation.Autowired;

public final class BankAccount implements Comparable<BankAccount> {
  private final String id;
  private LocalDate creationDate;
  
  private Comparator comparator;
  
  
  public BankAccount(String number) {
    this.id = number;
    comparator = new BankAccountComparatorById();
  }

  public LocalDate getCreationDate() {
    return creationDate;
  }

  public void setCreationDate(LocalDate date) {
    this.creationDate = date;
  }

  public String getId() {
    return id;
  }

  @Autowired
  public void setComparator(Comparator cmp) {
    comparator = cmp;
  }

  @Override
  public int compareTo(BankAccount other) {
    if (this == other)
      return 0;
    assert this.equals(other) : "compareTo inconsistent with equals.";
    return comparator.compare(this, other);
  }

  @Override
  public boolean equals(Object other) {
    if (this == other)
      return true;
    if (!(other instanceof BankAccount))
      return false;
    BankAccount that = (BankAccount) other;
    return this.id.equals(that.getId());
  }

  @Override
  public String toString() {
    return id.toString();
  }
}
```
### BankAccountComparatorById.java
```java
package com.example.inyeccion;
import java.util.*;

class BankAccountComparatorById implements Comparator<BankAccount> 
{
    public int compare(BankAccount o1, BankAccount o2) 
    {
        return o1.getId().compareTo(o2.getId());
    }
}
```

### BankAccountComparatorByCreationDate.java
```java
package com.example.inyeccion;
import java.util.*;

import org.springframework.context.annotation.Primary;
@Primary
class BankAccountComparatorByCreationDate implements Comparator<BankAccount> 
{
    public int compare(BankAccount o1, BankAccount o2) 
    {
        return o1.getCreationDate().compareTo(o2.getCreationDate());
    }
}
```
Como podemos ver hemos hecho uso de dos etiquetas:
- Etiqueta **@Autowired**: Con esta etiqueta indicamos el método con el que se inyectará la dependencia. En este caso como estamos haciendo la inyección de dependencia mediante **Setter** la colocamos justo encima del método **setComparator**.
- Etiqueta **@Primary**: En este caso como nuestro comparador puede ser de dos tipos, necesitamos indicar cual de las dos implementaciones deseamos tomar como primaria, esto lo hacemos mediante esta etiqueta, la cual colocamos encima de la clase de nuestro comparador de fechas, puesto que ya por defecto en el constructor de la clase **BankAccount** tenemos asignado el comparador por id.

## Ejecución
Para poder probar que todo funciona correctamente, debemos implementar una clase de pruebas. Dicha clase ya se encuentra creada por defecto en nuestro proyecto en **src/test/java** y sólo tendremos que modificarla para incluir las pruebas que queramos realizar.

En concreto, en nuestra clase de pruebas vamos a probar que por defecto se toma el comparador por id y que si creamos dos objectos **BankAccount** con el mismo id el test se pasa correctamente; y por otro lado, crearemos otros dos objetos **BankAccount** con diferentes id, cambiaremos el comparador y este test también será pasado satisfactoriamente.
### InyeccionApplicationTests.java
```java
package com.example.inyeccion;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class InyeccionApplicationTests {

	@Test
	void CompareByIdTest() 
	{
		BankAccount b = new BankAccount("1");
		BankAccount b1 = new BankAccount("1");
		
		assertEquals(b.compareTo(b1), 0);
	}
	
	@Test
	void CompareByDateTest()
	{
		BankAccount b = new BankAccount("1");
		BankAccount b1 = new BankAccount("2");
		
		b.setComparator(new BankAccountComparatorByCreationDate());
		assertEquals(b.compareTo(b1), 0);
	}

}
```