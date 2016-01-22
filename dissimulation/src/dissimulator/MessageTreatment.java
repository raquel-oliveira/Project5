package dissimulator;
import java.io.BufferedReader;

import java.io.FileReader;
import java.io.IOException;
import java.util.BitSet;

public class MessageTreatment {

	/**
	 * This method takes a string as an argument, 
	 * and returns a BitSet containing the binary values of the characters of the string. 
	 * 
	 * @param chaine
	 * @return BitSet
	 */
	public BitSet ChaintoBinary(String chaine){
		byte[] bytes = chaine.getBytes(); 			//récupération des bytes correspondants a la chaine de caractères.
		BitSet bs = BitSet.valueOf(bytes); 			//Passage de byte[] à BitSet (une liste de valeurs booléennes)
		BitSet bsret = new BitSet(chaine.length()*8);
		int z=0;
		for(int i=0, j=7; j<=bs.length(); i+=8, j+=8 ){ //Le bitset ne mettant pas les bits dans l'ordre naturel de lecture, on les inverse 8 par 8
			BitSet carac = bs.get(i, j);
			for (int k = 7; k>=0; k--){
				if(carac.get(k))
					bsret.set(z);
				z++;
			}
		}
		return bsret;
	}
	
	/**
	 * Gets the number of iterations of all the letters in the message. Sorts the string by ascending order
	 * @param message
	 * @return the string like this "a:1,b:2,j:3"
	 */
	public String getNbIterations(String message)
	{
		String temp = "";
		char character;
		int count = 0;
		while(!message.isEmpty())
		{
			character = message.charAt(0);
			count = message.length() - message.replace(String.valueOf(character), "").length();
			message = message.replace(String.valueOf(character), "");  // Erase every 'a' for example
			temp += character + ":" + Integer.toString(count);
			if(!message.isEmpty()) temp += ",";
		}
		return sortByAscendingOrder(temp);
	}
	 /**
	  * Gets a string containing the return string of getNbIterations in order to order by ascending frequencies
	  * @param occurences
	  * @return occurences sorted by ascending frequencies
	  */
	private String sortByAscendingOrder(String occurences)
	{
		String temp = "";
		int frequency = 20000, position = 0;
		occurences = occurences.replace(",", "");
		while(!occurences.isEmpty())
		{
			for(int i = 0; i < occurences.length(); i++) // Searching for the lowest frequency
			{
				if(occurences.charAt(i) == ':' && Character.getNumericValue(occurences.charAt(i+1)) < frequency) 
				{
					frequency = Character.getNumericValue(occurences.charAt(i+1));
					position = i;
				}
			}
			frequency = 20000;
			temp += occurences.charAt(position-1) + ":" + occurences.charAt(position+1); // Ajout de x:y à temp
			occurences = occurences.replace(occurences.charAt(position-1) + ":" + occurences.charAt(position+1), ""); // Supression de x:y dans occurences
			if(!occurences.isEmpty()) temp += ','; // Doesn't put a comma at the end of the ordered string
		}
		return temp;
	}
	
	public String whetherFileOrText(String message, MagicNumberTester mnt) throws IOException, Exception
	{
		if(message.endsWith(".txt")) {
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
		}
		
		return message;
	}
}
