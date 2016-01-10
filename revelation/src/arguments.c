//
// Created by Raquel Lopes de Oliveira on 10/01/2016.
//

#include "arguments.h"
#include <string.h>
#include <stdio.h>


char *formatIn, *fileIn, *fileOut, *channels, *firstChannel, *secondChannel, *thirdChannel, *pattern;

int nbBits;

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