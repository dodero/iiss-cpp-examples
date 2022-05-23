## Contratos en Scala
Autor: Lucía Caro Barrera

## compilación y ejecución del ejemplo
```
scalac App.scala
scala App.scala
```
## Entorno utilizado 
```	
Visual Studio Code
```
## Dependencias 
```
Metals

```
## Código
```
final case class PreconditionException(private val message: String = "", 
                           private val cause: Throwable = None.orNull)
                      extends Exception(message, cause) 
final case class PostconditionError(private val message: String = "", 
                           private val cause: Throwable = None.orNull)
                      extends Exception(message, cause)                      
object Contracto {

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



```

## Explicación
El diseño por contrato se basa en unas condiciones previas y posteriores a un bloque de codigo y, si estas condiciones no se cumplen, se lanza una excepción.
Scala tiene soporte para implementar contratos mediante algunos métodos que sirven como condiciones previas y posteriores para la ejecución de un contrato. Las condiciones previas son los metodos assume, require y assert y las postcondiciones los ensuring.
 
En este ejemplo hemos creado la clase cuenta bancaria. Para ello hemos creado una clase cuenta con dos funciones principales en las que se implementan los contratos: retirar dinero y depositar. Y a parte, hemos creado tres  metodos: añadir, verSaldo y antiguo.
- El metodo deposit() recibe una cantidad a depositar y, mediante el metodo require como precondicion y ensuring como postcondicion de ésta, comprobamos que la cantidad a depositar sea mayor a 0; también nos aseguramos que el dinero depositado sea el saldo que tenía más la cantidad a depositar. Si esto no se cumpliera, saltaría un error.
El problema de ésto es que para comprobar estado antiguos de algunos atributos no es posible ya que ensuring se encuentra fuera y al final del método. Es por ello que lo hemos implementado de otra forma en el siguiente método.
- En el método retirar lo hemos hecho de dos formas distintas. Por un lado, hemos utilizado dos precondiciones: require, que comprueba que la cantidad a retirar sea menor que el dinero que hay en la cuenta y assume, que se asegura que la cuenta no quede bajo 0.
Sin embargo, a veces el uso de los método que ofrece scala se queda corto y es necesario crear o sobreescribir los contratos de forma que quede ordenado las pre y post condiciones. Para ello, hemos creado el objeto singleton Contrato que, aunque en nuestro realiza básicamente lo mismo, podemos utilizarl sus métodos de forma ordenada en nuestro código.
 
Por lo tanto, scala da un buen soporte para la realización de los contratos.
