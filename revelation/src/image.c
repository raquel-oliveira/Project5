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

/**
 * Get the values of blue in each pixel of a given image
 * @return 1 if the image it' not BGR
 */
int **getBlueMatrix(IplImage* img){
    /* if (getChannels(img) == 1){
         return 1
     }
     else{*/
    int **blue;
    CvScalar pixel;
    blue = malloc(img->height * sizeof (int *) );
    for(int row = 0; row < img->height; row++) {
        blue[row] = malloc(img->width * sizeof (int));
        for (int col = 0; col < img->width; col++) {
            pixel = cvGet2D(img, row, col);
            blue[row][col] = pixel.val[0];
        }
    }
    return blue;
    //}
}


/**
 * Get the values of green in each pixel of a given image
 */
char **getGreenMatrix(const IplImage* img){
    char **green;
    CvScalar pixel;
    green = malloc(img->height * sizeof (int *) );
    for(int row = 0; row < img->height; row++) {
        green[row] = malloc(img->width * sizeof (int));
        for (int col = 0; col < img->width; col++) {
            pixel = cvGet2D(img, row, col);
            green[row][col] = pixel.val[1];
        }
    }
    return green;
}


/**
 * Get the values of red in each pixel of a given image
 */
char **getRedMatrix(const IplImage* img){
    char **red;
    CvScalar pixel;
    red = malloc(img->height * sizeof (int *) );
    for(int row = 0; row < img->height; row++) {
        red[row] = malloc(img->width * sizeof (int));
        for (int col = 0; col < img->width; col++) {
            pixel = cvGet2D(img, row, col);
            red[row][col] = pixel.val[2];
        }
    }
    return red;
}