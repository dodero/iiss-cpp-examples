using System;
using System.Collections.Generic;

namespace ProyectoDelegación
{
    public delegate void delegateAfinar(Instrumento i);
    public delegate void delegateTocar(Instrumento i);

    public abstract class Instrumento
    {
        public abstract void tocar();
        public abstract void afinar();
    }

    public class Viento : Instrumento
    {
        public override void tocar() { soplar(); }
        public override void afinar() { Console.WriteLine("afinar soplido"); }
        public void soplar() { Console.WriteLine("soplar"); }
    }

    public class Cuerda : Instrumento
    {
        public override void tocar() { rasgar(); }
        public override void afinar() { Console.WriteLine("afinar rasgado"); }
        public void rasgar() { Console.WriteLine("rasgar"); }
    }

    public class Percusion : Instrumento
    {
        public override void tocar() { golpear(); }
        public override void afinar() { Console.WriteLine("afinar golpeado"); }
        public void golpear() { Console.WriteLine("golpear"); }
    }

    class Orquesta
    {
        delegateAfinar dA = delegate (Instrumento i)
        {
            i.afinar();
        };

        delegateTocar dT = delegate (Instrumento i)
        {
            i.tocar();
        };
        private List<Instrumento> instruments;
        public Orquesta()
        {
            instruments = new List<Instrumento>();
        }
        public void addInstrumento(Instrumento i)
        {
            instruments.Add(i);
        }
        public void removeInstrumento(Instrumento i)
        {
            instruments.Remove(i);
        }
        public List<Instrumento> instrumentos()
        {
            return instruments;
        }
        public void tocar()
        {
            foreach (Instrumento i in instruments)
            {
                dT(i);
            }
        }
        public void afinar()
        {
            foreach(var i in instruments)
            {
                dA(i);
                dT(i);
            }
        }
    }

    
    public class Program
    {
        public static void Main()
        {
            Orquesta orquesta = new Orquesta();
            orquesta.addInstrumento(new Viento());
            orquesta.addInstrumento(new Cuerda());
            orquesta.addInstrumento(new Percusion());
            orquesta.afinar();
            orquesta.tocar();
        }
    }
}