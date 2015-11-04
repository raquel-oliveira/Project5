package io;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class ReadTxt {

	public static void readTxtFile(String filePath){
		try{
			String encoding = "UTF-8";
			File file = new File(filePath);
			if(file.isFile()&&file.exists()){  
				InputStreamReader read = new InputStreamReader(new FileInputStream(file),encoding);
				BufferedReader bufferedReader = new BufferedReader(read);
				String lineTxt = null;
				while((lineTxt = bufferedReader.readLine())!=null){
					System.out.println(lineTxt);
				}
				read.close();
			}else{
				System.out.println("Don't find the file.");
			}
		}catch(Exception e){
			System.out.println("erreur reading.");
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		String filePath = "writeTxt.txt";
		readTxtFile(filePath);

	}

}
