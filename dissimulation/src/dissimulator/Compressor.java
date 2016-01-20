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
        int padd = 0;
        String[] letters  = msg.split("(?!^)");
        byte[] ret = new byte[(letters.length+1)*8];
        int bc =0;
        StringBuilder sbb = new StringBuilder();

        for(String l : letters){
            String codl = Integer.toBinaryString(dictionnary.get(l));
            while(codl.length()<codelength.get(l)){
                codl = "0"+codl;
            }
            sbb.append(codl);
        }
        while(sbb.length()%8!=0){
            sbb.append("0");
            padd++;
        }
        if(padd!=0)
            padd = 8-padd;
        String pad = Integer.toBinaryString(padd);
        while(pad.length()<8){
            pad = "0"+pad;
        }
        sbb.insert(0, pad);
        for(int i=0, j=8; j<=sbb.length(); i+=8, j+=8){
            String byt = sbb.substring(i, j);
            Byte b = (byte) Integer.parseInt(byt, 2);
            ret[bc] = reverseByte(b);
            bc++;
        }
        return ret;
    }

    public byte[] groupMessage(byte[] dic,byte[] msg){
        byte[] ret = new byte[dic.length+msg.length];
        for(int i=0; i<dic.length; i++){
            if(dic[i]!=0 || i==0)
                ret[i]=dic[i];
        }
        for(int j=0; j<msg.length;j++){
            if(msg[j]!=0){
                ret[j+dic.length]= msg[j];
            }
        }
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
