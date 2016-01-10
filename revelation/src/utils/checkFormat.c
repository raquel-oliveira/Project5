//
// Created by Raquel Lopes de Oliveira on 10/01/2016.
//
#include "checkFormat.h"
#include "formatDetector.h"
#include "arguments.h"

#define PNG 1;
#define BMP 2;
#define PPM 3;
#define PGM 4;


int check_extension(){
    int userFormat = -1;
    if (formatIn == "PNG") {
        userFormat = 1;
    }
    else if (formatin == "BRP"){
        userFormat = 2;
    }
    else if (formatin == "PPM"){
        userFormat = 3;
    }
    else if (formatin == "PGM"){
        userFormat = 4;
    }

    if (userFormat > 4 && userFormat < 1){
        return -1; //not a format accepted by the program
    }

    if (userFormat != detect_format(fileIn)){
        return -2; //Format given by the user doesn' correspont to the format of image
    }
    else{
        return 0; //ok
    }
}
