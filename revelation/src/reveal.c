#include "reveal.h"
#define BLUE 0
#define GREEN 1
#define RED 2
#define MAGIC "HELP"

/*
 * @param matrixColor
 * @param qtdbit number of bits the message was hidden
 * */
char* revealOneColor(int **matrixColor, int qtdbit, int height, int width ){
    int maxSize = 10000;
    char aux_message;
    char *messageHidden = malloc(maxSize);
    int charCount = 0;
    int cont = 0; // bit as 0 as the last significant bit and 7 as the most significant bit
    int row, col;
    for (row = 0; row < height; row ++){
        for (col = 0; col < width; col ++){
            while (cont < qtdbit){
                aux_message = intBToChar(get_bit(matrixColor[row][col], cont));
                messageHidden[charCount++] = aux_message;
                cont ++;
                if(charCount >= maxSize){
                    maxSize *= 2;
                    messageHidden = (char *) realloc(messageHidden, maxSize*sizeof(char));
                }
            }
            cont = 0;
        }
    }
    return messageHidden;
}


int main() {
    IplImage *img = 0;
    int height, width, step, channels;
    uchar *data;
    CvScalar pixel;

    //char* magic = "HELP"; //48 45 4C 50

    /*If second parameter == 1 (normal image); if == 0 (grey)*/
    img=cvLoadImage("../resource/azul.png", 1);
    if(!img){
        printf("Could not load image file:");
        exit(0);
    }

    height    = getHeight(img);
    width     = getWidth(img);
    channels  = getChannels(img);
    data      = (uchar *)img->imageData;
    uchar *pImg = (uchar *)img->imageData; // setup the pointer to access img data

    int **azul = getBlueMatrix(img);
   /* for (int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("%d ", azul[i][j]);
        }
    }*/
    char* messsage = revealOneColor(azul,1, height, width); //change parameters
    printf("%c", messsage[0]);
    return 0;
}