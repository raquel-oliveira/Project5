package matrice;

import java.awt.image.BufferedImage;
import java.awt.Color;
import java.awt.image.DataBuffer;
import java.awt.image.DataBufferByte;
import java.awt.image.Raster;
import java.awt.image.SampleModel;
import java.io.File;

import javax.imageio.ImageIO;
import javax.swing.JOptionPane;

// @author Charly

public class ManipMatrice {
	
	BufferedImage image;
	int width, height;
	
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
	private void getPixelsColor(int[] tab, String color)
	{
		int z = 0;
		
		for(int i = 0; i < height - 1; i++)
		{
			for(int j = 0; j < width - 1; j++)
			{
				Color pxcolor= new Color(image.getRGB(j, i));
				if(color.equals("red")) tab[z] = pxcolor.getRed();
				if(color.equals("blue")) tab[z] = pxcolor.getBlue();
				if(color.equals("green")) tab[z] = pxcolor.getGreen();
				z++;
			}
			z++;
		}
	}
	private int getWidth()
	{
		return width;
	}
	private int getHeight()
	{
		return height;
	}
	
	public static void main(String[] args)
	{
		ManipMatrice mat = new ManipMatrice("fagoon-cartman-10536.png");
		
		int[] red = new int[mat.getWidth() * mat.getHeight()];
		int[] blue = new int[mat.getWidth() * mat.getHeight()];
		int[] green = new int[mat.getWidth() * mat.getHeight()];
		
		int z = 0;
		
		mat.getPixelsColor(red, "red");
		mat.getPixelsColor(blue, "blue");
		mat.getPixelsColor(green, "green");
		
		for(int i = 0; i < mat.getWidth(); i++)
		{
			for(int j = 0; j < mat.getHeight(); j++)
			{
				System.out.println(blue[z]);
				z++;
			}
			z++;
		}
	}

}
