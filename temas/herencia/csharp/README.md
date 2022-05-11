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
