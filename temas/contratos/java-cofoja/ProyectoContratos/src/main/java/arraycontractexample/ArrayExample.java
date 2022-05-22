package arraycontractexample;

import com.google.java.contract.*;

@Invariant({"position < 10"})
public class ArrayExample {
	
	private int[] example;
	private int position;
	
	public ArrayExample()
	{
		this.example = new int[10];
		this.position = 0;
	}
	
	@Requires({"i > 0"})
	public void addPositiveNumber(int i)
	{
		example[position]=i;
		position++;
	}
	
	@Requires({"position > 0"})
	@Ensures({"result > 0"})
	public int sumArrayNumbers()
	{
		int valor = 0;
		for(int x = 0; x < position; x++)
		{
			valor += example[x];
		}
		return valor;
	}
	
	/*public static void main(String args[])
	{
		try
		{
		ArrayExample ex = new ArrayExample();
		ex.addPositiveNumber(5);
		ex.addPositiveNumber(6);
		System.out.println(ex.sumArrayNumbers());
		ex.addPositiveNumber(-20);
		System.out.println(ex.sumArrayNumbers());
		}catch(PreconditionError pe) {}
	}*/
}


