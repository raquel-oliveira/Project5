package matrice;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;

import javax.imageio.ImageIO;
import javax.swing.JOptionPane;

public class ImageRGB {

	private BufferedImage image;
	private int width, height;
	private int[] red;
	private int[] blue;
	private int[] green;
	
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
		int z=0;
		for(int i =0; i < height ; i++) {
			for (int j = 0; j < width; j++) {
				Color pxcolor = new Color(this.getImageBuff().getRGB(j,i)); // Store in pxcolor the RGB color of the pixel(j,i)
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
	public void setRedArray(int[] red)
	{
		this.red = red;
	}
	public int[] getBlueArray()
	{
		return blue;
	}
	public void setBlueArray(int[] blue)
	{
		this.blue = blue;
	}
	public int[] getGreenArray()
	{
		return green;
	}
	public void setGreenArray(int[] green)
	{
		this.green = green;
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
