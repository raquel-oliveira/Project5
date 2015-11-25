#include "reveal.h"

/**
 * Print the value of each component pixels of an image
 */
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
 * Temporary
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
 * Temporary
 * Reveal the hidden message of an image witch was
 * dissimulated taking the least significant bit of each component of a pixel
 *
 * Temporary because, for now, we are managing a short message.
 *
 */
void revealrgb(const IplImage* img, CvScalar pixel){
    int lred, lgreen, lblue, z = 0;
    int tab[8];
    char resultat[65];

    //for(int row = 0; row < img->height; row++) {
    for(int col = 0; col < 56/*img->width*/; col++)
    {
        pixel = cvGet2D(img, 0, col);
        
        lred = get_bit(pixel.val[2], 8);
        tab[z] = lred;
        checkAndConvert(resultat, &z);
        
        z++;
        lgreen = get_bit(pixel.val[1], 8);
        tab[z] = lgreen;
        checkAndConvert(resultat, &z);

        z++;
        lblue = get_bit(pixel.val[0], 8);
        tab[z] = lblue;
        checkAndConvert(resultat, &z);
        
        z++;
    }
}

void checkAndConvert(char resultat[], int *z)
{
    if(z == 7)
    {
        int n = 0, j;
        for(j = 0; j < 8; j++)
        {
            n += tab[j]*pow(2,8-j);
        }
        sprintf(resultat, "%d", n);
        
        printf("%s", resultat);
        
        z = 0;
    }
}

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
    //printMatrixChannels(img, pixel, channels);

    //showImage(img);
    //reveal(img, pixel);
    revealrgb(img, pixel);

    return 0;
}