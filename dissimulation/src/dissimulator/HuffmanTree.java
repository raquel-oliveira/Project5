package dissimulator;

/**
 * Created by Paul Bertot on 1/18/16.
 */
import java.util.HashMap;
import java.util.LinkedList;


public class HuffmanTree {
    /**
     * nodes : Linkedlist contaning the couple "character:frequency"
     * tree : String containing the tree as an expression following the format (exp1,exp2).
     */
    private LinkedList<String> nodes;
    private String tree;

    private HashMap<String, Integer> dictionnary;
    private HashMap<String, Integer> codelength;

    public HuffmanTree(){
        this.nodes = new LinkedList<String>();
    }

    public String getTree(){
        return this.tree;
    }

    public HashMap<String, Integer> getDictionnary(){
        return this.dictionnary;
    }

    public HashMap<String, Integer> getCodelength(){
        return this.codelength;
    }

    public void setTree(String s){
        this.tree = s;
    }

    public LinkedList<String> getNodes(){
        return this.nodes;
    }

    /**
     * This method adds a String representing a couple character:frequency while respecting the order by frequency
     *
     * @param node String representin ga character and its frequency, expected to be "x~y" where x is the character
     *             and y is the frequency value (integer).
     */
    public void addNode(String node){
        int index = 0;
        String[] nodeS = node.split("~");
        int occ = Integer.parseInt(nodeS[1]);
        if(!this.getNodes().isEmpty()){
            for (String n : this.getNodes()){
                String[] nS = n.split("~");
                if (occ >= Integer.parseInt(nS[1]))
                    index++;
            }
            this.getNodes().add(index, node);
        }
        else this.getNodes().add(node);
    }

    /**
     * This method fuses the first 2 nodes of the nodes LinkedList.
     * Fusing means that the character will be saved as a couple, and will look like [n1|n2]~x
     * where n1 and n2 will be characters (or couples such as [a|b]) and x will be the addition of the two frequencies.
     */
    public void fuseNodes(){
        StringBuilder sb = new StringBuilder("[|]");
        String n1 = this.getNodes().get(0);
        String n2 = this.getNodes().get(1);
        String[] n1split = n1.split("~");
        String[] n2split = n2.split("~");

        int occ = Integer.parseInt(n1split[1]) + Integer.parseInt(n2split[1]);

        sb.insert(1, n1split[0]);
        sb.insert(n1split[0].length()+2, n2split[0]);
        sb.append("~"+occ);
        this.addNode(sb.toString());
        this.getNodes().remove();
        this.getNodes().remove();
    }

    /**
     * This method does a while loop to fuse all the nodes of the LinkedList, untill you get the Huffman Tree,
     * with the total number of letters. Then, the tree representation is stored in the attribute tree.
     */
    public void constructHuffmanTree(){
        while(this.getNodes().size()>1){
            this.fuseNodes();
        }

        String[] tuple = this.getNodes().get(0).split("~");
        this.setTree(tuple[0]);
    }

    /**
     * Fills the nodes LinkedList with the "character:frequency" strings, ordered by their frequency (from lowest to highest)
     * This is intended to be used as initia;isation for the nodes LinkedList
     * @param occurences String representing the frequencies of the letters in the message.
     *                   The format expected is the same as the return value of getNbIterations from MessageTreatment
     *                   example => "{a:2, b:1, j:3}"
     */

    public void createList(String occurences){
        String occur = occurences.substring(1, occurences.length()-1);
        String[] tuples = occur.split(", ");
        for(int i=0; i < tuples.length; i++){
            this.addNode(tuples[i]);
        }

    }

    /**
     * This method determines which coma should be used for the splitting of the String during the recursivity;
     * It is used to avoid miscutting the String sent as parameter, and create a correct dictionnary.
     * @param s The string to be analysed, the format expected is exp1,exp2
     *          where exp1 and exp2 can be a single character, or a couple of expressions => (exp3,exp4)
     * @return Returns the position of the coma that is not inside a set of parentheses, which will allow us
     * to cut the s expression into two elements, left and right, to simulate the tree.
     */
    public int comaPosition(String s){
        int pos =0;
        int alt = 0;
        for(int i=0; i< s.length(); i++){
            if(s.charAt(i)=='[')
                alt++;
            else if (s.charAt(i) ==']')
                alt--;
            else if(s.charAt(i) == '|' && alt ==0)
                pos = i;
        }
        return pos;
    }


    /**
     * Method that fills the dictionnary
     *
     * and V is the code for this character, as an integer.
     **/
    public void getCodes(){
        HashMap<String, Integer> hmd = new HashMap<String, Integer>();
        HashMap<String, Integer> hmc = new HashMap<String, Integer>();
        this.getCodes(hmd,hmc, this.getTree(), 0,0);
        this.dictionnary = hmd;
        this.codelength = hmc;
    }

    /**
     * Internal method to recursively determine the code value and its length for each character in the message string
     * @param dic The HashMap that contains the dictionnary
     * @param cod The HaashMap containing the lengths of the different codes for each character
     * @param node Either a character or an expression of the following format => (exp1,exp2).
     *             The first node is expected to be the String parameteer, once it has been initialized with
     *             the proper value (the String representing the tree once every node has been fused).
     * @param value The value of the code.
     * @param len The length of the code
     */
    private void getCodes(HashMap<String, Integer> dic,HashMap<String, Integer>cod, String node, int value, int len){
        if (node.length()>1){
            node = node.substring(1, node.length()-1);
            this.getCodes(dic, cod, node.substring(0, this.comaPosition(node)), value*2+0,len+1);
            this.getCodes(dic, cod, node.substring(this.comaPosition(node)+1, node.length()), value*2+1, len+1);
        }
        else{
            dic.put(node, value);
            if(len == 0)
                cod.put(node, len+1);
            else cod.put(node, len);
        }
    }


}
