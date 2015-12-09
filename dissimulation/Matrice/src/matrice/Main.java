package matrice;

import java.io.IOException;
import java.util.BitSet;

public class Main {
	
	public static void main(String[] args) throws IOException, Throwable
	{
		Arguments arg = new Arguments(args);
		
		String in = "fagoon-cartman-10536.png";
		String out = "toc.png";
		String message = "Bonjour";
		
		ManipImage manipMat = new ManipImage(in);
		TextToBinary t = new TextToBinary();
		MagicNumberTester mnt = new MagicNumberTester();

		if(mnt.doesStringContainMN(message))
		{
			System.out.println("Chaine de charactères non-valide : le message contient le mot magique");
		}
		else {
			message += "HELP";

			BitSet b = t.ChaintoBinary(message);

			manipMat.dissimulationLSB(b, arg.getArg("pattern"));

			manipMat.setPixelsColor(out);

			for (int i = manipMat.getRedArray().length - 1; i > manipMat.getRedArray().length - 100; i--) 
			{
				System.out.print(manipMat.getRedArray()[i]);
			}
		}
	}
}
