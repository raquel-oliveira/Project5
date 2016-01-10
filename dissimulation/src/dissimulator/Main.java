package dissimulator;

import java.io.IOException;
import java.util.BitSet;

public class Main {
	
	public static void main(String[] args) throws IOException, Exception
	{
        //Récupération des arguments, et utilisation
        Arguments arg = new Arguments(args);
		Metrics met = new Metrics();
		met.setTime();
		
        String in = arg.getArg("fileIn");
        String out = arg.getArg("fileOut");
        String message = arg.getArg("message");

        //Vérification du message pour le nombre magique
        MagicNumberTester mnt = new MagicNumberTester(arg.getArg("magic"));

		//if(message.startsWith("\"")){



			if (mnt.doesStringContainMN(message)) {
				throw new MagicNumberException("Ce message contient le nombre magique");
			} else {
			message += mnt.hexStringtoString();
			}

		//}
		
		ManipImage manipMat = new ManipImage(in);
        
        //Conversion du message en BitSet.

		MessageToBinary t = new MessageToBinary();
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
		
		/*for(int k = manipMat.getRedArray().length - 1; k > manipMat.getRedArray().length - 46; k--)
		{
			for(int l = 0; l < 8; l++)
			{
				System.out.print(manipMat.getBinary8(manipMat.getRedArray()[k])[l]);
			}
			System.out.print(" ");
		}*/
		
		met.nbBitsImpacted(message, manipMat.getImage());
		System.out.println("Temps d'exécution de la dissimulation : " + met.getTime());
	}
}
