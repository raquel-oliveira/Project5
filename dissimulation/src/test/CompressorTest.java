package test;
import dissimulator.Compressor;

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
    public void singleLetterCompressionTest(){
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
}
