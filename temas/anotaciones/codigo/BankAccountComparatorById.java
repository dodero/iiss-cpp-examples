package codigo;

import java.util.*;

import codigo.Annotations.compareBySomething;

@compareBySomething
public class BankAccountComparatorById implements Comparator<BankAccount> {
	 public int compare(BankAccount o1, BankAccount o2) {
	        return o1.getId().compareTo(o2.getId());
	    }

}
