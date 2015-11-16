#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include <opencv/highgui.h>

int main(int argc, char *argv[]) {
    
    IplImage* img = 0;
    int height,width,step,channels;
    uchar *data;
    int i,j,k;

    // load an image
    img=cvLoadImage("../resource/test.png", 1);
    if(!img){
        printf("Could not load image file: %s\n", "test.png");
        exit(0);
    }

    // get the image data
    height    = img->height;
    width     = img->width;
    step      = img->widthStep;
    channels  = img->nChannels;
    data      = (uchar *)img->imageData;
    uchar *pImg = (uchar *)img->imageData; // setup the pointer to access img data
    printf("Processing a image with %d channels\n", channels);

    //If it is colorful take the 3 channels
    if (channels > 1) {

    } else if (channels == 1){
        //Take the gray information
    }

    // create a window
    cvNamedWindow("ImageWindow", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("ImageWindow", 100, 100);

    // show the image
    cvShowImage("ImageWindow", img );

    // wait for a key
    cvWaitKey(0);

    // release the image
    cvReleaseImage(&img );
    return 0;
}
