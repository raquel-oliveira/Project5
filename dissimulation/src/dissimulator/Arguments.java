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
			if(arguments[i].equals("-Fin")) formatIn = "." + arguments[i+1].toLowerCase();
			else if(arguments[i].equals("-Fout")) formatOut = "." + arguments[i+1].toLowerCase();
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
			fd.setFiletype(this.fileIn);
			if(formatIn == null){
				return "."+fd.getFileType().toLowerCase();
			}
			else if(fd.getFileType().toLowerCase().equals("jpeg") && (formatIn.equals(".jpg") || formatIn.equals(".JPEG") || formatIn.equals(".jpeg") || formatIn.equals(".JPG")))
			{
				return ".jpg";
			}
			else {
				if(!formatIn.equals("."+fd.getFileType().toLowerCase()))
					throw new InvalidArgumentException("Format argument does not match input file format");
			}
			return formatIn;
		}
		else if(what.equals("formatOut"))
		{
			fd.setFiletype(this.fileIn);
			if(formatOut== null) return null;
			else if(formatOut.toLowerCase().equals(fd.getFileType().toLowerCase())){
				return formatOut;
			}
			else throw new InvalidArgumentException("Output format is not valid");
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
			if(channels == null) return "Red";
			return channels;
		}
		else if(what.equals("pattern"))
		{
			if(pattern == null) return "Direct";
			return pattern;
		}
		else if(what.equals("magic"))
		{
			if(magic == null) return "48 45 4C 50";
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
