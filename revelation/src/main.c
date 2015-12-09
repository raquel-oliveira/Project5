#include <stdio.h>
#include <stdlib.h>
#include "reveal.h"


#define SIZE_MESSAGE 100

int main(int argc, char *argv[])
{
    IplImage *img = NULL;
    int height, width, step, channels, i = 0;
    uchar *message = malloc(SIZE_MESSAGE * sizeof(uchar));
    char help[] = "HELP";

    img = cvLoadImage("../resource/1bitRedDirect.png", 1); //If second parameter == 1 (normal image); if == 0 (grey)

    if(!img)
    {
        printf("Could not load image file : ");
        exit(0);
    }
    
    height    = getHeight(img);
    width     = getWidth(img);
    channels  = getChannels(img);

    message = revealDirect(img, 1, help, message);
    
    while(message[i] != '\0')
    {
        printf("%c", message[i]);
        i++;
    }

    cvReleaseImage(&img);
    return 0;
}
