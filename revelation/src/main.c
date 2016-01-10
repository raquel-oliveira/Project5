#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arguments.h"
#include "reveal.h"
#include "formatDetector.h"

#define FIN "-Fin" // Format of file
#define IN "-in" // Path of image
#define OUT "-out" //Path of where to save the message
#define B "-b" // Number of bits
#define C "-c" //Channels
#define P "-p" // Pattern

int main(int argc, char *argv[]){

    nbBits = 1;
    pattern = "direct";

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
    }
    return 0;
}
