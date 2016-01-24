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
		if(arg.getMetrics())  met.setTime();
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
		
		// Compression and metrics of compression
		else
		{
			HuffmanTree huff = new HuffmanTree();
			huff.createList(msgTreatment.getNbIterations(message));
			huff.constructHuffmanTree();
			huff.getCodes();
			Compressor compressor = new Compressor(huff.getDictionnary(), huff.getCodelength());
			byte[] array1 = compressor.messageCompression(message);
			byte[] array2 = mnt.mnCompressionBArray();
			byte[] finalArray = Compressor.groupByteArray(array1, array2);
			BitSet compressed = BitSet.valueOf(finalArray);
			compressed.set(finalArray.length*8);
			
			bitsetMessage = compressed; // Starting from here, we have the fully compressed message
			if(arg.getShow()) met.getDictionary(huff.getDictionnary(), huff.getCodelength(), bitsetMessage);
			if(arg.getMetrics()) met.getTime();
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
		
		if(arg.getMetrics())
		{
			met.nbBitsImpacted(bitsetMessage, nbColorsNotNull, manipMat.getImage());
			met.getTime();
			double sizeSaved = met.getCompressionSavings(message, bitsetMessage);
			if(sizeSaved > 0) System.out.println("Saved space with compression : " + sizeSaved + "%");
			else System.out.println("The compression was a bad idea ! Saved space with compression : " + sizeSaved + " %");
		}
	}
}
