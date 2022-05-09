package com.example.inyeccion;
import java.util.*;

class BankAccountComparatorById implements Comparator<BankAccount> 
{
    public int compare(BankAccount o1, BankAccount o2) 
    {
        return o1.getId().compareTo(o2.getId());
    }
}