package codigo;

import java.time.LocalDate; 
import java.util.Comparator;
import java.util.Scanner;

public class Main {	
	public static void main(String[]args) {
		Comparator<BankAccount> comparatorId = new BankAccountComparatorById();
		Comparator<BankAccount> comparatorDate = new BankAcccountComparatorByCreationDate();
		Scanner input = new Scanner(System.in);
		
		// Create main bank fields
		System.out.println("## WRITE MY BANK DATA FIELDS ### ");
		String idBank = "";
		System.out.print("Write an id bank: ");
		idBank = input.nextLine();
		
		// Create LocalDate for main bank
		int year = 0, month = 0, day = 0;
		System.out.print("Write a year for your bank account: ");
		year = input.nextInt();
		System.out.print("Write a month for your bank account: ");
		month = input.nextInt();
		System.out.print("Write a day for your bank account: ");
		day = input.nextInt();
		input.close();		
		
		// Create the main back
		LocalDate bankDate = LocalDate.of(year, month, day);	
		BankAccount bank = new BankAccount(idBank,comparatorId,bankDate);	// Injection
		printBank(bank);		
		
		// Create other banks to compare
		LocalDate bankADate = LocalDate.of(1996, 10, 18);
		LocalDate bankBDate = LocalDate.of(2020, 2, 8);
		BankAccount bankA = new BankAccount("12345",comparatorId,bankADate);
		BankAccount bankB = new BankAccount("1234",comparatorId,bankBDate);
		
		compareIdBanks(bank, bankA);
		compareIdBanks(bank, bankB);		
	}	
	
	private static void printBank(BankAccount bank) {
		System.out.println("");
		System.out.println(" ### BANK DATA ###");
		System.out.println("BANK ID: " + bank.getId());
		System.out.println("BANK DATE: " + bank.getCreationDate().toString());
		System.out.println(" #################");
		System.out.println("");
	}
	
	private static void compareIdBanks(BankAccount bankA, BankAccount bankB ) {
		System.out.println("ID Bank A: " + bankA.getId() + " | ID Bank B: " + bankB.getId());
		if(bankA.compareTo(bankB) == 0) System.out.println("The id's of the banks are equal");
		else {System.out.println("The id's are different");}
		
	}
	


	
	
}
