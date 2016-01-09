package dissimulator;

import java.io.IOException;
import java.util.BitSet;

public class Main {
	
	public static void main(String[] args) throws IOException, Exception
	{
		Arguments arg = new Arguments(args);
		
		String in = arg.getArg("fileIn") + ".png";
		String out = arg.getArg("fileOut") + ".png";
		String message = "B";
		
		/*for(int g = 0; g < 18600; g++)
		{
			message += "k";
		}*/

		message += "HELP";
		
		ManipImage manipMat = new ManipImage(in);
		TextToBinary t = new TextToBinary();
		
		BitSet b = t.ChaintoBinary(message);
		
		try
		{ 
			manipMat.dissimulationLSB(b, Integer.parseInt(arg.getArg("nbBits")), arg.getArg("pattern"));
		}
		catch(InvalidArgumentException e)
		{
			System.out.println(e.getMessage());
		}
		catch(EmptyArgumentException e)
		{
			System.out.println(e.getMessage());
		}

		manipMat.setPixelsColor(out);
		
		for(int k = manipMat.getRedArray().length - 1; k > manipMat.getRedArray().length - 46; k--)
		{
			for(int l = 0; l < 8; l++)
			{
				System.out.print(manipMat.getBinary8(manipMat.getRedArray()[k])[l]);
			}
			System.out.print(" ");
		}
		
		
		/*for (int i = 0; i < 100; i++) 
		{
			System.out.print(manipMat.getRedArray()[i]);
		}*/
		
		
		/*MagicNumberTester mnt = new MagicNumberTester();

		if(mnt.doesStringContainMN(message))
		{
			System.out.println("Chaine de charactères non-valide : le message contient le mot magique");
		}
		else {
			message += "HELP";

			

			manipMat.dissimulationLSB(b, arg.getArg("pattern"));

			manipMat.setPixelsColor(out);

			
		}*/
	}
}
