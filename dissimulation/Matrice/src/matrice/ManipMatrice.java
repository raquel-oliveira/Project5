package matrice;

import java.awt.image.BufferedImage;

import java.awt.Color;

import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JOptionPane;
import java.util.BitSet;

// @author Charly

public class ManipMatrice {
	
	BufferedImage image;
	int width, height;
	
	/**
	 * Constructs a BufferedImage. Get width and height from the image.
	 * @param Path to file
	 */
	private ManipMatrice(String f)
	{
		File file = new File(f);
		try{
			image = ImageIO.read(file);
		}
		catch(Exception ex){
			JOptionPane.showMessageDialog(null, 
				"Image could not be read!","Error",JOptionPane.ERROR_MESSAGE);
		}
		height = image.getHeight();
		width = image.getWidth();
	}
	
	/**
	 *  Fills an array of Int with Red or Blue or Green colors from each pixels
	 * @param array to fill
	 * @param color to choose
	 */
	private void getPixelsColor(int[] tab, String color)
	{
		int z = 0;
		
		for(int i = 0; i < height - 1; i++)
		{
			for(int j = 0; j < width - 1; j++)
			{
				Color pxcolor= new Color(image.getRGB(j, i)); // Store in pxcolor the RGB color of the pixel(j,i)
				if(color.equals("red")) tab[z] = pxcolor.getRed(); // Gets the Red of the color
				if(color.equals("blue")) tab[z] = pxcolor.getBlue(); // Gets the blue
				if(color.equals("green")) tab[z] = pxcolor.getGreen(); // Gets the green
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
	private void setPixelsColor(int[] red, int[] blue, int[] green) throws IOException
	{
		int z = 0;
		
		for(int i = 0; i < height - 1; i++)
		{
			for(int j = 0; j < width - 1; j++)
			{
				int rgb = new Color(red[z], green[z], blue[z]).getRGB(); // Creates a new color from the colors given to the method 
		        image.setRGB(j, i, rgb); // Sets the pixel(j,i) with the new color
				z++;				
			}
			z++;
		}
		ImageIO.write(image, "png", new File("sortie.jpg")); // Writes a new image in the storage
	}
	
	/**
	 * Make the image negative.
	 * @param array red
	 * @param array blue
	 * @param array green
	 */
	private void goToNegative(int red[], int blue[], int green[])
	{
		int z = 0;
		
		for(int i = 0; i < width - 1; i++)
		{
			for(int j = 0; j < height - 1; j++) // Reverse each values of RGB arrays
			{
				red[z] = Math.abs(red[z] - 255);
				blue[z] = Math.abs(blue[z] - 255); 
				green[z] = Math.abs(green[z] - 255); 
				z++;
			}
			z++;
		}
	}
	
	/**
	 * Prints out the number of bits available for hiding. Prints out the number of bits to hide (s)
	 * @param string to hide
	 */
	private void nbBitsAvailable(String s)
	{
		System.out.println("Nombre maximum de bits disponibles : " + (width * height * 3));
		System.out.println("Nombre de bits à cacher : " + (s.length() * 8));
	}
	
	/**
	 * Change each bytes's last bit of RGB colors, with selection from the user of the colors.
	 * Put null to the non-wanted array(s) color
	 * @param array of byte from the string to hide
	 * @param Array red
	 * @param Array blue
	 * @param Array green
	 */
	private void dissimulationLSB(String sIn, int red[], int blue[], int green[])
	{
		int z = 7;
		
		for(int i = 0; i < sIn.length(); i++)
		{
			if(red != null && i < sIn.length()) // Si on a selectionné la couleur Red et qu'on est pas au bout de la chaine
			{
				if(sIn.codePointAt(i) == 48) red[z] = 0; // Si le caractère est un 0, on met un 0 dans le LSB de red
				else red[z] = 1;
			}
			if(blue != null && i < sIn.length() -1)
			{
				if(sIn.codePointAt(++i) == 48) blue[z] = 0;
				else blue[z] = 1;
			} 
			if(green != null && i < sIn.length() -1)
			{
				if(sIn.codePointAt(++i) == 48) green[z] = 0;
				else green[z] = 1;
			}
			
			z += 8;
		}
		
		
	}
	private boolean isNbEven(int x)
	{
		if(x % 2 == 0) return true;
		return false;
	}
	
	private int getWidth()
	{
		return width;
	}
	private int getHeight()
	{
		return height;
	}
	
	public static void main(String[] args) throws IOException
	{
		ManipMatrice mat = new ManipMatrice("fagoon-cartman-10536.png");
		
		int[] red = new int[mat.getWidth() * mat.getHeight()];
		int[] blue = new int[mat.getWidth() * mat.getHeight()];
		int[] green = new int[mat.getWidth() * mat.getHeight()];
		
		mat.getPixelsColor(red, "red");
		mat.getPixelsColor(blue, "blue");
		mat.getPixelsColor(green, "green");
		
		TextToBinary c = new TextToBinary();
		String x = c.StringtoBinaryString("Bonjour");
		
		mat.dissimulationLSB(x, red, blue, green);
		
		mat.setPixelsColor(red, blue, green);
		
		for(int i = 0; i < 100; i++)
		{
			System.out.println(blue[i]);
		}
	}
}
