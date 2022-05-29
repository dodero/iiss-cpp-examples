## Inyecciones en Java
Autor: Lucía Caro Barrera

## Framework usado
```
Google Guice

```
## Entorno utilizado 
```	
Eclipse
```
## Dependencias del paquete
```
guice-4.2.1-no_aop.jar
javax.inject-1.jar
j2objc-annotations-1.1.jar
animal-sniffer-annotations-1.14.jar
checker-compat-qual-2.0.0.jar
aopalliance-1.0.jar
jsr305-3.0.2.jar
guava-25.1-android.jar
error_prone_annotations-2.1.3.jar
asm-9.0.jar

```
## Código
```
//Paquete servicios ofrecidos 
public interface Alquiler {
	void alquilar();
}

public class AlquilerBicis implements Alquiler{
	@Override
	public void alquilar() {
		System.out.println("¡Bici alquilada!");
	}
}

//Paquete solicitudes
import servicios.ofrecidos.Alquiler;

public class SolicitudBicis {
	Alquiler d;
	 
	public void solicitarBici(Alquiler d) {
		this.d = d;
	}
	
	public void  solicitar(){
		d.alquilar();
	}
}

//Paquete principal
import com.google.inject.AbstractModule;

import servicios.ofrecidos.Alquiler;
import servicios.ofrecidos.AlquilerBicis;

public class AppModule extends AbstractModule{
	
	@Override
	protected void configure() {
		bind(Alquiler.class).to(AlquilerBicis.class);
	}
}

import com.google.inject.Guice;
import com.google.inject.Injector;

import servicios.ofrecidos.Alquiler;
import servicios.ofrecidos.AlquilerBicis;
import solicitudes.SolicitudBicis;

public class Main {
	
	private static void hacerSolicitud() {
		Injector injector = Guice.createInjector(new AppModule());
		Alquiler d  = injector.getInstance(Alquiler.class);
		SolicitudBicis solici = new SolicitudBicis();
		solici.solicitar();
	}
	
	public static void main(String[] args) {
		hacerSolicitud();
	}
}


```

## Explicación
Tenemos un servicio de alquiler de bicicletas y, para alquilar una de ellas, debemos realizar una solicitud. Podríamos decir que, una solicitud se realiza cuando intentamos alquilar una bicicleta, por lo tanto, existe una dependencia fuerte entre estas dos clases.  Ésto implica que ambas clases estén acopladas y además, sea poco flexible para poder ampliar el servicio de alquiler.

¿Qué nos ofrece la inyección de dependencias? Nos proporcionará menor dependencia entre las clases y poder ampliar el servicio que ofrecemos.
Para ello crearemos una interfaz Alquiler con un único método alquilar(). Además, heredaremos de esta interfaz creando una subclase AlquilerBicis y sobrescribiendo dicho método. Si quisiéramos, en este punto podríamos crear otros servicios(coche, moto...). 
Crearemos otro módulo llamado AppModule en el que definiremos la dependencia para que, cada vez que se necesite una dependencia de tipo alquiler, se cree una instancia de la subclase, en este caso, de alquilerBicis.
Por último, inyectamos la dependencia en el main. Creamos un objeto de la clase solicitudBicis y,  como éste tiene un atributo de tipo alquiler, la instancia que se crea dada la inyección que hemos definido será de tipo alquilerBicis. Por lo tanto, cuando éste invoque al método alquiler(), deberá imprimirse el contenido definido en el método AlquilerBicis::alquilar() : ¡Bici alquilada!

