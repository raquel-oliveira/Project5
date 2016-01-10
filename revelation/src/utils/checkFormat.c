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
    int userFormat;
    int format = detect_format(fileIn);

    if (formatIn == "PNG") {
        userFormat = 1;
    }
    else if (formatIn == "BRP"){
        userFormat = 2;
    }
    else if (formatIn == "PPM"){
        userFormat = 3;
    }
    else if (formatIn == "PGM"){
        userFormat = 4;
    }
    else if (formatIn == NULL){
        if (format != -1){
            return 0; // The program accept the format
        }
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
