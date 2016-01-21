package dissimulator;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;

import javax.imageio.ImageIO;

public class ImageRGB {

	private BufferedImage image;
	private int width, height;
	private int[] red;
	private int[] blue;
	private int[] green;
	
	/**
	 * Read the image with the path f. Constructs the Red, Green and Blue arrays
	 * @param f path to the image to read
	 */
	public ImageRGB(String f)
	{
		File file = new File(f);
		try{
			image = ImageIO.read(file);
		}
		catch(Exception ex){
			System.out.println("Erreur de lecture de l'image");
		}
		height = image.getHeight();
		width = image.getWidth();
		red = new int[width * height];
		blue = new int[width * height];
		green = new int[width * height];
		
		getPixelsColor();
	}
	
	/**
	 * Gets the RGB colors of each pixel and put them in the corresponding arrays
	 */
	public void getPixelsColor()
	{
		int z = 0;
		
		for(int i = 0; i < height - 1; i++) 
		{
			for (int j = 0; j < width - 1; j++) 
			{
				Color pxcolor = new Color(image.getRGB(j,i)); // Store in pxcolor the RGB color of the pixel(j,i)
				red[z]= pxcolor.getRed();
				green[z] = pxcolor.getGreen();
				blue[z] = pxcolor.getBlue();
				z++;
			}
		}
	}
	public BufferedImage getImageBuff()
	{
		return image;
	}
	public int[] getRedArray()
	{
		return red;
	}
	public int[] getBlueArray()
	{
		return blue;
	}
	public int[] getGreenArray()
	{
		return green;
	}
	public int getHeight()
	{
		return height;
	}
	public int getWidth()
	{
		return width;
	}
}
