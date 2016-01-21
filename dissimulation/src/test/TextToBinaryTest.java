package test;
import dissimulator.Compressor;
import dissimulator.MessageTreatment;
import org.junit.Test;

import java.util.BitSet;



import static org.junit.Assert.assertTrue;

/**
 * Created by Paul Bertot on 1/6/16.
 */
public class TextToBinaryTest {

    @Test
    public void ChaintoBinaryTest(){
        MessageTreatment ttb = new MessageTreatment();
        String stringTest = "Salut";
        BitSet b = ttb.ChaintoBinary(stringTest);
        
        byte[] array = stringTest.getBytes();
        stringTest = "";
        for(int i = 0; i < array.length; i++)
    	{
    		stringTest += String.format("%8s", Integer.toBinaryString(array[i] & 0xFF)).replace(' ', '0');
    		if(i != array.length - 1) stringTest += " ";
    	}
        
        String stringTest2 = "";
        for(int i = 0; i < b.length() - 1; i++)
        {
        	if(i%8 == 0 && i != 0) stringTest2 += " ";
        	if(b.get(i)) stringTest2 += "1";
        	else stringTest2 += "0";
        }

        assertTrue(stringTest.equals(stringTest2));
    }




}
