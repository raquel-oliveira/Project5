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
		else if(what.equals("formatOut"))
		{
			fd.setFiletype(this.fileIn);
			if(formatOut== null) return null;
			else if(formatOut.equals(".jpg") || formatOut.equals(".jpeg"))
				throw new InvalidArgumentException("JPEG is not a valid format for the output");
			else if(fd.getFileType().toLowerCase().equals("jpeg") && (formatOut.equals(".png"))) return formatOut;
			else if(formatOut.contains(fd.getFileType().toLowerCase())) return formatOut;
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
		else if(what.equals("pattern"))
		{
			if(pattern == null) return "Direct";
			if(!pattern.equals("direct") && !pattern.equals("reverse") && !pattern.equals("external_spiral") && !pattern.equals("internal_spiral"))
				throw new InvalidArgumentException("Incorrect typing of metrics");
			return pattern;
		}
		else if(what.equals("magic"))
		{
			if(magic == null) return "48454C50";
			return magic;
		}
		else if(what.equals("metrics"))
		{
			if(metrics == null) return null;
			if(!metrics.equals("impact") && !metrics.equals("time") && !metrics.equals("histogram") && !metrics.equals("template"))
				throw new InvalidArgumentException("Incorrect typing of metrics");
			return metrics;
		}
		
		throw new InvalidArgumentException("Requested argument is invalid");
	}
}
