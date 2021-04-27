package codigo;

import java.util.*;


import javax.inject.Inject;
import codigo.Annotations.compareById;
import codigo.Annotations.compareByDate;

import java.time.*;


public class BankAccount implements Comparable<BankAccount>{
	  private final String id;
	  @Inject  LocalDate creationDate;  
	  @Inject  @compareById Comparator<BankAccount> comparatorId;  	 
	  @Inject  @compareByDate Comparator<BankAccount> comparatorDate;  	
	 
	  @Inject
	  public BankAccount(String number, LocalDate date) {
		  this.id = number;		  	
		  this.creationDate = date;
      }
	  
	  public String getId(){return id;}

	  public LocalDate getCreationDate(){return creationDate;}

	  @Inject 
	  public void setCreationDate(LocalDate date){this.creationDate = date;}	 

	  @Inject
	  public void setComparatorId(Comparator<BankAccount> cmp){this.comparatorId = cmp;}
	  
	  @Inject
	  public void setComparatorDate(Comparator<BankAccount> cmp){this.comparatorDate = cmp;}

	  @Override
	  public int compareTo(BankAccount other) {
		  if (this == other)return 0;
		  assert this.equals(other) : "compareTo inconsistent with equals.";
		  return comparatorId.compare(this, other);
     }
	  
	  public int compareByDate(BankAccount other) {		  
		  if (this == other)return 0;
		  assert this.equals(other) : "compareTo inconsistent with equals.";
		  return comparatorDate.compare(this, other);
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
