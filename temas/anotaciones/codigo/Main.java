package codigo;

import java.lang.reflect.Field;
import java.time.LocalDate; 
import java.util.Comparator;
import java.util.Scanner;

import codigo.Annotations.compareById;
import codigo.Annotations.compareByDate;


public class Main {	
	public static void main(String[]args) {
		Comparator<BankAccount> comparatorId = new BankAccountComparatorById();
		Comparator<BankAccount> comparatorDate = new BankAcccountComparatorByCreationDate();
		Scanner input = new Scanner(System.in);		
		
		// Creating the main bank
		BankAccount bank = creatingBankThroughInput();
		bank.setComparatorId(comparatorId);
		bank.setComparatorDate(comparatorDate);
		printBank(bank);		
		
		// Create other banks to compare
		LocalDate bankADate = LocalDate.of(1996, 10, 18);
		LocalDate bankBDate = LocalDate.of(2020, 2, 8);
		BankAccount bankA = new BankAccount("1234",bankADate);
		bankA.setComparatorId(comparatorId);
		bankA.setComparatorDate(comparatorDate);
		BankAccount bankB = new BankAccount("12345",bankBDate);
		bankB.setComparatorId(comparatorId);
		bankB.setComparatorDate(comparatorDate);		
		
		// Compare the banks
		compareBanks(bank, bankA);		
		compareBanks(bank, bankB);		
	}
	
	private static BankAccount creatingBankThroughInput() {
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
		input.nextLine();		
		input.close();	
			
		// Create the object main banks
		LocalDate bankDate = LocalDate.of(year, month, day);	
		BankAccount bank = new BankAccount(idBank,bankDate);
		
		return bank;
		
	}		
	
	private static void printBank(BankAccount bank) {
		System.out.println("");
		System.out.println(" ### BANK DATA ###");
		System.out.println("BANK ID: " + bank.getId());
		System.out.println("BANK DATE: " + bank.getCreationDate().toString());
		System.out.println(" #################");
		System.out.println("");
	}
	
	private static void compareBanks(BankAccount bankA, BankAccount bankB ) {
		
		// Check if this class have this annotations
		boolean haveAnnotations = checkAnnotations();
		
		if(haveAnnotations) {
			System.out.println("ID Bank A: " + bankA.getId() + " | ID Bank B: " + bankB.getId());	
			System.out.println("Date Bank A: " + bankA.getCreationDate() + " | ID Bank B: " + bankB.getCreationDate());
			
			// Compare by Id's
			if(bankA.compareTo(bankB) == 0) System.out.println("The id's of the banks are equal");
			else {System.out.println("The id's are different");}
			
			// Compare by Dates
			if(bankA.compareByDate(bankB) == 0) System.out.println("The dates of the banks are equal");
			else {System.out.println("The dates are different");}
			System.out.println("");
		}
		else {
			System.out.println("These class dont have this annotations!");
		}	
		
	}
	
	private static boolean checkAnnotations() {		
		boolean isRight = false;
		Class<BankAccount> obj = BankAccount.class;	
		if(obj.getDeclaredFields().length == 0) {System.out.println("This class doesnt have fields");}
		for(Field field : obj.getDeclaredFields()) {		
			  if(!field.isAnnotationPresent(compareById.class)) isRight = true;
			  if(!field.isAnnotationPresent(compareByDate.class))isRight = true;		  
		  } 

		return isRight;
	}
	


	
	
}
