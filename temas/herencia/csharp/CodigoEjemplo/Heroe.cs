using System;
namespace Aventura
{
    public class Heroe : PersonajeDeAccion, SabeLuchar, SabeNadar,SabeVolar
    { 
        public void volar() { Console.WriteLine("SABE VOLAR HEROE"); }

        public void nadar() { Console.WriteLine("SABE NADAR HEROE"); }
    }
}
