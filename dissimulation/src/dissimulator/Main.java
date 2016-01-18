package dissimulator;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.BitSet;

public class Main {
	
	public static void main(String[] args) throws IOException, Exception {
		//Récupération des arguments, et utilisation
		Arguments arg = new Arguments(args);
		Metrics met = new Metrics();
		//met.setMetric(arg.getArg("metrics"));
		MessageTreatment t = new MessageTreatment();
		
		String in = arg.getArg("fileIn");
		String out = arg.getArg("fileOut");
		String message = arg.getArg("message");
		String[] colors = new String[3];

		//Vérification du message pour le nombre magique
		MagicNumberTester mnt = new MagicNumberTester(arg.getArg("magic"));

		if (message.endsWith(".txt")) {
			BufferedReader br = new BufferedReader(new FileReader(message));
			try {
				StringBuilder sb = new StringBuilder();
				String line = br.readLine();

				while (line != null) {
					sb.append(line);
					sb.append("");
					line = br.readLine();
				}
				message = sb.toString();
			} finally {
				br.close();
			}
			if (mnt.doesStringContainMN(message)) {
				throw new MagicNumberException("Le contenu de ce fichier texte contient le mot magique");
			} else {
				message += mnt.hexStringtoString();
			}
		}
		else {
			if(mnt.doesStringContainMN(message)) {
				throw new MagicNumberException("Ce message contient le nombre magique");
			}else{
				message += mnt.hexStringtoString();
			}
		}
		
		ManipImage manipMat = new ManipImage(in);
        
        //Conversion du message en BitSet.
		
		BitSet b = t.ChaintoBinary(message);
		
		// Traitement des couleurs
		
		String channels = arg.getArg("channels"), temp = "";
		
		for(int i = 0, cpt = 0; i < channels.length(); i++)
		{
			temp += channels.charAt(i);
			if(temp.equals("red") || temp.equals("green") || temp.equals("blue"))
			{
				colors[cpt++] = temp;
				temp = "";
			}
		}
		int nbColorsNotNull;
		if(colors[1] == null && colors[2] == null) nbColorsNotNull = 1;
		else if(colors[1] != null && colors[2] == null) nbColorsNotNull = 2;
		else nbColorsNotNull = 3;
		
		if(((message.length() + arg.getArg("magic").length()) * 8  / Integer.parseInt(arg.getArg("nbBits"))) > 
			(manipMat.getImage().getWidth() * nbColorsNotNull * manipMat.getImage().getHeight())) 
			throw new InvalidArgumentException("Message + magic number do not fit in the image");
		
		try
		{ 
			manipMat.dissimulationLSB(b, Integer.parseInt(arg.getArg("nbBits")), arg.getArg("pattern"), colors);
		}
		catch(InvalidArgumentException | EmptyArgumentException e)
		{
			System.out.println(e.getMessage());
		}	
		
		manipMat.setPixelsColor(out, arg.getArg("formatIn"), arg.getArg("formatOut"));
	}
}
