package dissimulator;

import java.math.BigInteger;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Set;

/**
 * Created by Paul Bertot on 1/19/16.
 */
public class Compressor {

    private HashMap<String, Integer> dictionnary;
    private HashMap<String, Integer> codelength;
    private String msg;
    private int mdc;

    public Compressor(HashMap<String, Integer> dic, HashMap<String, Integer> cl){
        this.dictionnary = dic;
        this.codelength = cl;
    }

    public void setMessage(String s){
        this.msg = s;
    }

    public int getMdc(){
        return this.mdc;
    }

    public void setMdc(int n){
        this.mdc = n;
    }

    public String getMsg(){
        return this.msg;
    }


    /**
     * This method compresses the dictionnary part of the message. This part of the message contains
     * the number of different symbols -1, and for each character, a byte representing the charater, the length of the
     * code used for the compression of this character and the code itself.
     *
     * @return a byte array containing the first part of the message (number of symbols + coding for each symbol)
     */
    public byte[] compressDictionnary(){
        int i=0;
        String[] letters = this.msg.split("(?!^)");
        Set<String> uniquelet = new LinkedHashSet<String>();
        for(String s : letters){
            uniquelet.add(s);
        }
        this.mdc = uniquelet.size();
        byte symb = reverseByte(this.integerToByte(uniquelet.size()-1));
        int codebytes = 0;
        for(String s : uniquelet){
            codebytes+= (int) Math.ceil((double)codelength.get(s)/8);
        }
        byte[] b = new byte[this.mdc*2+codebytes+1];
        b[i++] = symb;



        for(String s : uniquelet){

            byte letter = reverseByte(s.getBytes()[0]);
            byte cl = reverseByte(this.integerToByte(codelength.get(s)));
            b[i++] = letter;
            b[i++] = cl;
            if(codelength.get(s)<=8) {
                byte temp = (byte) (this.integerToByte(dictionnary.get(s)) << (8 - codelength.get(s)));
                byte dic = reverseByte(temp);
                b[i++] = dic;
            }
            else{
                byte[] bytes = BigInteger.valueOf(dictionnary.get(s)).toByteArray();
                int shifter = 8-(codelength.get(s)%8);
                for(byte b1 : bytes){
                    System.out.println(b1);
                    b1 = (byte) (b1<<(shifter));
                    System.out.println(b1);
                    byte newby =reverseByte(b1);
                    b[i++] = newby;

                }
            }

        }

        return b;
    }

    /**
     * This method compresses the content of the message (-msg option). It creates a byte array where the first one
     * indicates the number of bits used in the last byte (you can obtain the padding by substraction),
     * followed by the compressed message (with each letter replaced by its code).
     *
     * @return a byte array representing the byte array for the message part.
     */
    public byte[] compressMessage(){
        int padd = 0;
        String[] letters  = this.msg.split("(?!^)");
        int nbbytes = compMessageByteNb(letters)+1;
        byte[] ret = new byte[nbbytes];
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

    /**
     * This method appends 2 byte arrays passed as arguments of the method. In the context of this application,
     * it is used to regroup the dictionnary part of the message with the compressed version of the message
     * (from compressDictionnary() and compressMessage() respectively), as well as the full message with the
     * Magic Number to create an intelligible message for the reveal tools.
     *
     * @param b1 the byte array that you want to be first in the new byte array
     * @param b2 the byte array you want to have in second position in the new byte array
     * @return a byte array containing b1 and b2, inb that order
     */
    public static byte[] groupByteArray(byte[] b1,byte[] b2){
        byte[] ret = new byte[b1.length+b2.length];
        for(int i=0; i<b1.length; i++){
            if(b1[i]!=0 || i==0)
                ret[i]=b1[i];
        }
        for(int j=0; j<b2.length;j++){
            if(b2[j]!=0){
                ret[j+b1.length]= b2[j];
            }
        }
        return ret;
    }

    /**
     * This method counts the number of bytes that would be used by the raw compressed message
     * (ie without any of the bytes representing the dictionnary, the number of symbols, or the padding at the end of the message)
     *
     * @param characs the message as an array of String.
     * @return a number of bytes for the compressed message.
     */
    public int compMessageByteNb(String[] characs){
        int bytes = 0;
        int bits =0;
        for(String c : characs){
            bits+= codelength.get(c);

        }
        if(bits%8!=0)
            bytes= (bits/8)+1;
        else bytes = bits/8;
        return bytes;
    }

    /**
     * A simple method that converts an integer in a byte
     * @param i the integer to convert.
     * @return the byte result of the conversion.
     */
    public Byte integerToByte(int i){
        Byte ret = Byte.valueOf(i+"");
        return ret;
    }

    /**
     * A method that inverts the byte in argument. The base program uses BitSets to dissimulate the message.
     * One problem that appears is that the valueOf(Byte[]) method of BitSet passes values in little endian
     * (with the least significant bit first). For example, 01100010 becomes 01000110. To solve this,
     * we invert the bytes so that BitSet puts them in the correct way (big endian)
     *
     * @param in the byte to invert
     * @return the inverted byte.
     */
    public static byte reverseByte(byte in){
        byte out = 0;
        for(int ii=0; ii < 8; ii++){
            byte bit = (byte) (in & 1);
            out = (byte)((out<<1)| bit);
            in = (byte) (in >> 1);
        }
        return out;
    }

    /**
     * This method regroups compressDictionnary() and compressMessage() into a single method call, for lisibility.
     * @param message the mesage to have compressed
     * @return the compressed message, with its dictionnary
     */
    public byte[] messageCompression(String message){
        this.setMessage(message);
        byte[] dictionnary = this.compressDictionnary();
        byte[] msg = this.compressMessage();
        byte[] retour = groupByteArray(dictionnary,msg);
        return retour;
    }
}
