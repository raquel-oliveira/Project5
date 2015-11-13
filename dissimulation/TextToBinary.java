package matrice;

import java.util.Arrays;
import java.util.BitSet;



public class TextToBinary {

	/**
	 * This method takes a string as an argument, 
	 * and returns a string containing the binary values of the characters of the string. 
	 * 
	 * @param chaine
	 * @return BitSet
	 */
	public  BitSet ChaintoBinary(String chaine){
		byte[] bytes = chaine.getBytes();
		BitSet bs = BitSet.valueOf(bytes);
		return bs;
	}

	/**
	 * This method takes a byte Array
	 * and returns a  string.
	 * 
	 * 
	 * @param BitSet
	 * @return text
	 */
	public String BinarytoString(BitSet bs){
		String ret;
		byte[] bc = bs.toByteArray();
		ret = new String(bc);
		return ret;

	}

	public String StringtoBinaryString(String s){
		byte[] bytes = s.getBytes();
		StringBuilder binary = new StringBuilder();
		for(byte b : bytes){
			int val = b;
			for(int i =0; i<8; i++){
				binary.append((val & 128) == 0 ? 0 :1);
				val <<= 1;
			}
		}
		return binary.toString();
	}

	public static void main(String args[]){
		String s = "Bonjour les amis, vous voulez qqchose à boire?";
		System.out.println(s);
		TextToBinary ttb = new TextToBinary();
		BitSet sb = ttb.ChaintoBinary(s);
		System.out.println(sb.toString());
		String res = ttb.BinarytoString(sb);
		System.out.println(res);

	}

}
