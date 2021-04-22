package codigo;

import java.util.*;

import javax.inject.Inject;
import java.time.*;


public class BankAccount implements Comparable<BankAccount>{
	  private final String id;
	  @Inject  LocalDate creationDate;  
	  @Inject private Comparator<BankAccount> comparator;  	  
	 
	  @Inject
	  public BankAccount(String number, Comparator<BankAccount> comp, LocalDate date) {
		  this.id = number;
		  this.comparator = comp; 	
		  this.creationDate = date;
      }

	  public LocalDate getCreationDate(){return creationDate;}

	  @Inject 
	  public void setCreationDate(LocalDate date){this.creationDate = date;}

	  public String getId(){return id;}

	  @Inject
	  public void setComparator(Comparator<BankAccount> cmp){this.comparator = cmp;}

	  @Override
	  public int compareTo(BankAccount other) {
		  if (this == other)return 0;
		  assert this.equals(other) : "compareTo inconsistent with equals.";
		  return comparator.compare(this, other);
     }

	  @Override
	  public boolean equals(Object other) {
		  if (this == other)return true;
		  if (!(other instanceof BankAccount))return false;
		  BankAccount that = (BankAccount) other;
		  return this.id.equals(that.getId());
      }

	  @Override
	  public String toString(){return id.toString();}

}
