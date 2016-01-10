#include <string.h>
#include <stdlib.h>
#include "arguments.h"
#include "reveal.h"
#include "utils/checkFormat.h"
#define RED 2
#define GREEN 1
#define BLUE 0

#define FIN "-Fin" // Format of file
#define IN "-in" // Path of image
#define OUT "-out" //Path of where to save the message
#define B "-b" // Number of bits
#define C "-c" //Channels
#define P "-p" // Pattern
#define MAGIC "-magic"
#define SIZE_MESSAGE 100

int main(int argc, char *argv[]){
    const char delimiter[2] = ",";
    if (argc == 1){
        fprintf(stderr, "Insufficient arguments.");
        exit(-1);
    }
    int flag = 0;
    int i = 0;

    //Default arguments:
    pattern = "direct";
    fileIn = NULL;
    fileOut = NULL;
    channels = NULL;
    nbBits = 1;
    uchar *message = malloc(SIZE_MESSAGE);
    char magic[] = "HELP";
    IplImage *img = NULL;


   for(int i = 0; i < argc; i++){
        if(strcmp(argv[i],FIN)==0)
            formatIn = argv[i+1];
        else if(strcmp(argv[i],IN)==0)
            fileIn = argv[i+1];
        else if(strcmp(argv[i],OUT)==0)
            fileOut = argv[i+1];
        else if(strcmp(argv[i],B)==0)
            nbBits = atoi(argv[i+1]);
        else if(strcmp(argv[i],C)==0) {
            channels = argv[i + 1];
        }
        else if(strcmp(argv[i],P)==0)
            pattern = argv[i+1];
        //else if(strcmp(argv[i],MAGIC)==0)
           // magicNumber = argv[i + 1]; //not using
       /*else{
            fprintf(stderr, "Tried to put an argument that does not exist.\n");
            exit(-1);
        }*/
    }

    if (fileIn == NULL){
        fprintf(stderr, "There is no input file.\n");
        exit(-1);
    }

    img = cvLoadImage(fileIn, 1); // Second parameter == 1 (RGB) || == 0 (GREY)
    if (img){
        flag = check_extension();
        switch(flag) {
            case 0:
                break;
            case -1:
                fprintf(stderr, "%s is not a format accepted\n", formatIn);
                exit(-1);
            case -2:
                fprintf(stderr, "This format is not the format of the image\n");
                exit(-2);
            case -3:
                fprintf(stderr, "Not a format valid\n");
                exit(-2);
        }
    }else{
        printf("Could not open the file");
        exit(-3);
    }

    flag = reveal(img, 1, magic, message, 2, 1, 0); //default 1 bit, red green blue

    switch(flag){
        case 0: while(message[i] != '\0')
            {
                printf("%c", message[i]);
                i++;
            }
            printf("\n\n");
            break;

        case -1: {
            fprintf(stderr, "Error while reallocating memory for message");
            exit(-1);
        } break;

        case -2: {
            fprintf(stderr, "Error Trying to access bit");
            exit(-2);
        } break;

        case -3:
            fprintf(stderr, "There is no magic number");
            exit(-3);
    }


    cvReleaseImage(&img);
    free(message);

    return 0;
}
