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
