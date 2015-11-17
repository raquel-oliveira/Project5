#include "reveal.h"
//a lot of code equal. Change it!
void print3channels(const IplImage* img, CvScalar pixel ) {
    for(int row = 0; row < img->height; row++) {
        for(int col = 0; col < img->width; col++){
            pixel = cvGet2D(img, row, col);
            //pixel[blue, green, red]
            printf("[%f, %f, %f] ", pixel.val[0], pixel.val[1], pixel.val[2]);
        }
        printf("\n");
    }
}

void print1channel(const IplImage* img, CvScalar pixel ) {
    for(int row = 0; row < img->height; row++) {
        for(int col = 0; col < img->width; col++){
            pixel = cvGet2D(img, row, col);
            //pixel[blue, green, red]
            printf("[%f] ", pixel.val[0]);
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
    img=cvLoadImage("../resource/teste.png", 0);
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
    if (channels == 3){
        print3channels(img, pixel);
    }
    else if (channels ==1){
        print1channel(img, pixel);
    }

    showImage(img);

    return 0;
}