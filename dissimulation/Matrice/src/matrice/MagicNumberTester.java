package matrice;

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
        this.hexString = "48 45 4C 50";
    }

    public MagicNumberTester(String hexstr){
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

    public String getHexString(){
        return this.hexString;
    }
}

