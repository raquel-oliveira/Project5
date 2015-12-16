package dissimulator;

public class Arguments {

	String formatIn;
	String formatOut;
	String fileIn;
	String fileOut;
	String message;
	String nbBits;
	String channels;
	String pattern;
	String magic;
	String metrics;
	
	public Arguments(String[] arguments)
	{
		for(int i = 0; i < arguments.length ; i++)
		{
			if(arguments[i].equals("-Fin")) formatIn = arguments[i+1];
			else if(arguments[i].equals("-Fout")) formatOut = arguments[i+1];
			else if(arguments[i].equals("-in")) fileIn = arguments[i+1];
			else if(arguments[i].equals("-out")) fileOut = arguments[i+1];
			else if(arguments[i].equals("-msg")) message = arguments[i+1];
			else if(arguments[i].equals("-b")) nbBits = arguments[i+1];
			else if(arguments[i].equals("-c")) channels = arguments[i+1];
			else if(arguments[i].equals("-p")) pattern = arguments[i+1];
			else if(arguments[i].equals("-magic")) magic = arguments[i+1];
			else if(arguments[i].equals("-metrics")) metrics = arguments[i+1];
		}
	}
	public String getArg(String what) throws Throwable
	{
		if(what.equals("formatIn")) 
		{
			if(formatIn == null) throw new EmptyArgumentException("Requested argument is empty");
			return formatIn;
		}
		else if(what.equals("formatOut"))
		{
			if(formatOut == null) throw new EmptyArgumentException("Requested argument is empty");
			return formatOut;
		}
		else if(what.equals("fileIn"))
		{
			if(fileIn == null) throw new EmptyArgumentException("Requested argument is empty");
			return fileIn;
		}
		else if(what.equals("fileOut"))
		{
			if(fileOut == null) return "output/result.png";
			return fileOut;
		}
		else if(what.equals("message"))
		{
			if(message == null) throw new EmptyArgumentException("Requested argument is empty");
			return message;
		}
		else if(what.equals("nbBits"))
		{
			if(nbBits == null) return "1";
			return nbBits;
		}
		else if(what.equals("channels"))
		{
			if(channels == null) throw new EmptyArgumentException("Requested argument is empty");
			return channels;
		}
		else if(what.equals("pattern"))
		{
			if(pattern == null) return "Direct";
			return pattern;
		}
		else if(what.equals("magic"))
		{
			if(magic == null) return "HELP";
			return magic;
		}
		else if(what.equals("metrics"))
		{
			if(metrics == null) throw new EmptyArgumentException("Requested argument is empty");
			return metrics;
		}
		
		throw new InvalidArgumentException("Requested argument is invalid");
	}
}
