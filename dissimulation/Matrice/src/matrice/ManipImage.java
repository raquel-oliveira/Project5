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
	 * @param in path to file
	 */
	public ManipImage(String in)
	{
		this.image = new ImageRGB(in);
	}
	
	/**
	 * Create a new image with the new RGB colors.
	 * @param sortie filename du fichier de sortie
	 * @throws IOException
	 */
	public void setPixelsColor(String sortie) throws IOException
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
		ImageIO.write(image.getImageBuff(), "png", new File(sortie)); // Writes a new image in the storage
	}
	
	/**
	 * Change each bytes's last bit of RGB colors, with selection from the user of the colors.
	 * Put null to the non-wanted array(s) color
	 * @param bIn BitSet of the string to hide
	 */
	public void dissimulationLSB(BitSet bIn, String pattern)
	{	
		int pass = 0;
		boolean firstTime = true;
		
		if(pattern.equals("Direct"))
		{
			int z = 0;
			
			for(int i = 0; i < bIn.length(); i++)
			{
				if(pass == 0)
				{
					setDissimulation(bIn, image.getRedArray(), i, z);
					if(z == image.getRedArray().length - 1) pass = 1;
				}
				
				else if(pass == 1)
				{
					if(firstTime == true)
					{
						z = 0;
						firstTime = false;
					}
					setDissimulation(bIn, image.getGreenArray(), i, z);
					if(z == image.getGreenArray().length - 1) 
					{
						pass = 2;
						firstTime = true;
					}
				} 
				
				else if(pass == 2)
				{
					if(firstTime == true)
					{
						z = 0;
						firstTime = false;
					}
					setDissimulation(bIn, image.getBlueArray(), i, z);
				}
				
			    z++;
			}
			System.out.println("J'ai fais en direct");
		}
		else if(pattern.equals("Inverse"))
		{
			int z = image.getRedArray().length - 1;
			for(int i = 0; i < bIn.length(); i++)
			{
				if(pass == 0)
				{
					setDissimulation(bIn, image.getRedArray(), i, z);
					if(z == 0) pass = 1;
				}
				else if(pass == 1)
				{
					if(firstTime == true)
					{
						z = image.getGreenArray().length - 1;
						firstTime = false;
					}
					setDissimulation(bIn, image.getGreenArray(), ++i, z);
					if(z == 0) 
					{
						pass = 2;
						firstTime = true;
					}
	
				} 
				else if(pass == 2)
				{
					if(firstTime == true)
					{
						z = image.getBlueArray().length - 1;
						firstTime = false;
					}
					setDissimulation(bIn, image.getBlueArray(), ++i, z);
	
				}
				
				z--;
			}
			System.out.println("J'ai fais en inverse");
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
	 * @param s string to hide
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
