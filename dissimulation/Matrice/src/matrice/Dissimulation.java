package matrice;

public class Dissimulation {

	int[] red;
	int[] blue;
	int[] green;
	
	public Dissimulation(int[] red, int[] blue, int[] green)
	{
		this.red = red;
		this.blue = blue;
		this.green = green;
	}
	
	/**
	 * Change each bytes's last bit of RGB colors, with selection from the user of the colors.
	 * Put null to the non-wanted array(s) color
	 * @param array of byte from the string to hide
	 * @param Array red
	 * @param Array blue
	 * @param Array green
	 */
	public void dissimulationLSB(String sIn)
	{
		int z = 7;
		
		for(int i = 0; i < sIn.length(); i++)
		{
			if(red != null && i < sIn.length()) // Si on a selectionné la couleur Red et qu'on est pas au bout de la chaine
			{
				if(sIn.codePointAt(i) == 48) red[z] = 0; // Si le caractère est un 0, on met un 0 dans le LSB de red
				else red[z] = 1;
			}
			if(green != null && i < sIn.length() -1)
			{
				if(sIn.codePointAt(++i) == 48) green[z] = 0;
				else green[z] = 1;
			} 
			if(blue != null && i < sIn.length() -1)
			{
				if(sIn.codePointAt(++i) == 48) blue[z] = 0;
				else blue[z] = 1;
			}
			
			z += 8;
		}
	}
	
}
