package dissimulator;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;



public class MessageTreatment {

	/**
	 * This method takes a string as an argument, 
	 * and returns a string containing the binary values of the characters of the string. 
	 * 
	 * @param chaine
	 * @return BitSet
	 */
	public  BitSet ChaintoBinary(String chaine){
		byte[] bytes = chaine.getBytes(); 			//réccupération des bytes correspondant a la chaine de characères.
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
		bsret.set(chaine.length()*8);
		return bsret;
	}

	public BitSet FileToBinary(String filepath){
		BitSet bsret = new BitSet();
		return bsret;
	}
	
	/**
	 * Gets the number of iterations of all the letters in the message. Sorts the string by ascending order
	 * @param message
	 * @return the string like this "a:2,b:1,j:3"
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
			message = message.replace(String.valueOf(character), "");
			temp += character + ":" + Integer.toString(count);
			if(!message.isEmpty()) temp += ",";
		}
		System.out.println(sortByAscendingOrder(temp));
		return sortByAscendingOrder(temp);
	}
	 /**
	  * Gets a string containing the return string of getNbIterations in order to order by ascending frequencies
	  * @param occurences
	  * @return occurences sorted by ascending frequencies
	  */
	private String sortByAscendingOrder(String occurences)
	{
		String temp = "", key = "";
		int frequency = 20000, position = 0;
		occurences = occurences.replace(",", "");
		while(!occurences.isEmpty())
		{
			for(int i = 0; i < occurences.length(); i++)
			{
				if(occurences.charAt(i) == ':' && Character.getNumericValue(occurences.charAt(i+1)) < frequency) 
				{
					frequency = Character.getNumericValue(occurences.charAt(i+1));
					position = i;
				}
			}
			frequency = 20000;
			temp += occurences.charAt(position-1) + ":" + occurences.charAt(position+1) + ",";
			occurences = occurences.replace(occurences.charAt(position-1) + ":" + occurences.charAt(position+1), "");
		}
		return temp;
	}


}