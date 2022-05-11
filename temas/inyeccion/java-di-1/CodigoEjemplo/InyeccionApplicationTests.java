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
