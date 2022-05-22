package arraycontractexample;
import org.junit.Test;
import com.google.java.contract.*;

public class ArrayExampleTests {

	@Test
	public void negativeNumber()
	{
		ArrayExample ex = new ArrayExample();
		ex.addPositiveNumber(-3);
	}
	
	@Test
	public void positiveNumber()
	{
		ArrayExample ex = new ArrayExample();
		ex.addPositiveNumber(3);
	}
	
	@Test
	public void emptyList()
	{
		ArrayExample ex = new ArrayExample();
		ex.sumArrayNumbers();
	}
	
	@Test
	public void negativeResult()
	{
		ArrayExample ex = new ArrayExample();
		ex.addPositiveNumber(3);
		ex.addPositiveNumber(4);
		ex.sumArrayNumbers();
	}
}
