package matrice;

import java.awt.image.BufferedImage;
import java.io.File;

import javax.imageio.ImageIO;
import javax.swing.JOptionPane;

public class Matrice {

	BufferedImage image;
	int width, height;
	int[] red;
	int[] blue;
	int[] green;
	
	public Matrice(String f)
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
}
