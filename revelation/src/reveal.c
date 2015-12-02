#include "reveal.h"
#define BLUE 0
#define GREEN 1
#define RED 2
//char*
//void reveal(char* messageHidden){}

int main() {
    IplImage *img = 0;
    int height, width, step, channels;
    uchar *data;
    CvScalar pixel;

    //char* magic = "HELP"; //48 45 4C 50

    /*If second parameter == 1 (normal image); if == 0 (grey)*/
    img=cvLoadImage("../resource/teste.png", 1);
    if(!img){
        printf("Could not load image file:");
        exit(0);
    }

    height    = getHeight(img);
    width     = getWidth(img);
    channels  = getChannels(img);
    data      = (uchar *)img->imageData;
    uchar *pImg = (uchar *)img->imageData; // setup the pointer to access img data

    int **blue = getBlueMatrix(img);
    int **red = getRedMatrix(img);
    int **green = getGreenMatrix(img);

    char* encodemessage = messageFromOneColor(green, 1, height, width);
    reveal(encodemessage);
    //char* messsage = messageFromOneColor(azul, 1, height, width); //change parameters

    return 0;
}