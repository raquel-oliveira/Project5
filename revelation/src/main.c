#include <stdio.h>
#include <stdlib.h>
#include "reveal.h"
#include "formatDetector.h"

#define SIZE_MESSAGE 100

int main(int argc, char *argv[]) {
    IplImage *img = NULL;
    int i = 0;
    uchar *message = malloc(SIZE_MESSAGE);
    char help[] = "HELP";
    int flag = 0;
    char *path = "../resource/1bitRedDirect.png";

    //argument(argc, argv);
    //printf("%s", getArg("fileIn"));

    //img = cvLoadImage(getArg("fileIn") , 1); // Second parameter == 1 (RGB) || == 0 (GREY)
    img = cvLoadImage("../resource/1bitRedDirect.png", 1);
    /*flag = loadImage(img, path);
    printf("%d", flag);
    if (flag == 5){
        printf("Format not accepted");
        exit(5);
    }
    else if (flag == 6){
        printf("Could not open the file");
    }*/
    int *channel  = malloc(sizeof(int));
    //flag = directPattern(img, channel, atoi(getArg("nbBits")), help, message);
    //flag = directPattern(img, 1, help, message);
    flag = revealText(img, 1, help, message);
    switch(flag){
        case 0: while(message[i] != '\0')
                {
                    printf("%c", message[i]);
                    i++;
                }
                printf("\n\n");
                break;
            
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
