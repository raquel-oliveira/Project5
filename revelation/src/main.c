#include <stdio.h>
#include <stdlib.h>
#include "reveal.h"
#include "formatDetector.h"

#define SIZE_MESSAGE 100

int main(int argc, char *argv[]) {

    IplImage *img = NULL; //image
    int i = 0; //Index for the message
    uchar *message = malloc(SIZE_MESSAGE);
    char magicNumber[] = "HELP"; //default magic number
    int flag = 0;
    //char* path = "../../dissimulation/Matrice/output/result.png";
    //char* path = "../../../test/result2bits.png";
    char* path = "../resource/1bitRedDirect.png";

    img = cvLoadImage(path, 1); // Second parameter == 1 (RGB) || == 0 (GREY)
    if (img){
        flag = checkFormat(path);
        if (flag == -1){
            printf("Format not accepted\n");
            exit(-1);
        }
    }else{
        printf("Could not open the file\n");
        exit(-2);
    }

    flag = reveal(img, 1, magicNumber, message);

    switch(flag){
        case 0: while(message[i] != '\0')
                {
                    printf("%c", message[i]);
                    i++;
                }
                printf("\n\n");
                break;
            
        case -1: {
            printf("Error while reallocating memory for message\n");
            exit(-1);
        } break;

        case -2: {
            printf("Error Trying to acess bit\n");
            exit(-2);
        } break;

        case -3: printf("There is no magic number \n");
                exit(-3);
    }

    cvReleaseImage(&img);
    free(message);

    return 0;
}
