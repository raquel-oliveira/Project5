import dissimulator.HuffmanTree;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

/**
 * Created by Paul Bertot on 1/18/16.
 */
public class HuffmanTreeTest {
    @Test
    public void HuffmanTreeTest(){
        HuffmanTree htt = new HuffmanTree();
        String occ = "{c:1, b:2, d:3, e:3, a:4}";
        htt.createList(occ);

       assertEquals("c:1", htt.getTree().get(0));
        assertEquals("d:3", htt.getTree().get(2));
    }
}
