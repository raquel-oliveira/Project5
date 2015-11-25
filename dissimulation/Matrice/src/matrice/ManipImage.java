package matrice;

import java.awt.image.BufferedImage;

import java.awt.Color;

import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import java.util.BitSet;

// @author Charly Lafon

public class ManipImage {
	
	private ImageRGB image;
	
	/**
	 * Constructs a BufferedImage. Get width and height from the image.
	 * @param Path to file
	 */
	public ManipImage(String s)
	{
		image = new ImageRGB(s);
	}
	
	/**
	 * Create a new image with the new RGB colors.
	 * @param array red
	 * @param array blue
	 * @param array green
	 * @throws IOException
	 */
	public void setPixelsColor() throws IOException
	{
		int z = 0;
		
		for(int i = 0; i < image.getHeight() - 1; i++)
		{
			for(int j = 0; j < image.getWidth() - 1; j++)
			{
				int rgb = new Color(image.getRedArray()[z], image.getGreenArray()[z], image.getBlueArray()[z]).getRGB(); // Creates a new color from the colors given to the method 
		        image.getImageBuff().setRGB(j, i, rgb); // Sets the pixel(j,i) with the new color
				z++;				
			}
		}
		ImageIO.write(image.getImageBuff(), "png", new File("sortie.png")); // Writes a new image in the storage
	}
	
	/**
	 * Change each bytes's last bit of RGB colors, with selection from the user of the colors.
	 * Put null to the non-wanted array(s) color
	 * @param Bitset from the string to hide
	 */
	public void dissimulationLSB(BitSet bIn)
	{
		int z = 0;
		
		for(int i = 0; i < bIn.length(); i++)
		{
			if(i < bIn.length())
			{
				setDissimulation(bIn, image.getRedArray(), i, z);
			}
			if(i < bIn.length() -1)
			{
				setDissimulation(bIn, image.getGreenArray(), ++i, z);

			} 
			if(i < bIn.length() -1)
			{
				setDissimulation(bIn, image.getBlueArray(), ++i, z);

			}
			
			z++;
		}
	}
	public void setDissimulation(BitSet bIn, int[] array, int i, int z)
	{
		if(!bIn.get(i) && !isNbEven(array[z])) array[z] -= 1; // Si le bit est false et que le LSB actuel est 1,on met à 0 le LSB
		
		else if (bIn.get(i) && isNbEven(array[z])) // Si le bit est true et que le LSB actuel est 0, on met à 1 le LSB de red
		{
			if(array[z] == 0) array[z] += 1; // Si on a le nombre = 0, on incrémente au lieu de décrémenter
			else array[z] -= 1;
		}
	}
	public boolean isNbEven(int x)
	{
		if(x % 2 == 0) return true;
		return false;
	}
	
	/**
	 * Prints out the number of bits available for hiding. Prints out the number of bits to hide (s)
	 * @param string to hide
	 */
	public void nbBitsAvailable(String s)
	{
		System.out.println("Nombre maximum de bits disponibles : " + (image.getWidth() * image.getHeight() * 3));
		System.out.println("Nombre de bits à cacher : " + (s.length() * 8));
	}
	public int[] getRedArray()
	{
		return image.getRedArray();
	}
	public int[] getGreenArray()
	{
		return image.getGreenArray();
	}
	public int[] getBlueArray()
	{
		return image.getBlueArray();
	}
}
