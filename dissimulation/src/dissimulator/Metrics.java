package dissimulator;

import java.time.Duration;
import java.time.Instant;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;

public class Metrics {

	long beginning, ending;
	Instant start, end;
	MagicNumberTester mnt = new MagicNumberTester();

	/**
	 * Prints out the number of bits available for hiding. Prints out the number of bits to hide (message)
	 * @param message The message to hide
	 * @param image The imageRGB
	 */
	public void nbBitsImpacted(String message,int nbColorsNotNull, ImageRGB image)
	{
		System.out.println("\nMaximum number of bits available : " + (image.getWidth() * image.getHeight() * nbColorsNotNull));
		System.out.println("Number of bits impacted : " + (message.length() * 8));
	}
	
	public void setTime()
	{
		start = Instant.now();
	}
	
	/**
	 * Prints out the time consumed by the dissimulation
	 */
	public void getTime()
	{
		end = Instant.now();
		System.out.println("Time consumed by the dissimulation : " + Duration.between(start, end).toMillis());
	}
	
	/**
	 * Calculates then prints out the space saved by the compression. The result may be below zero, showing that the compression
	 * was not useful.
	 */
	public void getCompressionSavings(String originalMessage, BitSet compressedMessage)
	{
		double sizeOriginal = originalMessage.length() * 8;
		double sizeCompressed = compressedMessage.length();
		
		double sizeSaved = 1 - (sizeCompressed/sizeOriginal)*100;
		
		if(sizeSaved > 0) System.out.println("Saved space with compression : " + sizeSaved + "%");
		else System.out.println("The compression was a bad idea ! Saved space with compression : " + sizeSaved + "%");
	}
	
	public void getDictionary(HashMap<String, Integer> dicoCode, HashMap<String, Integer> dicoLength, String messageCompressed)
	{
		for (Map.Entry<String, Integer> mapEntry : dicoCode.entrySet()) 
		{
	       String valueDictionary = Integer.toBinaryString(mapEntry.getValue());
	       
	       int length = dicoLength.get(mapEntry.getKey());
	       if(valueDictionary.length() != length)
	       {
	    	   StringBuilder temp = new StringBuilder(valueDictionary);
	    	   temp = temp.reverse();
	    	   while(temp.length() != length)
	    	   {
	    		   temp = temp.append('0');
	    	   }
	    	   temp = temp.reverse();
	    	   valueDictionary = temp.toString();
	       }
	       byte[] array = mapEntry.getKey().getBytes();
	       String hexCode = mnt.toHexString(array);
	       System.out.println("0x" + hexCode + ": " + valueDictionary);
	    }
		byte[] binaryMessage = messageCompressed.getBytes();
		for(int i = 0, cpt = 0; i < binaryMessage.length; i++, cpt++)
	    {
			String binaryString = String.format("%8s", Integer.toBinaryString(binaryMessage[i] & 0xFF)).replace(' ', '0');
			System.out.print(binaryString);
			System.out.print(" ");
	    }
		System.out.print("\n");
	}
}
