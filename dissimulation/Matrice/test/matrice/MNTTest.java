package matrice;

import org.junit.Test;

import java.util.Arrays;

import static junit.framework.TestCase.assertTrue;

/**
 * Created by Paul Bertot on 12/9/15.
 */
public class MNTTest {

    @Test
    public void magicNumberTesterhexStringtoStringTest(){
        MagicNumberTester test = new MagicNumberTester("48 45 4C 50");
        assertTrue(test.hexStringtoString().equals("HELP"));
    }

    @Test
    public void magicNumberTesterhexStringtoByteArray(){
        MagicNumberTester test = new MagicNumberTester();
        //assertTrue(test.hextStringtoByteArray().equals("HELP".getBytes()));
        System.out.println(Arrays.toString(test.hextStringtoByteArray()));
        System.out.println(Arrays.toString("HELP".getBytes()));
    }


}
