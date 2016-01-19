package dissimulator;

import java.io.IOException;
import java.util.BitSet;

public class Main {
	
	public static void main(String[] args) throws IOException, Exception {
		//Getting of arguments
		
		Arguments arg = new Arguments(args);
		Metrics met = new Metrics();
		if(arg.getMetrics().equals("time"))  met.setTime();
		MessageTreatment msgTreatment = new MessageTreatment();
		
		String in = arg.getFileIn();
		String out = arg.getFileOut();
		String message = arg.getMessage();
		String[] colors = new String[3];

		//Checking the message for the magic number
		MagicNumberTester mnt = new MagicNumberTester(arg.getMagic());

		message = msgTreatment.whetherFileOrText(message, mnt);
		
		// Compressing the message
		if(arg.getMetrics().equals("compression_time")) met.setTime();
		if(arg.getCompress()) msgTreatment.getNbIterations(message);
		
		if(arg.getMetrics().equals("compression_time")) met.getTime();
		ManipImage manipMat = new ManipImage(in);
        
        //From message to BitSet
		
		BitSet b = msgTreatment.ChaintoBinary(message);
		
		// Colors treatment
		
		String channels = arg.getChannels(), temp = "";
		
		for(int i = 0, cpt = 0; i < channels.length(); i++)
		{
			temp += channels.charAt(i);
			if(temp.equals("red") || temp.equals("green") || temp.equals("blue"))
			{
				colors[cpt++] = temp;
				temp = "";
			}
		}
		int nbColorsNotNull;
		if(colors[1] == null && colors[2] == null) nbColorsNotNull = 1;
		else if(colors[1] != null && colors[2] == null) nbColorsNotNull = 2;
		else nbColorsNotNull = 3;
		
		if(((message.length() + arg.getMagic().length()) * 8  / Integer.parseInt(arg.getNbBits())) > 
			(manipMat.getImage().getWidth() * nbColorsNotNull * manipMat.getImage().getHeight())) 
			throw new InvalidArgumentException("Message + magic number do not fit in the image");
		
		try
		{ 
			manipMat.dissimulationLSB(b, Integer.parseInt(arg.getNbBits()), arg.getPattern(), colors);
		}
		catch(InvalidArgumentException | EmptyArgumentException e)
		{
			System.out.println(e.getMessage());
		}	
		
		manipMat.setPixelsColor(out, arg.getFormatIn(), arg.getFormatOut());
		if(arg.getMetrics().equals("impact"))  met.nbBitsImpacted(message, nbColorsNotNull, manipMat.getImage());
		else if(arg.getMetrics().equals("time"))  met.getTime();
	}
}
