//
// Created by Raquel Lopes de Oliveira on 18/01/2016.
//

#include "validateArguments.h"


void setArguments(){
    /*
     * Verification os file in
     */
    if (fileIn == NULL){
        fprintf(stderr, "There is no input file.\n");
        exit(-1);
    }

    /*
     * Verification o number of bits.
     * Number default: 1.
     */
    if (nbBits == -1){
        nbBits = 1;
    }
    else{
        if(nbBits>8 || nbBits <1){
            fprintf(stderr, "Not possible to pattern a message with this number of bits\n");
            exit(-1);
        }
    }

    /*
     * Verification of pattern
     * Default pattern: Direct.
     */
    if(pattern == NULL){
        pattern = "DIRECT";
        patternInt = 1;
    }
    else{
        flag = validatePattern();
        switch (flag){
            case -1:
                fprintf(stderr, "Not a valid pattern\n");
                exit(-1);
            case 1:
                patternInt = flag; //Direct Pattern
                break;
            case 2:
                patternInt = flag; //Inverse
                break;
            case 3:
                fprintf(stderr, "External spiral pattern not implemented\n");
                exit(-3);
            case 4:
                fprintf(stderr, "Internal spiral pattern not implemented\n");
                exit(-4);
        }
    }

    /**
     * Setting and validation os Channels
     * Default: Red,Green,Blue
     */
    if (channels == NULL){
        firstChannel = 2;
        secondChannel = 1;
        thirdChannel = 0;
    }else{
        setChannels();
    }

    /**
     * Validation of Magic Number
     * Default: 48454C50
     */
    if(magicHexa == NULL){
        magicHexa = "48454C50";
        magic = hex_to_str(magicHexa); // magic = "HELP"
    }else{
        magic = hex_to_str(magicHexa);
    }

    /**
     * Validation of Output
     * Default: Standart (Console)
     */
    if(fileOut != NULL){
        isStandard = false;
    }
    else {
        isStandard = true;
        fileOut = "output.txt";
    }

    /**
     * Validation of the format of input
     * If there is no format, the program will detect.
     * If the format of the image its different of the argument or it is not a format accepted,
     * the program ends/error.
     */

    img = cvLoadImage(fileIn, 1); // Second parameter == 1 (RGB) || == 0 (GREY)
    if (img){ //Try to load the image by OpenCv
        if(formatIn == NULL){
            int format = detect_format(fileIn);
            if (format == -1){
                fprintf(stderr, "Not possible to detect format\n");
                exit(-1);
            }
        }
        else {
            flag = validateFormat();
            switch (flag) {
                case 0: //Accepted
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
        }
    }else{
        fprintf(stderr, "Could not open the file\n");
        exit(-3);
    }
}