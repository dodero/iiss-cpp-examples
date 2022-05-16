package futbol;

public aspect NarracionAspect {
    pointcut callmaradona(): call(* Narracion.maradona());


    before(): callmaradona() {
        System.out.println("REPITO");
    }

    after(): callmaradona() {
        System.out.println("QUIERO LLORAR!!!");
    }
}