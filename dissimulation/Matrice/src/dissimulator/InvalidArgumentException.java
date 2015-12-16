package dissimulator;

public class InvalidArgumentException extends Exception{

	public InvalidArgumentException(String message)
	{
		super("Error : " + message);
	}
}
