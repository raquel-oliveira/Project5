package matrice;

import java.io.IOException;
import java.util.BitSet;

public class Main {

	public static void main(String[] args) throws IOException
	{
		String s = "fagoon-cartman-10536.png";
		String sortie = "toc.png";
		
		ManipImage manipMat = new ManipImage(s);
		TextToBinary t = new TextToBinary();
		
		BitSet b = t.ChaintoBinary("Comment ca va ?");
		
		manipMat.dissimulationLSB(b, "Inverse");
		
		manipMat.setPixelsColor(sortie);	
	}
}
