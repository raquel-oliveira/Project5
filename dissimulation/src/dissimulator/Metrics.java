package dissimulator;

import java.awt.image.BufferedImage;

public class Metrics {

	/**
	 * Prints out the number of bits available for hiding. Prints out the number of bits to hide (message)
	 * @param message The message to hide
	 * @param image The imageRGB
	 */
	public void nbBitsImpacted(String message, ImageRGB image)
	{
		System.out.println("\nMaximum number of bits available : " + (image.getWidth() * image.getHeight() * 3));
		System.out.println("Number of bits impacted : " + (message.length() * 8));
	}
}
