
package principal.main;
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
