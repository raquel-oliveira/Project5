#include "reveal.h"

int main() {
    IplImage *img = 0;
    int height, width, step, channels;
    uchar *data;
    CvScalar pixel;

    img=cvLoadImage("../resource/teste.png", 1);
    if(!img){
        printf("Could not load image file: %s\n", "test.png");
        exit(0);
    }

    height    = img->height;
    width     = img->width;
    step      = img->widthStep;
    channels  = img->nChannels;
    data      = (uchar *)img->imageData;
    uchar *pImg = (uchar *)img->imageData; // setup the pointer to access img data

    printf("Processing a image with %d channels\n", channels);

    cvNamedWindow("ImageWindow", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("ImageWindow", 100, 100);

    cvShowImage("ImageWindow", img );

    cvWaitKey(0);

    cvReleaseImage(&img );
    return 0;
}