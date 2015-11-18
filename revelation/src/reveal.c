#include "reveal.h"

void printMatrixChannels(const IplImage* img, CvScalar pixel, int channels ) {
    for(int row = 0; row < img->height; row++) {
        for(int col = 0; col < img->width; col++){
            pixel = cvGet2D(img, row, col);
            if (channels == 3){
                //pixel[blue, green, red]
                printf("[%f, %f, %f] ", pixel.val[0], pixel.val[1], pixel.val[2]);
            }
            else if (channels == 1){
                printf("[%f] ", pixel.val[0]);
            }

        }
        printf("\n");
    }
}

/**
 * Tempory
 * Only looking the first line of a image.
 * Taking the message dissimulated in the least significant bit of red components only
 */
void reveal(const IplImage* img, CvScalar pixel){
    int lred;
    //for(int row = 0; row < img->height; row++) {
        for(int col = 0; col < 176/*img->width*/; col++) {
            pixel = cvGet2D(img, 0, col);
            lred = get_bit(pixel.val[2], 8);
            printf("%d", lred);
        }
    //}

}

/**
 * Reveal
 */
void revealrgb(const IplImage* img, CvScalar pixel){
    int lred, lgreen, lblue;
    int byte;
    int cont = 0;
    //for(int row = 0; row < img->height; row++) {
    for(int col = 0; col < 56/*img->width*/; col++) {
        pixel = cvGet2D(img, 0, col);
        lred = get_bit(pixel.val[2], 8);
        lgreen = get_bit(pixel.val[1], 8);
        lblue = get_bit(pixel.val[0], 8);
        printf("%d%d%d",lred,lgreen,lblue);
    }
    //}

}

int main() {
    IplImage *img = 0;
    int height, width, step, channels;
    uchar *data;
    CvScalar pixel;

    char* magic = "HELP"; //48 45 4C 50

    /*If second parameter == 1 (normal image); if == 0 (grey)*/
    img=cvLoadImage("../resource/cavaMessage.png", 1);
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
    //printMatrixChannels(img, pixel, channels);

   //showImage(img);
  //  reveal(img, pixel);
    revealrgb(img, pixel);

    return 0;
}