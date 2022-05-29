package solicitudes;

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
