package matrice;

import java.io.IOException;

public class Main {

	public static void main(String[] args) throws IOException
	{
		ImageRGB img = new ImageRGB("jpg.2.jpg");
		ManipMatrice manipMat = new ManipMatrice(img);
		Dissimulation d = new Dissimulation(img);
		
		manipMat.getPixelsColor("red");
		manipMat.getPixelsColor("blue");
		manipMat.getPixelsColor("green");
		
		
		
		manipMat.goToNegative();
		
		manipMat.setPixelsColor();
		
		
		
		//TextToBinary c = new TextToBinary();
		//String x = c.StringtoBinaryString("Bonjour");
		
		//mat.dissimulationLSB(x, red, blue, green);
		
		// FAIRE DE L'OBJET !!!!!! FAIRE UNE CLASSE MATRICE ET LAISSER LES TABLEAUX DEDANS ! UTILISER SEULEMENT LES GETTEURS DE MATRICE !
	}
}
