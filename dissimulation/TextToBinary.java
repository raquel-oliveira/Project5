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
		System.out.println(Arrays.toString(bytes));
		BitSet bs = BitSet.valueOf(bytes);
		BitSet bsret = new BitSet();
		int z=0;
		for(int i=0, j=7; j<=bs.length(); i+=8, j+=8 ){
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
			binary.append(' ');
		}
		return binary.toString();
	}

	public static void main(String args[]){
		String s = "bonjour";
		System.out.println(s);
		int val;
		TextToBinary ttb = new TextToBinary();
		BitSet sb = ttb.ChaintoBinary(s);
		for(int i =0; i<=sb.length(); i++){
			/*if (i%8 ==0){
				System.out.println("\n");
			}*/
			val = sb.get(i)? 1 :0;
			System.out.print(val);
			
		}
		//String res = ttb.BinarytoString(sb);
		//System.out.println(res);

	}

}
