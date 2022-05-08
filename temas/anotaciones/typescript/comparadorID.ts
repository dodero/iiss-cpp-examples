import { BankAccount } from './anotaciones'

export class BankAccountComparatorById {

    public compare(o1: BankAccount, o2: BankAccount) {
        return o1.getId() == o2.getId()
    }
}

