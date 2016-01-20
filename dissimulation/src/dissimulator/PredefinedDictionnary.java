package dissimulator;

import java.util.HashMap;

public class PredefinedDictionnary {

	HashMap<Character, Integer> dicoCode;
	HashMap<Character, Integer> dicoLength;
	
	public PredefinedDictionnary()
	{
		dicoCode = new HashMap<>();
		dicoLength = new HashMap<>();
		
		dicoCode.put('g', 0);
		dicoCode.put('w', 1);
		dicoCode.put('l', 1);
		dicoCode.put('h', 4);
		dicoCode.put('r', 5);
		dicoCode.put('s', 6);
		dicoCode.put('a', 7);
		dicoCode.put('t', 1);
		
		dicoLength.put('g', 4);
		dicoLength.put('w', 4);
		dicoLength.put('l', 3);
		dicoLength.put('h', 3);
		dicoLength.put('r', 3);
		dicoLength.put('s', 3);
		dicoLength.put('a', 3);
		dicoLength.put('t', 2);
	}
	
	public HashMap<Character, Integer> getDicoCode()
	{
		return dicoCode;
	}
	public HashMap<Character, Integer> getDicoLength()
	{
		return dicoCode;
	}
}
