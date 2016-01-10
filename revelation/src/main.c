#include <string.h>
#include <stdlib.h>
#include "arguments.h"
#include "reveal.h"
#include "utils/checkFormat.h"

#define FIN "-Fin" // Format of file
#define IN "-in" // Path of image
#define OUT "-out" //Path of where to save the message
#define B "-b" // Number of bits
#define C "-c" //Channels
#define P "-p" // Pattern
#define SIZE_MESSAGE 100


int main(int argc, char *argv[]){
    //Default arguments:
    nbBits = 1;
    pattern = "direct";

    //
    IplImage *img = NULL;
    int flag = 0;
    int i = 0;
    uchar *message = malloc(SIZE_MESSAGE);
    char magicNumber[] = "HELP";

    //////////

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
            //firstChannel = strtok(channels, ",");
        }
        else if(strcmp(argv[i],P)==0)
            pattern = argv[i+1];
        else{
            fprintf(stderr, "Tried to put an argument that does not exist.\n");
            exit(-1);
        }
        fileIn = "/Users/Raquel/Desktop/NSA/private/revelation/resource/oi.png";
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
        }
    }else{
        printf("Could not open the file");
        exit(-3);
    }

















    return 0;
}
