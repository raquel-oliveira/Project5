package dissimulator;

/**
 * Created by paul Bertot on 1/18/16.
 */
import java.util.HashMap;
import java.util.LinkedList;


public class HuffmanTree {
    private LinkedList<String> nodes;
    private String tree;

    public HuffmanTree(){
        this.nodes = new LinkedList<String>();
    }

    public String getTree(){
        return this.tree;
    }

    public void setTree(String s){
        this.tree = s;
    }

    public LinkedList<String> getNodes(){
        return this.nodes;
    }

    public void addNode(String node){
        int index = 0;
        String[] nodeS = node.split(":");
        int occ = Integer.parseInt(nodeS[1]);
        if(!this.getNodes().isEmpty()){
            for (String n : this.getNodes()){
                String[] nS = n.split(":");
                if (occ >= Integer.parseInt(nS[1]))
                    index++;
            }
            this.getNodes().add(index, node);
        }
        else this.getNodes().add(node);
    }

    public void fuseNodes(){
        StringBuilder sb = new StringBuilder("(,)");
        String n1 = this.getNodes().get(0);
        String n2 = this.getNodes().get(1);
        String[] n1split = n1.split(":");
        String[] n2split = n2.split(":");

        int occ = Integer.parseInt(n1split[1]) + Integer.parseInt(n2split[1]);

        sb.insert(1, n1split[0]);
        sb.insert(n1split[0].length()+2, n2split[0]);
        sb.append(":"+occ);
        this.addNode(sb.toString());
        this.getNodes().remove();
        this.getNodes().remove();
    }

    public void createList(String occurences){
        String occur = occurences.substring(1, occurences.length()-1);
        String[] tuples = occur.split(", ");
        for(int i=0; i < tuples.length; i++){
            this.addNode(tuples[i]);
        }

    }

    public int comaPosition(String s){
        int pos =0;
        int alt = 0;
        for(int i=0; i< s.length(); i++){
            if(s.charAt(i)=='(')
                alt++;
            else if (s.charAt(i) ==')')
                alt--;
            else if(s.charAt(i) == ',' && alt ==0)
                pos = i;
        }
        return pos;
    }

    public HashMap<String, Integer> getCodes(){
        HashMap<String, Integer> hm = new HashMap<String, Integer>();
        this.getCodes(hm, this.getTree(), 0);

        return hm;
    }

    private void getCodes(HashMap<String, Integer> hash, String node, int value){
        if (node.length()>1){
            node = node.substring(1, node.length()-1);
            this.getCodes(hash, node.substring(0, this.comaPosition(node)), value*2+0);
            this.getCodes(hash, node.substring(this.comaPosition(node)+1, node.length()), value*2+1);
        }
        else hash.put(node, value);
    }


}
