#include "argument.h"

#define FIN "-Fin" // Format of file
#define IN "-in" // Path of image
#define OUT "-out" //Path of where to save the message
#define B "-b" // Number of bits
#define C "-c" //Channels
#define P "-p" // Pattern

char *formatIn, *fileIn, *fileOut, *channels, *pattern;
int nbBits;

//Define defaults:
nbBits = 1;
pattern = "direct";

void argument(int argc, char *argv[]){
    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i],FIN)==0)
            formatIn = argv[i+1];
        else if(strcmp(argv[i],IN)==0)
            fileIn = argv[i+1];
        else if(strcmp(argv[i],OUT)==0)
            fileOut = argv[i+1];
        else if(strcmp(argv[i],B)==0)
            nbBits = atoi(argv[i+1]);
        else if(strcmp(argv[i],C)==0)
            channels = argv[i+1];
        else if(strcmp(argv[i],P)==0)
            pattern = argv[i+1];
    }
}

char * getArg(char *what){
    if(strcmp(what,"formatIn")==0){
        return formatIn;
    }
    else if(strcmp(what,"fileIn")==0){
        if(what == NULL) printf("Argument invalide\n");
        return fileIn;
    }
    else if(strcmp(what,"fileOut")==0){
        if(what == NULL) printf("Argument invalide\n");
        return fileOut;
    }
    else if(strcmp(what,"nbBits")==0){
        if(what == NULL) {return "1";}
        return nbBits;
    }
    else if(strcmp(what,"pattern")==0){
        if(what == NULL) return "Direct";
        return pattern;
    }
    else if(strcmp(what,"channel")==0){
        if(what == NULL) return "Direct";
        return pattern;
    }
    else{
        printf("Argument invalide\n");
        return NULL;
    }

}