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
	 * @param array of byte from the string to hide
	 * @param Array red
	 * @param Array blue
	 * @param Array green
	 */
	public void dissimulationLSB(BitSet bIn)
	{
		int z = 7;
		
		for(int i = 0; i < bIn.length(); i++)
		{
			if(image.getRedArray() != null && i < bIn.length()) // Si on a selectionné la couleur Red et qu'on est pas au bout du BitSet
			{
				if(!bIn.get(i)) image.getRedArray()[z] = 0; // Si le bit est false, on met un 0 dans le LSB de red
				else image.getRedArray()[z] = 1;
			}
			if(image.getGreenArray() != null && i < bIn.length() -1)
			{
				if(!bIn.get(++i)) image.getGreenArray()[z] = 0;
				else image.getGreenArray()[z] = 1;
			} 
			if(image.getBlueArray() != null && i < bIn.length() -1)
			{
				if(!bIn.get(++i)) image.getBlueArray()[z] = 0;
				else image.getBlueArray()[z] = 1;
			}
			
			z += 8;
		}
	}
	
}
