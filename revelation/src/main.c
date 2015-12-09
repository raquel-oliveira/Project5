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

    img = cvLoadImage("../resource/1bitRedGreenDirect.png", 1); // Second parameter == 1 (RGB) || == 0 (GREY)
    
    if(!img)
    {
        printf("Could not load image file : ");
        exit(0);
    }
    
    int errorCode = revealText(img, 1, help, message);
    
    switch(errorCode){
        case 0: while(message[i] != '\0')
                {
                    printf("%c", message[i]);
                    i++;
                } break;
            
        case 1: {
                    printf("Error while reallocating memory for message");
                    exit(1);
                } break;
            
        case 2: printf("There is no magic number");
    }

    cvReleaseImage(&img);
    free(message);

    return 0;
}
