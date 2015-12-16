package dissimulator;

import java.io.IOException;
import java.util.BitSet;

public class Main {
	
	public static void main(String[] args) throws IOException, Throwable
	{
		Arguments arg = new Arguments(args);
		
		String in = "resources/fagoon-cartman-10536.png";
		String out = arg.getArg("fileOut");
		String message = "Bla bla hi hi oi";
		message += "HEL";
		
		ManipImage manipMat = new ManipImage(in);
		TextToBinary t = new TextToBinary();
		
		BitSet b = t.ChaintoBinary(message);
	
		try
		{ 
			manipMat.dissimulationLSB(b, arg.getArg("pattern"));
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
		
		manipMat.nbBitsImpacted(message);
		
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
