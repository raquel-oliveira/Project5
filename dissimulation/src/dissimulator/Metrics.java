package dissimulator;

import java.time.Duration;
import java.time.Instant;
import java.util.BitSet;

public class Metrics {

	long beginning, ending;
	Instant start, end;

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
		System.out.println(Duration.between(start, end).toMillis());
	}
	
	/**
	 * Calculates then prints out the space saved by the compression. The result may be below zero, showing that the compression
	 * was not useful.
	 */
	public void getCompressionSavings(String originalMessage, BitSet compressedMessage)
	{
		int sizeOriginal = originalMessage.length() * 8;
		int sizeCompressed = compressedMessage.length();
		
		int sizeSaved = 1 - (sizeCompressed/sizeOriginal)*100;
		
		System.out.println("Saved space with compression : " + sizeSaved + "%");
	}
}
