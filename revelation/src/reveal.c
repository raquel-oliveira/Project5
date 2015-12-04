#include "reveal.h"
/**
 *  @param img - Image to be reveal in the Direct Pattern
 *  @param b - Quantity of bits
 *  @param help - define de ends of the message
 */
uchar* revealDirect(IplImage *img, int b, char* help, uchar* message){
    CvScalar pixel;
    int lbit, channel;
    int count = 7;
    uchar letter = 1;
    message = malloc(1000); //change this
    int i = 0;
    for (int row = 0; row < img->height; row++){
        for (int col = 0; col < img->width; col++){
            channel = cvGet2D(img, row, col).val[2]; //channel red
            lbit = get_bit(channel, b); //red, last bit if b = 1;
            letter = setBit(letter, count, lbit);
            count--;
            if (count < 0){ count = 7; message[i++] = letter; }
        }
    }
    return message;
}



int main() {
    IplImage *img = 0;
    int height, width, step, channels;
    uchar *data;

    /*If second parameter == 1 (normal image); if == 0 (grey)*/
    img=cvLoadImage("../resource/red1bit.png", 1);
    if(!img){
        printf("Could not load image file:");
        exit(0);
    }

    height    = getHeight(img);
    width     = getWidth(img);
    channels  = getChannels(img);

    uchar* message;
    message = revealDirect(img,8,0, message);
    int i = 0;
    for (int i = 0; i < 21; i++){
        printf("%c", message[i]);
    }



    return 0;
}