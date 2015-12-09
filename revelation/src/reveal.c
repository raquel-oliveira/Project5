#include "reveal.h"
/**
 *  @param img - Image to be reveal in the Direct Pattern
 *  @param b - Quantity of bits
 *  @param help - define de ends of the message
 */
uchar* revealDirect(IplImage *img, int b, char* help, uchar* message){
    int lbit, channel; int count = 7; int i = 0;
    uchar letter = 1; char* end;
    message = malloc(1000); //change this
    for (int row = 0; row < img->height; row++){
        for (int col = 0; col < img->width; col++){
            channel = cvGet2D(img, row, col).val[2]; //channel red
                lbit = get_bit(channel, (9 - b)); //access to the bit in ascending order
                letter = setBit(letter, count, lbit);
                count--;
                if (count < 0) {
                    count = 7;
                    message[i++] = letter;
                }

                end = strstr((char *) message, help);
                if (end != 0) {
                    *end = '\0';
                    return message;
                }
        }
    }
    return message;
}



int main() {
    IplImage *img = 0;
    int height, width, step, channels;
    uchar* message;
    char *help = malloc(5* sizeof(char));
    help[0] = 'H';
    help[1] = 'E';
    help[2] = 'L';
    help[3] = 'P';
//    help[4] = '/0';

    /*If second parameter == 1 (normal image); if == 0 (grey)*/
    img=cvLoadImage("../resource/red1bit.png", 1);
    if(!img){
        printf("Could not load image file:");
        exit(0);
    }
    height    = getHeight(img);
    width     = getWidth(img);
    channels  = getChannels(img);


    message = revealDirect(img,1,help, message);
    int i = 0;
    while(message[i] != '\0'){
        printf("%c", message[i]);
        i++;
    }

    return 0;
}