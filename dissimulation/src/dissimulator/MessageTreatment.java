package dissimulator;
import java.io.BufferedReader;


import java.io.FileReader;
import java.io.IOException;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;


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
		HashMap<Character, Integer> frequencies = new HashMap<>();
		char character;
		int count = 0;
		for(int i = 0; i < message.length(); i++)
		{
			character = message.charAt(i);
			if(!frequencies.containsKey(character))
			{
				frequencies.put(character, 1);
			}
			else
			{
				int nb = frequencies.get(character);
				frequencies.put(character, nb+1);
			}
		}
		String strFinal = sortByAscendingOrder(frequencies);
		return strFinal;
	}
	 /**
	  * Gets a string containing the return string of getNbIterations in order to order by ascending frequencies
	  * @param occurences
	  * @return occurences sorted by ascending frequencies
	  */
	private String sortByAscendingOrder(HashMap<Character, Integer> frequencies)
	{
		String temp = "{";
		char cleInf = '0';
		
		while(!frequencies.isEmpty())
		{
			int valeurInf = Integer.MAX_VALUE;
			for(Entry<Character, Integer> entry : frequencies.entrySet()) 
			{
			    char cle = entry.getKey();
			    int valeur = entry.getValue();
			    if(valeur < valeurInf)
			    {
			    	cleInf = cle;
			    	valeurInf = valeur;
			    }
			}
			frequencies.remove(cleInf);
			temp += cleInf + ":" + Integer.toString(valeurInf) + ", ";
		}
		temp = temp.substring(0, temp.length()-2);
		temp += '}';
		
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
