
import dissimulator.MagicNumberTester;
import org.junit.Test;
import static org.junit.Assert.*;


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
        byte[] arraytest = test.hextStringtoByteArray();
        byte[] controlarray = "HELP".getBytes();
        for(int i=0; i<arraytest.length; i++){
            assertEquals(arraytest[i], controlarray[i]);
        }

    }

    @Test
    public void magicNumbertesterStringContainsMN(){
        MagicNumberTester test = new MagicNumberTester();
        assertFalse(test.doesStringContainMN("Bonjour"));
        assertFalse(test.doesStringContainMN("BonjHE LPour"));
        assertTrue(test.doesStringContainMN("BonHELPjour"));

    }

    @Test
    public void magicNumberToByteArrayTest(){
        MagicNumberTester test = new MagicNumberTester();
        byte[] ba = test.hextStringtoByteArray();

    }


}
