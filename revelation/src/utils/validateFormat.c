//
// Created by Raquel Lopes de Oliveira on 10/01/2016.
//
#include "validateFormat.h"

#define PNG 1;
#define BMP 2;
#define PPM 3;
#define PGM 4;


int validateFormat(){
    int userFormat;
    int format = detect_format(fileIn);
    int i = 0;
    while(formatIn[i])
    {
        formatIn[i] = toupper(formatIn[i]);
        i++;
    }

    if (strcmp(formatIn,"PNG") == 0) {
        userFormat = 1;
    }
    else if (strcmp(formatIn,"BMP") == 0){
        userFormat = 2;
    }
    else if (strcmp(formatIn,"PPM") == 0){
        userFormat = 3;
    }
    else if (strcmp(formatIn,"PGM") == 0){
        userFormat = 4;
    }
    else {
        return -1;
    }
    if (userFormat != format){
        return -2; //Format given by the user doesn' correspont to the format of image
    }
    else{
        return 0; //ok
    }
}
