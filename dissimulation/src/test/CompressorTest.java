package test;
import dissimulator.Compressor;
import dissimulator.MagicNumberTester;
import dissimulator.PredefinedDictionnary;
import org.junit.Test;

import java.util.BitSet;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

/**
 * Created by Paul on 1/20/16.
 */
public class CompressorTest {
	
    @Test
    public void singleLetterCompressionTest()
    {
        BitSet ctrl = new BitSet();
        ctrl.set(9);ctrl.set(10);ctrl.set(11);ctrl.set(13);
        ctrl.set(22);ctrl.set(25);ctrl.set(37);ctrl.set(38);
        ctrl.set(41);ctrl.set(43);ctrl.set(45);


        PredefinedDictionnary prd = new PredefinedDictionnary();
        Compressor comp = new Compressor(prd.getDicoCode(),prd.getDicoLength());
        byte[] msg = comp.messageCompression("ttt");
        BitSet bmsg = BitSet.valueOf(msg);

        assertEquals(ctrl, bmsg);
        assertEquals(6,msg.length);
    }
    
    @Test 
    public void severalBytesCompressedTest()
    {
    	String message = "all";
    	PredefinedDictionnary prd = new PredefinedDictionnary();
        Compressor compressor = new Compressor(prd.getDicoCode(),prd.getDicoLength());
        MagicNumberTester mnt = new MagicNumberTester();
    	byte[] array1 = compressor.messageCompression(message);
    	String stringTest = "";
    	for(int i = 0; i < array1.length; i++)
    	{
    		array1[i] = Compressor.reverseByte(array1[i]);
    		stringTest += String.format("%8s", Integer.toBinaryString(array1[i] & 0xFF)).replace(' ', '0');
    		if(i != array1.length - 1) stringTest += " ";
    	}
    	String bits = "00000001 01100001 00000011 11100000 01101100 00000011 00100000 00000001 11100100 10000000";
    	assertTrue(stringTest.equals(bits));
    }
}
