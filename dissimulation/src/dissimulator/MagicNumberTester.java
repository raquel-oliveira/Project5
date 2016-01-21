package dissimulator;

import javax.xml.bind.DatatypeConverter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

/**
 * Created by Paul Bertot on 12/9/15.
 */
public class MagicNumberTester {

    private String hexString;

    public MagicNumberTester(){
        this.hexString = "48454C50";
    }

    public MagicNumberTester(String hexstr){
        if(hexstr.startsWith("\""))
            hexstr = hexstr.substring(1, hexstr.length()-1);
        this.hexString = hexstr;
    }

    public String toHexString(byte[] bytes){
        StringBuffer sb = new StringBuffer( bytes.length*2 );
        for( int i = 0; i < bytes.length; i++ )
        {
            sb.append( toHex(bytes[i] >> 4) );
            sb.append( toHex(bytes[i]) );
            sb.append(" ");
        }
        sb.delete(sb.length()-1, sb.length()-1);
        return sb.toString();
    }

    private static char toHex(int nibble){
        final char[] hexDigit =
                {
                        '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
                };
        return hexDigit[nibble & 0xF];

    }

    public boolean doesFileContainMN(String filepath) throws IOException {
        Path path = Paths.get(filepath);
        byte[] data = Files.readAllBytes(path);

        String hexcomp = this.toHexString(data);
        return hexcomp.contains(this.getHexString());

    }

    public boolean doesStringContainMN(String message){
        String hexcomp = this.toHexString(message.getBytes());
        return  hexcomp.contains(this.getHexString());
    }

    public String hexStringtoString(){
        String res = "";
        /*if(this.hexString.contains("\\s+")) {
            String[] splitstr = this.hexString.split("\\s+");
            for (int i = 0; i < splitstr.length; i++) {
                char[] c = Character.toChars(Integer.decode("0X" + splitstr[i]));
                res += Character.toString(c[0]);
            }
            return res;
        }*/

            String mn = this.hexString;

            for (int i = 0; i < mn.length(); i+=2) {
                char[] c = Character.toChars(Integer.decode("0X" + mn.charAt(i)+mn.charAt(i+1)));
                res += Character.toString(c[0]);
            }
            return res;


    }

    public byte[] hextStringtoByteArray(){
        String[] splitstr = new String[4];
        for(int i= 0; i < 8; i=i+2){
            int j = i+2;
            splitstr[i/2] = this.hexString.substring(i,j);
        }
        int size = splitstr.length;
        byte [] bytes = new byte[size];
        int j=0;
            for (int i = 0; i < splitstr.length; i++) {
                byte[] b = DatatypeConverter.parseHexBinary(splitstr[i]);
                bytes[j]=b[0];
                j++;
            }
        return bytes;
    }

    public String getHexString(){
        return this.hexString;
    }

    public byte[] mnCompressionBArray(){
        byte[] bytes = this.hextStringtoByteArray();
        byte[] ret = new byte[bytes.length];
        for(int i=0; i < bytes.length; i++){
            byte br = Compressor.reverseByte(bytes[i]);
            ret[i] = br;
        }
        return ret;
    }
}

