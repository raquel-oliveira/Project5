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
	FormatDetector fd;
	
	public Arguments(String[] arguments)
	{
		this.fd = new FormatDetector();
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
	public String getArg(String what) throws Exception
	{
		if(what.equals("formatIn")) 
		{
			if(formatIn == null){
				fd.setFiletype(this.fileIn);
				return fd.getFileType();
			};
			return formatIn;
		}
		else if(what.equals("formatOut"))
		{
			if(formatOut == null) return "png";
			return formatOut;
		}
		else if(what.equals("fileIn"))
		{
			if(fileIn == null) throw new EmptyArgumentException("Requested input file argument is empty");
			return fileIn;
		}
		else if(what.equals("fileOut"))
		{
			if(fileOut == null) return "output/result.png";
			return fileOut;
		}
		else if(what.equals("message"))
		{
			if(message == null) throw new EmptyArgumentException("Requested message argument is empty");
			return message;
		}
		else if(what.equals("nbBits"))
		{
			if(nbBits == null) return "1";
			return nbBits;
		}
		else if(what.equals("channels"))
		{
			if(channels == null) {
				fd.setFiletype(fileIn);
				String formatused = fd.getFileType();
				if(formatused.equals("bmp")||formatused.equals("pgm")) return "Gray";
				else return "Red, Green, Blue";
			}
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
			if(metrics == null) return null;
			return metrics;
		}
		
		throw new InvalidArgumentException("Requested argument is invalid");
	}
}
