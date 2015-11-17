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
/*
// Temp variable for one byte from file
char byte_current;

// Grab LSB of all bytes for length specified at fgetc
void takeLsb(FILE *file_handle, char byte_current, FILE *message_handle){
    int size_message=fgetc(file_handle);
    for(int i=0;i<size_message;i++) {
        char temp_ch='\0';
        for( int j=0;j<8;j++) {
            temp_ch = temp_ch<<1;
            byte_current = fgetc(file_handle);
            int file_byte_lsb = byte_current & 1;
            temp_ch|=file_byte_lsb;
        }
        fputc(temp_ch,message_handle);
    }
    fclose(message_handle);	//stream closed
}*/


int main() {
    IplImage *img = 0;
    int height, width, step, channels;
    uchar *data;
    CvScalar pixel;

    File *message;
    message = "../resource/message.txt";


    //loadImage(img, "../resource/teste.png" );
    /*If second parameter == 1 (normal image); if == 0 (grey)*/
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
    printMatrixChannels(img, pixel, channels);

    showImage(img);

    return 0;
}