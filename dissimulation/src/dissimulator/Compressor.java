package dissimulator;

import java.util.HashMap;

/**
 * Created by Paul Bertot on 1/19/16.
 */
public class Compressor {

    private HashMap<String, Integer> dictionnary;
    private HashMap<String, Integer> codelength;

    public Compressor(HashMap<String, Integer> dic, HashMap<String, Integer> cl){
        this.dictionnary = dic;
        this.codelength = cl;
    }

    public byte[] compressDictionnary(){
        byte[] b = new byte[this.dictionnary.size()*3+100];
        int i=0;
        byte symb = reverseByte(this.integerToByte(dictionnary.size()-1));
        b[i++] = symb;
        for(String s : this.dictionnary.keySet()){
            byte letter = reverseByte(s.getBytes()[0]);
            byte cl = reverseByte(this.integerToByte(codelength.get(s)));
            byte temp = (byte) (this.integerToByte(dictionnary.get(s))<<(8-codelength.get(s)));
            byte dic = reverseByte(temp);

            b[i++] = letter;
            b[i++] = cl;
            b[i++] = dic;
        }
        return b;
    }

    public byte[] compressMessage(String msg){
        String[] letters  = msg.split("(?!^)");
        int bitlen = 0;
        byte[] ret = new byte[(letters.length+1)*8];


        return ret;
    }


    public Byte integerToByte(int i){
        Byte ret = Byte.valueOf(i+"");
        return ret;
    }

    public static byte reverseByte(byte in){
        byte out = 0;
        for(int ii=0; ii < 8; ii++){
            byte bit = (byte) (in & 1);
            out = (byte)((out<<1)| bit);
            in = (byte) (in >> 1);
        }
        return out;
    }
}
