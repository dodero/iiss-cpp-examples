import { BankAccountComparatorById } from './comparadorID'
import { BankAccountComparatorByCreationDate } from './comparadorDate'

function compareById(target: Function) {
    console.log(target, "inject: CompareById")
    target.prototype.comparatorById = new BankAccountComparatorById()
}

function compareByDate(target: Function) {
    console.log(target, "inject: CompareByDate")
    target.prototype.comparatorByCreationDate = new BankAccountComparatorByCreationDate()
}


@compareById
@compareByDate
export class BankAccount {
    private id: string
    private creationDate: Date

    private comparatorById : BankAccountComparatorById;
    private comparatorByCreationDate: BankAccountComparatorByCreationDate;

    constructor(number: string, date : Date) {
        this.id = number
        this.creationDate = date

    }

    public getCreationDate(): Date { return this.creationDate }

    public setCreationDate(value: Date) { this.creationDate = value }

    public getId(): string { return this.id }
    
    public setComparatorById(comparator: BankAccountComparatorById) { this.comparatorById = comparator }

    public setComparatorByDate(comparator: BankAccountComparatorByCreationDate) { this.comparatorByCreationDate = comparator }
    
    // @checkCompId()
    public compareTo(that : BankAccount) : boolean {
        if(this == that) return false
        return this?.comparatorById?.compare(this, that) ?? false
    }

    public compareToByDate(that : BankAccount) : boolean {
        if(this == that) return false
        return this?.comparatorByCreationDate?.compare(this, that) ?? false
    }

    public toString() { return this.id.toString() }
}

class Main {
    public test() {
        
        let fecha: Date = new Date()
        let bank : BankAccount = new BankAccount("1", fecha)
        let bank2 : BankAccount = new BankAccount("2", fecha)

        console.log('Comparar cuentas id:', bank.compareTo(bank2))
        console.log('Comparar cuentas date:', bank.compareToByDate(bank2))
    }
}

let main: Main = new Main()
main.test()


//npm i -D @types/node
// npm install typescript-injections --save
// npm install reflect-metadata