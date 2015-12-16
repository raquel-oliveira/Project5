package matrice;

import javax.imageio.ImageIO;
import javax.imageio.ImageReader;
import javax.imageio.stream.ImageInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
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
            filetype = null;
            return;
        }
        ImageReader reader = (ImageReader) iter.next();
        iis.close();

        filetype = reader.getFormatName();

    }
    public String getFileType(){
        return filetype;
    }


}

