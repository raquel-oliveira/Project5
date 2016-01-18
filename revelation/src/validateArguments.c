//
// Created by Raquel Lopes de Oliveira on 18/01/2016.
//

#include "validateArguments.h"


void setArguments(){
    int flag;
    printf("----------Veryfication file in---------------------\n");
    if (fileIn == NULL){
        fprintf(stderr, "There is no input file.\n");
        exit(-1);
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
        firstChannel = 2;
        secondChannel = 1;
        thirdChannel = 0;
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