import { BankAccount } from './anotaciones'

export class BankAccountComparatorByCreationDate {

    public compare(o1: BankAccount, o2: BankAccount) {
        return o1.getCreationDate() == o2.getCreationDate()
    }
}