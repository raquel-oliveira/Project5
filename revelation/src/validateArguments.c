//
// Created by Raquel Lopes de Oliveira on 18/01/2016.
//

#include "validateArguments.h"


void setArguments(){
    printf("----------Veryfication file in---------------------\n");
    if (fileIn == NULL){
        fprintf(stderr, "There is no input file.\n");
        exit(-1);
    }

    printf("----------Veryfication Bits---------------------\n");
    if (nbBits == -1){
        nbBits = 1;
    }
    else{
        if(nbBits>8 || nbBits <1){
            fprintf(stderr, "Not possible to pattern a message with this number of bits\n");
            exit(-1);
        }
    }

    printf("----------Veryfication pattern--------------------\n");
    if(pattern == NULL){
        pattern = "DIRECT";
    }
    else{
        flag = validatePattern();
        switch (flag){
            case -1:
                fprintf(stderr, "Not a valid pattern\n");
                exit(-1);
            case 1:
                patternInt = flag; //Direct Pattern
                printf("Direct pattern. \n");
                break;
            case 2:
                fprintf(stderr, "Inverse pattern not implemented\n");
                exit(-2);
            case 3:
                fprintf(stderr, "External spiral pattern not implemented\n");
                exit(-3);
            case 4:
                fprintf(stderr, "Internal spiral pattern not implemented\n");
                exit(-4);
        }
    }

    printf("----------Set Channels--------------------\n");
    if (channels == NULL){
        /*firstChannel = 2;//R
        secondChannel = 1; //G
        thirdChannel = 0;*/ //B
        firstChannel = 2;
        secondChannel = -1;
        thirdChannel = -1;
        printf("First Channel: %d\n", firstChannel);
        printf("Second Channel: %d\n", secondChannel);
        printf("Third Channel: %d\n", thirdChannel);
    }else{
        //TODO: The set channels its not separating correctly
        setChannels();
        printf("First Channel: %d\n", firstChannel);
        printf("Second Channel: %d\n", secondChannel);
        printf("Third Channel: %d\n", thirdChannel);
    }

    printf("----------CheckMagicNumber--------------------\n");
    if(magicHexa == NULL){
        printf("----------MagicNumber NULL-------------------\n");
        magicHexa = "48454C50";
        printf("Hexa Magic Number: %s \n", magicHexa);
        magic = hex_to_str(magicHexa);
        printf("Magic Number: %s \n", magic);
        //magic = "HELP";
    }else{
        printf("Hexa Magic Number: %s \n", magicHexa);
        magic = hex_to_str(magicHexa);
        printf("Magic Number: %s \n", magic);
        //do the transform.
    }

    printf("----------Veryfication Output--------------------\n");
    if(fileOut != NULL){
        output = fopen(fileOut,"r");
        if (output == NULL){
            //TODO: Change this to create the file is not exist
            printf("This file do not exist");
            exit(-1);
        }
    } else {
        fileOut = "output.txt";
        output = fopen(fileOut, "w");
    }


    printf("----------Veryfication format--------------------\n");
    img = cvLoadImage(fileIn, 1); // Second parameter == 1 (RGB) || == 0 (GREY)
    printf("----------Trying to load the image--------------------\n");
    if (img){
        printf("----------isImage--------------------\n");
        if(formatIn == NULL){
            int format = detect_format(fileIn);
            if (format == -1){
                fprintf(stderr, "Not possible to detect format\n");
                exit(-1);
            }
            else{
                printf("Image accepted\n");
            }
        }
        else {
            flag = validateFormat();
            switch (flag) {
                case 0:
                    printf("----------Format accepted--------------------");
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
        printf("Could not open the file\n");
        exit(-3);
    }
}