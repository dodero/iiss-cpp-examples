# Herencia en C# 

## Cómo implementar la herencia
Para explicar como realizar la herencia, vamos a partir del ejemplo **Aventura**. 
En primer lugar, necesitamos la clase base **Personaje de Acción**:

### PersonajeDeAccion.cs
```csharp
using System;
namespace Aventura
{
    public class PersonajeDeAccion 
    {
        public void luchar() { Console.WriteLine("SABE LUCHAR PERSONAJE ACCION"); }
    }
}

```
Seguidamente, crearemos las interfaces:
### SabeNadar.cs
```csharp
using System;
namespace Aventura
{
    public interface SabeNadar
    {
        public void nadar();
    }
}

```
### SabeVolar.cs
```csharp
using System;
namespace Aventura
{
    public interface SabeVolar
    {
        public void volar();
    }
}
```
### SabeLuchar.cs
```csharp
using System;
namespace Aventura
{
    public interface SabeLuchar
    {
        public void luchar();
    }
}
```
A continuación, creamos la clase **Heroe** subclase de la clase **Personaje de Accion** y además, implementa los métodos de las interfaces anteriormente creadas:
### Heroe.cs
```csharp
using System;
namespace Aventura
{
    public class Heroe : PersonajeDeAccion, SabeLuchar, SabeNadar,SabeVolar
    { 
        public void volar() { Console.WriteLine("SABE VOLAR HEROE"); }

        public void nadar() { Console.WriteLine("SABE NADAR HEROE"); }
    }
}
```
Finalmente, crearemos la clase **Aventura** donde probaremos las clases anteriores.
### Aventura.cs
```csharp
using System;

namespace Aventura
{
    class Aventura
    {
        static void t(SabeLuchar x)
        {
            x.luchar();
        }
        static void u(SabeNadar x)
        {
            x.nadar();
        }
        static void v(SabeVolar x)
        {
            x.volar();
        }
        static void w(PersonajeDeAccion x)
        {
            x.luchar();
        }
        static void Main(string[] args)
        {
            Heroe i = new Heroe();
            t(i); // Tratar como un SabeLuchar
            u(i); // Tratar como un SabeNadar
            v(i); // Tratar como un SabeVolar
            w(i); // Tratar como un PersonajeDeAccion
        }
    }
}
```
### Salida:
Si ejecutamos nuestro proyecto obtendremos la siguiente salida:
```
SABE LUCHAR PERSONAJE ACCION
SABE NADAR HEROE
SABE VOLAR HEROE
SABE LUCHAR PERSONAJE ACCION
```
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

