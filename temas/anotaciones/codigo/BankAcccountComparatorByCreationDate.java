package codigo;

import java.util.*;

import codigo.Annotations.compareBySomething;

@compareBySomething(type = "date")
public class BankAcccountComparatorByCreationDate implements Comparator<BankAccount> {
	public int compare(BankAccount o1, BankAccount o2) {
        return o1.getCreationDate().compareTo(o2.getCreationDate());
    }

}
