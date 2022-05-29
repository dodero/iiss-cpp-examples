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