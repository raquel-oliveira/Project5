package matrice;

import java.io.IOException;
import java.util.BitSet;

public class Main {

	public static void main(String[] args) throws IOException
	{
		ImageRGB img = new ImageRGB("fagoon-cartman-10536.png");
		ManipImage manipMat = new ManipImage(img);
		Dissimulation d = new Dissimulation(img);
		TextToBinary t = new TextToBinary();
		
		BitSet b = t.ChaintoBinary("Comment ca va ?");
		
		manipMat.getPixelsColor("red");
		manipMat.getPixelsColor("blue");
		manipMat.getPixelsColor("green");
		
		d.dissimulationLSB(b);
		
		manipMat.setPixelsColor();
	}
}
