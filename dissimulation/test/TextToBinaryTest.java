import dissimulator.MessageToBinary;
import org.junit.Test;

import java.util.BitSet;

import static org.junit.Assert.assertTrue;

/**
 * Created by Paul Bertot on 1/6/16.
 */
public class TextToBinaryTest {

    @Test
    public void ChaintoBinaryTest(){
        MessageToBinary ttb = new MessageToBinary();
        BitSet bsc = new BitSet(32);
        bsc.set(1); bsc.set(4);bsc.set(9);
        bsc.set(13); bsc.set(15);bsc.set(17);
        bsc.set(20); bsc.set(21);bsc.set(25);
        bsc.set(27);
        assertTrue(bsc.equals(ttb.ChaintoBinary("HELP")));
    }




}
