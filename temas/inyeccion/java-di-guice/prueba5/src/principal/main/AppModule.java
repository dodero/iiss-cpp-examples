package principal.main;
import com.google.inject.AbstractModule;

import servicios.ofrecidos.Alquiler;
import servicios.ofrecidos.AlquilerBicis;

public class AppModule extends AbstractModule{
	
	@Override
	protected void configure() {
		bind(Alquiler.class).to(AlquilerBicis.class);
	}
}
 