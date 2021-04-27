package codigo;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

public class Annotations {
	
	// Element.TYPE -> This annotation is for the class
	// Element.FIELD -> This annotations is for fields in the class
	
	@Retention(RetentionPolicy.RUNTIME)
	@Target({ ElementType.TYPE, ElementType.FIELD})
	public @interface compareById{
		
	}	
	
	@Retention(RetentionPolicy.RUNTIME)
	@Target({ ElementType.TYPE, ElementType.FIELD})
	public @interface compareByDate{
		
	}

	
	
}
