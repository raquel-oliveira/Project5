package dissimulator;

/**
 * Created by paul Bertot on 1/18/16.
 */
import java.util.LinkedList;


public class HuffmanTree {
    private LinkedList<String> tree;

    public HuffmanTree(){
        this.tree = new LinkedList<String>();
    }

    public LinkedList<String> getTree(){
        return this.tree;
    }

    public void addNode(String node){
        int index = 0;
        String[] nodeS = node.split(":");
        int occ = Integer.parseInt(nodeS[1]);
        if(!this.getTree().isEmpty()){
            for (String n : this.getTree()){
                String[] nS = n.split(":");
                if (occ >= Integer.parseInt(nS[1]))
                    index++;
            }
            this.getTree().add(index, node);
        }
        else this.getTree().add(node);
    }

    public void fuseNodes(){
        StringBuilder sb = new StringBuilder("(,)");
        String n1 = this.getTree().get(0);
        String n2 = this.getTree().get(1);
        String[] n1split = n1.split(":");
        String[] n2split = n2.split(":");

        int occ = Integer.parseInt(n1split[1]) + Integer.parseInt(n2split[1]);

        sb.insert(1, n1split[0]);
        sb.insert(n1split[0].length()+2, n2split[0]);
        sb.append(":"+occ);
        this.addNode(sb.toString());
        this.getTree().remove();
        this.getTree().remove();
    }

    public void createList(String occurences){
        String[] tuples = occurences.split(",");
        for(int i=0; i < tuples.length; i++){
            this.addNode(tuples[i]);
        }

    }


}
