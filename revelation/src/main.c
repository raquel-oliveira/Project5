#include <stdio.h>
#include <stdlib.h>
#include "reveal.h"


#define SIZE_MESSAGE 100

int main(int argc, char *argv[])
{
    IplImage *img = NULL;
    int i = 0;
    uchar *message = malloc(SIZE_MESSAGE);
    char help[] = "HELP";

    img = cvLoadImage("../resource/1bitRedGreenDirect.png", 1); //If second parameter == 1 (normal image); if == 0 (grey)

    if(!img)
    {
        printf("Could not load image file : ");
        exit(0);
    }

    int errorCode = revealDirect(img, 1, help, message);
    switch(errorCode){
        case 0:
            while(message[i] != '\0')
            {
                printf("%c", message[i]);
                i++;
            }
        case 1: exit(1); break;
        case 2: printf("There is no magic number"); break;
    }

    cvReleaseImage(&img);
    free(message);

    return 0;
}
