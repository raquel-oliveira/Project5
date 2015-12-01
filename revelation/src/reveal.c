#include "reveal.h"


int main() {
    IplImage *img = 0;
    int height, width, step, channels;
    uchar *data;
    CvScalar pixel;

    char* magic = "HELP"; //48 45 4C 50

    /*If second parameter == 1 (normal image); if == 0 (grey)*/
    img=cvLoadImage("../resource/secreteBonjour.png", 1);
    if(!img){
        printf("Could not load image file:");
        exit(0);
    }

    height    = getHeight(img);
    width     = getWidth(img);
    channels  = getChannels(img);
    data      = (uchar *)img->imageData;
    uchar *pImg = (uchar *)img->imageData; // setup the pointer to access img data

    printf("Processing a image with %d channels\n", channels);

    showImage(img);


    return 0;
}