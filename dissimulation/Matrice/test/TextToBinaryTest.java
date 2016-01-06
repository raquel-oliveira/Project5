import dissimulator.TextToBinary;
import org.junit.Test;

import java.util.BitSet;

import static org.junit.Assert.assertTrue;

/**
 * Created by Paul Bertot on 1/6/16.
 */
public class TextToBinaryTest {

    @Test
    public void ChaintoBinaryTest(){
        TextToBinary ttb = new TextToBinary();
        BitSet bsc = new BitSet(8);
        bsc.set(1); bsc.set(2);bsc.set(5);
        assertTrue(bsc.equals(ttb.ChaintoBinary("d")));
    }




}
