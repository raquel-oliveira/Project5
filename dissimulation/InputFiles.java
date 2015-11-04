package io;

import java.awt.image.BufferedImage;
import java.awt.image.Raster;
import java.awt.image.DataBufferByte;
import java.awt.image.WritableRaster;
import java.io.File;
import java.util.Arrays;

import javax.imageio.ImageIO;
import javax.swing.JOptionPane;
/**
 * 
 * @author Raquel
 *
 */
public class InputFiles {
	/*
	 *Return an image file
	 *@param f The complete path name of the image.
	 *@return image The image read.
	 */
	private BufferedImage getImage(String f)
	{
		BufferedImage image	= null;
		File file = new File(f);
		try{
			image = ImageIO.read(file);
		}
		catch(Exception ex){
			JOptionPane.showMessageDialog(null, 
				"Image could not be read!","Error",JOptionPane.ERROR_MESSAGE);
		}
		return image;
	}
	
	/*
	 *Get the byte array of an image
	 *@param image The image to get byte data from
	 *@return Returns the byte array of the image given
	 */
	private void get_byte_data(BufferedImage image)
	{
		Raster raster   = image.getRaster();
		raster.toString();
		//DataBufferByte buffer = raster.getDataBuffer();
		//return buffer.getData();
	}
	
	/*
	 *Generates proper byte format of an integer (only using 4 bytes)
	 *@param i The integer to convert
	 *@return Returns a byte[4] array converting the supplied integer in to bytes
	 */
	private byte[] bit_conversion(int i)
	{
		byte byte3 = (byte)((i & 0xFF000000) >>> 24); 
		byte byte2 = (byte)((i & 0x00FF0000) >>> 16); 
		byte byte1 = (byte)((i & 0x0000FF00) >>> 8 ); 
		byte byte0 = (byte)((i & 0x000000FF)	   );
		
		return(new byte[]{byte3,byte2,byte1,byte0});
	}
	
	public static void main(String[] args)
	{
		InputFiles image = new InputFiles();
		BufferedImage i;
		byte[] c;
		
		i = image.getImage("obama_sprite.jpg");
		image.get_byte_data(i);

		//System.out.println("bla");
		
	}
	
}
