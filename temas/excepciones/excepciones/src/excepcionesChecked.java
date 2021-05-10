import java.awt.Image;
import java.io.EOFException;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class excepcionesChecked {

	excepcionesChecked(){}
	
	public static void excepcionIO() throws IOException{
		Image imagen;
		imagen = ImageIO.read(new File("src/imagenQueNoExiste.jpg"));
	}

	public static void excepcionEOF() throws EOFException{
		throw new EOFException("Hola soy el mensaje de EOFException, la capturaste");
	}

	public static void excepcionPropiaChecked(String name) throws nombreDeNuestraAsignaturaErroneo{
		if(name != "IISS") throw new nombreDeNuestraAsignaturaErroneo("Esto no es "+name+", ESTO ES IISS!!!");
	}	
}

class nombreDeNuestraAsignaturaErroneo extends Exception{
	public nombreDeNuestraAsignaturaErroneo() {}
	public nombreDeNuestraAsignaturaErroneo(String mensajeDeError) {super(mensajeDeError);}
}