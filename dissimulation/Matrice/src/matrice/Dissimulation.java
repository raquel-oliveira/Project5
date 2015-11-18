package matrice;

import java.util.BitSet;

public class Dissimulation {

	ImageRGB image;
	
	public Dissimulation(ImageRGB image)
	{
		this.image = image;
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
				if(!bIn.get(i) && !isNbEven(image.getRedArray()[z])) image.getRedArray()[z] -= 1; // Si le bit est false, on met un 0 dans le LSB de red
				else if (bIn.get(i) && isNbEven(image.getRedArray()[z])) 
				{
					if(image.getRedArray()[z] == 0) image.getRedArray()[z] += 1;
					else image.getRedArray()[z] -= 1;
				}
			}
			if(i < bIn.length() -1)
			{
				if(!bIn.get(++i) && !isNbEven(image.getGreenArray()[z])) image.getGreenArray()[z] -= 1; // Si le bit est false, on met un 0 dans le LSB de red
				else if (bIn.get(i) && isNbEven(image.getGreenArray()[z]))
				{
					if(image.getGreenArray()[z] == 0) image.getGreenArray()[z] += 1;
					else image.getGreenArray()[z] -= 1;
				}
			} 
			if(i < bIn.length() -1)
			{
				if(!bIn.get(++i) && !isNbEven(image.getBlueArray()[z])) image.getBlueArray()[z] -= 1; // Si le bit est false, on met un 0 dans le LSB de red
				else if (bIn.get(i) && isNbEven(image.getBlueArray()[z]))
				{
					if(image.getBlueArray()[z] == 0) image.getBlueArray()[z] += 1;
					else image.getBlueArray()[z] -= 1;
				}
			}
			
			z++;
		}
	}
	public boolean isNbEven(int x)
	{
		if(x % 2 == 0) return true;
		return false;
	}
	
}
