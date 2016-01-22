package dissimulator;

import java.io.IOException;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;

public class Main {
	
	public static void main(String[] args) throws IOException, Exception {
		//Getting of arguments
		
		Arguments arg = new Arguments(args);
		Metrics met = new Metrics();
		if(arg.getMetrics().equals("time"))  met.setTime();
		MessageTreatment msgTreatment = new MessageTreatment();
		BitSet bitsetMessage = null;
		
		String in = arg.getFileIn();
		String out = arg.getFileOut();
		String message = arg.getMessage();
		String[] colors = new String[3];
		ManipImage manipMat = new ManipImage(in);

		//Checking the message for the magic number
		MagicNumberTester mnt = new MagicNumberTester(arg.getMagic());

		message = msgTreatment.whetherFileOrText(message, mnt);
		
		if(!arg.getCompress())
		{
			if(mnt.doesStringContainMN(message))
				throw new MagicNumberException("Ce message contient le nombre magique");
			else message += mnt.hexStringtoString();
		}
		else
		{
			if(arg.getMetrics().equals("compression_time")) met.setTime();
			PredefinedDictionnary dict = new PredefinedDictionnary();
			Compressor compressor = new Compressor(dict.getDicoCode(), dict.getDicoLength());
			byte[] array1 = compressor.messageCompression(message);
			byte[] array2 = mnt.mnCompressionBArray();
			byte[] finalArray = Compressor.groupByteArray(array1, array2);
			BitSet compressed = BitSet.valueOf(finalArray);
			compressed.set(finalArray.length*8);
			
			for(int k = 0, cpt = 0; k < compressed.length() - 1; k++, cpt++)
			{
				if(cpt%8 == 0 && cpt !=0) System.out.print(" ");
				if(compressed.get(k)) System.out.print("1");
				else System.out.print("0");
				
			}
			System.out.println("\n");
			
			bitsetMessage = compressed;
			if(arg.getMetrics().equals("compression_time")) met.getTime();
			if(arg.getShow()) met.getDictionary(dict.getDicoCode(), dict.getDicoLength(), bitsetMessage);
		}
		
        //From message to BitSet
		
		if(!arg.getCompress()) bitsetMessage = msgTreatment.ChaintoBinary(message);
		
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
			manipMat.dissimulationLSB(bitsetMessage, Integer.parseInt(arg.getNbBits()), arg.getPattern(), colors);
		}
		catch(InvalidArgumentException | EmptyArgumentException e)
		{
			System.out.println(e.getMessage());
		}	
		
		manipMat.setPixelsColor(out, arg.getFormatIn(), arg.getFormatOut());
		
		if(arg.getMetrics().equals("impact"))  met.nbBitsImpacted(message, nbColorsNotNull, manipMat.getImage());
		else if(arg.getMetrics().equals("time"))  met.getTime();
		else if(arg.getMetrics().equals("compression_savings"))
		{
			double sizeSaved = met.getCompressionSavings(message, bitsetMessage);
			if(sizeSaved > 0) System.out.println("Saved space with compression : " + sizeSaved + "%");
			else System.out.println("The compression was a bad idea ! Saved space with compression : " + sizeSaved + " %");
		}
	}
}
