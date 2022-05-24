class TestOverride{

    public class Empleado {

        public string nombre { get; }

        // pagoNeto esta definida como protected, solo va a poder ser accesible por estas clases y las clases derivadas
        protected float _pagoNeto;

        // Constructor para establecer el nombre y los valores pagoNeto.
        public Empleado(string nombre, float pagoNeto)
        {
            nombre = nombre;
            _pagoNeto = pagoNeto;
        }

        // Declarada virtual para que no pueda ser sobreescrita
        public virtual float Pago()
        {
            return _pagoNeto;
        }
    }

    // Deriva de la clase empleado
    public class VentasEmpleado : Empleado{

        private float _bonoVentas;

        // El constructor llama a la versión de clase base e inicializa el campo de bonificación de ventas.
        public VentasEmpleado(string nombre, float pagoNeto, float bonoVentas): base(nombre, pagoNeto)
        {
            _bonoVentas = bonoVentas;
        }

        //Reescribe el metodo Pago para tener en cuenta la bonificacion
        public override float Pago()
        {
            return _pagoNeto + _bonoVentas;
        }
    }

    static void Main() {

        var Empleado1 = new VentasEmpleado("Carlos", 1000, 500);
        var Empleado2 = new Empleado("Juan", 1200);

        Console.WriteLine($"Empleado {Empleado1.nombre} ha ganado: {Empleado1.Pago()}");
        Console.WriteLine($"Empleado {Empleado2.nombre} ha ganado: {Empleado2.Pago()}");
    }
}
