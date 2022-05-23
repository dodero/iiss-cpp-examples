final case class PreconditionException(private val message: String = "", 
                           private val cause: Throwable = None.orNull)
                      extends Exception(message, cause) 
final case class PostconditionError(private val message: String = "", 
                           private val cause: Throwable = None.orNull)
                      extends Exception(message, cause)                      
object Contracto {
    /*def apply[T](body: T): T = {
        body
    }*/

    def requires(condition: Boolean): Contracto.type = {
        if (!condition)
            throw new PreconditionException("ERROR: require")
        Contracto
    }

    def ensures(condition: Boolean): Contracto.type = {
        if(!condition)
            throw new PostconditionError("ERROR: ensure")
        Contracto
    }
}
/*
object requires{
    def requires(condition: Boolean): Contract.type = {
        print("jeje")
        if (!condition)
            throw new PreconditionException("ERROR: require")
        Contract
    }
}

object ensures{
    def requires(condition: Boolean): Contract.type = {
        print("jeje")
        if (!condition)
            throw new PostconditionError("ERROR: require")
        Contract
    }
}*/


class Account(var balance: Int, min_balance: Int = 0, propietario: String = "mio") {
  import Contracto._
  var old_balance: Int = balance

  require(min_balance >= 0 && balance >= min_balance)
  def add(sum: Int): Unit = {
    old(balance)
    balance = balance + sum
  }
  def old(value: Int ): Unit = {
    old_balance = value
  }

  def deposit(sum: Int): Int = {
    require(sum > 0, "La cantidad a depositar debe ser mayor a 0")
    println(" Deposite la suma en la cuenta:  (" + sum +")")
    add(sum) 
    balance
  } ensuring(balance => balance == old_balance + sum, "ERROR: al depositar el dinero")
  
  def withdraw(sum: Int): Unit = {
    require(sum > 0 , "No hay suficiente dinero en la cuenta")
    println("Retirar suma de la cuenta:  (" + sum + ")")
    ensures(balance == old_balance - sum)
    //assume(balance - sum >= min_balance, "error: La cuenta no puede quedar en números rojos (menor a 0)")
    add(-sum)
  }

  def seeBalance(): Unit ={
    println("Saldo actual:   "  + balance)
  }
}


object Principal{
  def main(args: Array[String]): Unit = {

    /*All is correct*/
    val b = new Account(1000,0,"hola")
    print("(1)")
    b.seeBalance()
    b.withdraw(200)
    println("Saldo actual:  " + b.deposit(50))

    /*Error precondicion: saldo insuficiente para retirar dinero*/
    print("(2)")
    val b2 = new Account(0)
    b2.seeBalance()

    /*Error postcondicion: al retirar la cuenta se queda bajo 0*/
    print("(3)")
    val b3 = new Account(50)
    b3.seeBalance()
    b3.withdraw(52)
  }
} 
