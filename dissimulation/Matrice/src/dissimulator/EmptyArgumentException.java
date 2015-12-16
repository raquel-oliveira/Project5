package dissimulator;

public class EmptyArgumentException extends Exception{

	public EmptyArgumentException(String message)
	{
		super("Error : " + message);
	}
}
