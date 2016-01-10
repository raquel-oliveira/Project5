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
    char* path = "/Users/Raquel/Desktop/NSA/private/revelation/resource/oi.png";

   // flag = reveal(img, 1, help, message, 1, NULL, NULL);
    flag = reveal(img, 1, help, message, 2, -1, -1);
    //flag = reveal(img, 1, help, message);

    switch(flag){
        case 0: while(message[i] != '\0')
            {
                printf("%c", message[i]);
                i++;
            }
            printf("\n\n");
            break;

        case -1: {
            printf("Error while reallocating memory for message");
            exit(-1);
        } break;

        case -2: {
            printf("Error Trying to access bit");
            exit(-2);
        } break;

        case -3: printf("There is no magic number");
            exit(-3);
    }

    cvReleaseImage(&img);
    free(message);

    return 0;
}
