package dissimulator;

import java.awt.image.BufferedImage;

import java.awt.Color;

import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import java.util.BitSet;

// @author Charly Lafon

public class ManipImage {
	
	private ImageRGB image;
	private String magicword;
	
	/**
	 * Constructs a BufferedImage. Get width and height from the image.
	 * @param Path to file
	 */
	public ManipImage(String in)
	{
		image = new ImageRGB(in);
		this.magicword = "HELP";
	}
	
	/**
	 * Create a new image with the new RGB colors.
	 * @param array red
	 * @param array blue
	 * @param array green
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
	 * Change each bytes's nbBits bit(s) of RGB colors, with selection from the user of the colors.
	 * @param bitset from the string to hide
	 * @param nbBits number of bits to change at each byte
	 * @param pattern which pattern to use when hiding the message
	 */
	public void dissimulationLSB(BitSet bIn, int nbBits, String pattern)
	{	
		Pattern pat; // Pattern used to navigate through the image
		int pass = 0;
		boolean firstTime = true;
		
		if(pattern.equals("Direct")) pat = new Direct();
		else if(pattern.equals("Reverse")) pat = new Reverse();
		else pat = new Direct(); // Put to avoid an error of non initialization of pat, but it's never the case
		
		int z = pat.initializePosition(image.getRedArray()); // We also could have passed the blue or green array, they all have the same size
			
		for(int i = 0; i < bIn.length(); i++)
		{
			if(pass == 0)
			{
                int j = nbBits;
                while(j != 0)
                {
                 	setDissimulation(bIn, image.getRedArray(), i++, z, j);
                    j--;
                }
                i--; // Reseting the right i for example if nbBits = 1
				if(!pat.hasNext(z, image.getRedArray())) pass = 1;
			}
			else if(pass == 1)
			{
				if(firstTime == true)
				{
					z = pat.initializePosition(image.getGreenArray());
					firstTime = false;
				}
				int j = nbBits;
				while(j != 0)
                {
                    setDissimulation(bIn, image.getGreenArray(), i++, z, j);
                    j--;
                }
                i--; // Reseting the right i for example if nbBits = 1
				if(!pat.hasNext(z, image.getGreenArray())) 
				{
					pass = 2;
					firstTime = true;
				}
			} 
			else if(pass == 2)
			{
				if(firstTime == true)
				{
					z = pat.initializePosition(image.getBlueArray());
					firstTime = false;
				}
				int j = nbBits;
				while(j != 0)
                {
                    setDissimulation(bIn, image.getBlueArray(), i++, z, j);
                    j--;
                }
                i--; // Reseting the right i for example if nbBits = 1
			}
				
			z = pat.nextPosition(z);
		}
	}
    
    public void setDissimulation(BitSet bIn, int[] array, int i, int z, int nbOccurences)
    { 	
    	int[] b = getBinary8(array[z]);
        
        if(!bIn.get(i) && (b[8-nbOccurences] == 1)) b[8-nbOccurences] = 0; // Si le bit est false et que le bit actuel est 1,on met à 0 le bit
            
        else if (bIn.get(i) && (b[8-nbOccurences] == 0)) // Si le bit est true et que le LSB actuel est 0, on met à 1 le LSB de array[z]
        {
             b[8-nbOccurences] = 1;
        }

        int temp = 0;
        for(int j = 0; j < 8; j++)
        {
            temp += b[7-j] * Math.pow(2, j);
        }
        array[z] = temp;
    }
    
    public int[] getBinary8(int a)
    {
        int[] b = new int[8];
        int i = 7;
        
        while(a != 0)
        {
            b[i] = a % 2;
            a /= 2;
            i--;
        }
        
        return b;
    }
	
	/**
	 * Prints out the number of bits available for hiding. Prints out the number of bits to hide (s)
	 * @param string to hide
	 */
	public void nbBitsImpacted(String s)
	{
		System.out.println("\nNombre maximum de bits disponibles : " + (image.getWidth() * image.getHeight() * 3));
		System.out.println("Nombre de bits impactés : " + (s.length() * 8));
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
	public String getMagicword() 
	{
		return magicword;
	}
}
