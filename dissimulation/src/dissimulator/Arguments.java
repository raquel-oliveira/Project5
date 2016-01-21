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
	boolean compress;
	boolean show;
	FormatDetector fd;
	
	/**
	 * Puts in the corresponding attributes the parameters puts in the console.
	 * Some of them are put to lowerCase in order to not worry about 1000 way of typing arguments
	 * @param arguments String[] received from the console
	 */
	public Arguments(String[] arguments)
	{
		fd = new FormatDetector();
		for(int i = 0; i < arguments.length ; i++)
		{
			if(arguments[i].equals("-Fin")) formatIn = "." + arguments[i+1].toLowerCase();
			else if(arguments[i].equals("-Fout")) formatOut = "." + arguments[i+1].toLowerCase();
			else if(arguments[i].equals("-in")) fileIn = arguments[i+1];
			else if(arguments[i].equals("-out")) fileOut = arguments[i+1];
			else if(arguments[i].equals("-msg")) message = arguments[i+1];
			else if(arguments[i].equals("-b")) nbBits = arguments[i+1];
			else if(arguments[i].equals("-c")) channels = arguments[i+1].toLowerCase();
			else if(arguments[i].equals("-p")) pattern = arguments[i+1].toLowerCase();
			else if(arguments[i].equals("-magic")) magic = arguments[i+1];
			else if(arguments[i].equals("-metrics")) metrics = arguments[i+1].toLowerCase();
			else if(arguments[i].equals("-compress")) compress = true;
			else if(arguments[i].equals("-show")) show = true;
		}
	}
	
	public String getFormatIn() throws Exception
	{
		fd.setFiletype(this.fileIn);
		if(formatIn == null){
			return "."+fd.getFileType().toLowerCase();
		}
		else if(fd.getFileType().toLowerCase().equals("jpeg") && (formatIn.equals(".jpg") || formatIn.equals(".jpeg")))
		{
			return ".jpg";
		}
		else {
			if(!formatIn.equals("."+fd.getFileType().toLowerCase()))
				throw new InvalidArgumentException("Format argument does not match input file format");
		}
		return formatIn;
	}
	public String getFormatOut() throws Exception
	{
		fd.setFiletype(this.fileIn);
		if(formatOut== null) return null;
		else if(formatOut.equals(".jpg") || formatOut.equals(".jpeg"))
			throw new InvalidArgumentException("JPEG is not a valid format for the output");
		else if(fd.getFileType().toLowerCase().equals("jpeg") && (formatOut.equals(".png"))) return formatOut;
		else if(formatOut.contains(fd.getFileType().toLowerCase())) return formatOut;
		else throw new InvalidArgumentException("Output format is not valid");
	}
	public String getFileIn() throws Exception
	{
		if(fileIn == null) throw new EmptyArgumentException("Requested input file argument is empty");
		return fileIn;
	}
	public String getFileOut() throws Exception
	{
		if(fileOut == null) return "output/result.png";
		return fileOut;
	}
	public String getMessage() throws Exception
	{
		if(message == null) throw new EmptyArgumentException("Requested message argument is empty");
		return message;
	}
	public String getNbBits() throws Exception
	{
		if(nbBits == null) return "1";
		if(nbBits.length() > 1) throw new InvalidArgumentException("Number of bits too high");
		if(!Character.isDigit(nbBits.charAt(0))) throw new InvalidArgumentException("Number of bits is not a number !");
		return nbBits;
	}
	public String getChannels() throws Exception
	{
		if(channels == null) return "redgreenblue";
		if(channels.contains(","))
		{
			String temp = "", retour = "";
			for(int i = 0; i < channels.length(); i++)
			{
				temp += channels.charAt(i);
				if((i == channels.length()-1) || (channels.charAt(i+1) == ','))
				{
					i++; // Ignoring the comma
					if(temp.equals("red") || temp.equals("green") || temp.equals("blue"))
					{
						if(retour.contains(temp)) throw new InvalidArgumentException("Typed the same color twice"); // Ex : Red,Red,Green
						retour += temp;
						temp = "";
					}
					else throw new InvalidArgumentException("Incorrect typing of color channels"); // Argument before comma is illegal
				}
				
			}
			return retour;
		}
		else if(channels.equals("red")) return "red";
		else if(channels.equals("green")) return "green";
		else if(channels.equals("blue")) return "blue";
		else throw new InvalidArgumentException("Incorrect typing of color channels");
	}
	public String getPattern() throws Exception
	{
		if(pattern == null) return "Direct";
		if(!pattern.equals("direct") && !pattern.equals("reverse") && !pattern.equals("external_spiral") && !pattern.equals("internal_spiral"))
			throw new InvalidArgumentException("Incorrect typing of pattern");
		return pattern;
	}
	public String getMagic() throws Exception
	{
		if(magic == null) return "48454C50";
		return magic;
	}
	public String getMetrics() throws Exception
	{
		if(metrics == null) return null;
		if(!metrics.equals("impact") && !metrics.equals("time") && !metrics.equals("histogram")
				&& !metrics.equals("template") && !metrics.equals("compression_savings") && !metrics.equals("compression_time"))
			throw new InvalidArgumentException("Incorrect typing of metrics");
		return metrics;
	}
	public boolean getCompress() throws Exception
	{
		if(compress == false) return false;
		return true;
	}
	public boolean getShow() throws Exception
	{
		if(show == false) return false;
		return true;
	}
}
