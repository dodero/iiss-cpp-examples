# Herencia

Autor : Carlos Loiz Jordán.

# Consejos

Tener extensiones de C++ y csharp si usas vs code para programarlo ya que hace que sea todo mas facil y sencillo.

# Código 1

public class Personal {
    private int _id;
    private string _nombre;

    public int id {
        get { return _id;}
        set { id_ = value;}
    }
    
    public string nombre {
        get { return _nombre;}
        set { _nombre = value;}
    }

    //Constructor para la herencia
    public personal( int id,  string nombre){
        _id = id;
        _nombre = nombre;
    }
}

//Clase que hereda de la base
class Profesor : Personal{

    public Profesor ( int id , string nombre):base(id , nombre){

    }
}

//Programa principal para el uso de la clase.
class Program {
    static void Main(string[] args){

        Profesor _profesor = new Profesor(1 , " Carlos");

        Console.WriteLine(_profesor.id , _profesor.nombre);
    }
}

# Explicación 
Para el otro tipo de herencia mirar codigo.
Diferentes tipos de herencias con C#

