#include "reveal.h"

void printIplImage(const IplImage* img, CvScalar pixel ) {
    for(int row = 0; row < img->height; row++) {
        for(int col = 0; col < img->width; col++){
            pixel = cvGet2D(img, row, col);
            //pixel[blue, green, red]
            printf("[%f, %f, %f] ", pixel.val[0], pixel.val[1], pixel.val[2]);
        }
        printf("\n");
    }
}

int main() {
    IplImage *img = 0;
    int height, width, step, channels;
    uchar *data;
    CvScalar pixel;

    //loadImage(img, "../resource/teste.png" );
    img=cvLoadImage("../resource/teste.png", 1);
    if(!img){
        printf("Could not load image file: %s\n", "test.png");
        exit(0);
    }

    height    = getHeight(img);
    width     = getWidth(img);
    channels  = getChannels(img);
    data      = (uchar *)img->imageData;
    uchar *pImg = (uchar *)img->imageData; // setup the pointer to access img data

    printf("Processing a image with %d channels\n", channels);
    printIplImage(img, pixel);

    showImage(img);

    return 0;
}