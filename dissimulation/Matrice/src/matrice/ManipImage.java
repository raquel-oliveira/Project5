package matrice;

import java.awt.image.BufferedImage;

import java.awt.Color;

import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JOptionPane;
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
	 *  Fills an array of Int with Red or Blue or Green colors from each pixels
	 * @param array to fill
	 * @param color to choose
	 */
	public void getPixelsColor(String color)
	{
		int z = 0;
		
		for(int i = 0; i < image.getHeight() - 1; i++)
		{
			for(int j = 0; j < image.getWidth() - 1; j++)
			{
				Color pxcolor= new Color(image.getImageBuff().getRGB(j, i)); // Store in pxcolor the RGB color of the pixel(j,i)
				if(color.equals("red")) image.getRedArray()[z] = pxcolor.getRed(); // Gets the Red of the color
				if(color.equals("blue")) image.getBlueArray()[z] = pxcolor.getBlue(); // Gets the blue
				if(color.equals("green")) image.getGreenArray()[z] = pxcolor.getGreen(); // Gets the green
				z++;
			}
			z++;
		}
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
			z++;
		}
		ImageIO.write(image.getImageBuff(), "png", new File("sortie2.png")); // Writes a new image in the storage
	}
	
	/**
	 * Makes the image negative.
	 * @param array red
	 * @param array blue
	 * @param array green
	 */
	public void goToNegative()
	{
		int z = 0;
		
		for(int i = 0; i < image.getWidth() - 1; i++)
		{
			for(int j = 0; j < image.getHeight() - 1; j++) // Reverse each values of RGB arrays
			{
				image.getRedArray()[z] = Math.abs(image.getRedArray()[z] - 255);
				image.getBlueArray()[z] = Math.abs(image.getBlueArray()[z] - 255); 
				image.getGreenArray()[z] = Math.abs(image.getGreenArray()[z] - 255); 
				z++;
			}
			z++;
		}
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
				this.setProperBit(bIn,this.getImageRGB().getRedArray(), i, z);
			}
			if(i < bIn.length() -1)
			{
				this.setProperBit(bIn,this.getImageRGB().getGreenArray(), ++i, z);

			} 
			if(i < bIn.length() -1)
			{
				this.setProperBit(bIn,this.getImageRGB().getBlueArray(), ++i, z);

			}
			
			z++;
		}
	}
	public void setProperBit(BitSet  input,int [] cctable, int i, int z){
		if(!input.get(i) && !isNbEven(cctable[z])) cctable[z] -= 1; // Si le bit est false et que le LSB actuel est 1,on met à 0 le LSB
		else if (input.get(i) && isNbEven(cctable[z])) // Si le bit est true et que le LSB actuel est 0, on met à 1 le LSB de red
		{
			if(cctable[z] == 0) cctable[z] += 1; // Si on a le LSB = 0, on incrémente au lieu de décrémenter
			else cctable[z] -= 1;
		}
	}
	public boolean isNbEven(int x)
	{
		if(x % 2 == 0) return true;
		return false;
	}

	public ImageRGB getImageRGB(){
		return this.image;
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
}
