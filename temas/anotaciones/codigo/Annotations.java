package codigo;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

public class Annotations {
	
	// Element.TYPE -> This annotation is for the class
	
	@Retention(RetentionPolicy.RUNTIME)
	@Target({ ElementType.TYPE})
	public @interface compareBySomething{
		String type() default "id";
	}	

	
}
