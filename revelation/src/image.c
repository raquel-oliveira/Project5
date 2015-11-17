#include "image.h"

void loadImage(const IplImage* img, const char *filename){
    img = cvLoadImage(filename, 1);
    if (!img) {
        printf("Could not load image file");
        exit(0);
    }
}
/*void getDataImage(const IplImage* img, int* height, int* width, int* step, int* channels, uchar* data ){
    height = getHeight(img);
    width = getWidth(img);
    step = getStep(img);
    channels = getChannels(img);
    data = (uchar *) img->imageData;
}*/

/**
 * @return height of a image
 */
int getHeight(IplImage* img){
    return img->height;
}

/**
 * @return @width of an image
 */
int getWidth(IplImage* img){
    return img->width;
}

/**
 * @return the steps to traverse using width
 */
int getStep(IplImage* img){
    return img->widthStep;
}

/**
 * return number of channel in a image
 */
int getChannels(IplImage* img){
    return img->nChannels;
}

/**
 * Show an image in the screen
 */
void showImage(IplImage* img){
    //create the window
    cvNamedWindow("ImageWindow", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("ImageWindow", 100, 100);

    // show the image
    cvShowImage("ImageWindow", img );

    // wait for a key
    cvWaitKey(0);

    // release the image
    cvReleaseImage(&img );
}