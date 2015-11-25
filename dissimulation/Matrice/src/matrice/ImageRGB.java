package matrice;

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
			JOptionPane.showMessageDialog(null, 
				"Image could not be read!","Error",JOptionPane.ERROR_MESSAGE);
		}
		height = image.getHeight();
		width = image.getWidth();
		red = new int[width * height];
		blue = new int[width * height];
		green = new int[width * height];
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
