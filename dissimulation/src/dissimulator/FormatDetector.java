package dissimulator;

import javax.imageio.ImageIO;
import javax.imageio.ImageReader;
import javax.imageio.stream.ImageInputStream;
import java.io.*;
import java.util.Iterator;

/**
 * Created by Paul Bertot
 */

public class FormatDetector {
    private String filetype;

    public FormatDetector(){
        this.filetype = "png";
    }
    public void setFiletype(String filename) throws IOException {
        File file = new File(filename);
        InputStream is = new FileInputStream(file);
        ImageInputStream iis = ImageIO.createImageInputStream(is);
        Iterator iter =  ImageIO.getImageReaders(iis);
        if(!iter.hasNext()){
            InputStream in = new FileInputStream(file);
            char c1 = (char)readByte(in);
            char c2 = (char)readByte(in);
            if(c1 == 'P'){
                if(c2 == '2' || c2 == '5')
                    filetype="pgm";
                else if(c2 == '3' || c2 == '6')
                    filetype="ppm";
            }
            else filetype = null;
            return;
        }
        ImageReader reader = (ImageReader) iter.next();
        iis.close();

        filetype = reader.getFormatName();

    }

    public static int readByte(InputStream in)throws IOException{
        int b = in.read();
        if(b==-1)
            throw new EOFException();
        return b;

    }
    public String getFileType(){
        return filetype;
    }


}

