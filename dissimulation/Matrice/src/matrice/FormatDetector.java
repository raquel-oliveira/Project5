package matrice;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URLConnection;


public class FormatDetector {
    private String filetype;

    public FormatDetector(){
        this.filetype = "png";
    }
    public void setFiletype(String filename) throws IOException {
        File file = new File(filename);
        InputStream is = new BufferedInputStream(new FileInputStream(file));
        String type = URLConnection.guessContentTypeFromStream(is);
        if(type!=null){
            type = type.split("/")[1];
            this.filetype = type;
        }
        else {
            String ct = URLConnection.guessContentTypeFromName(filename);
            ct = ct.split("/")[1];
            this.filetype = ct;

        }
    }
    public String getFileType(){
        return filetype;
    }


}

