#include <string.h>
#include <stdlib.h>
#include "arguments.h"
#include "reveal.h"
#include "utils/validateFormat.h"
#include "utils/validatePattern.h"
#include "utils/validateChannels.h"

#define FIN 0
#define IN 1
#define OUT 2
#define B 3
#define C 4
#define P 5
#define MAGIC 6
#define COMPRESS 7
#define SIZE_MESSAGE 100

//TODO: why optional argument doesn't work?
static struct option long_options[] =
        {
                {"Fin", required_argument, NULL, FIN},
                {"in", required_argument, NULL, IN},
                {"out", required_argument, NULL, OUT},
                {"b", required_argument, NULL, B},
                {"c", required_argument, NULL, C},
                {"p", required_argument, NULL, P},
                {"magic", required_argument, NULL, MAGIC},
                {"compress", no_argument, NULL, COMPRESS},
                {NULL, 0, NULL, 0}
        };

int main(int argc, char *argv[]){
    //defaultArguments:
    pattern = NULL;
    fileIn = NULL;
    fileOut = NULL;
    channels = NULL;
    nbBits = 1;
    uchar *message = malloc(SIZE_MESSAGE);
    char magic[] = "HELP";
    IplImage *img = NULL;

    int long_index=0;
    int opt = 0;

    //TODO: fix why he goes to 0(Fin) if the option is not valid.
    while((opt = getopt_long_only(argc, argv, "" , long_options, &long_index)!= -1)){
        printf("---------Arguments--------------------\n");
        printf("Long index: %d \n Opt: %d \n",long_index,opt);
        switch (long_index){
            case FIN:
                printf("FIN EXE: \n");
                formatIn = optarg;
                printf("Format in: %s \n", formatIn);
                break;
            case IN:
                printf("IN EXE: \n");
                fileIn = optarg;
                printf("Path in: %s \n", fileIn);
                break;
            case OUT:
                printf("OUT EXE: \n");
                fileOut = optarg;
                printf("File Out: %s \n", fileOut);
                break;
            case B:
                printf("B EXE: \n");
                nbBits = atoi(optarg); //do a Try
                printf("Number of bits: %d \n", nbBits);
                break;
            case C:
                printf("CHANNELS EXE: \n");
                channels = optarg;
                printf("Channels: %s \n", channels);
                break;
            case P:
                printf("P EXE: \n");
                pattern = optarg;
                printf("Pattern: %s \n", pattern);
                break;
            case MAGIC:
                printf("MAGIC EXE: \n");
                //magic = optarg;
                break;
            case COMPRESS:
                printf("COMPRESS EXE: \n");
                isCompress = true;
                break;
        }
    }

   int flag;

    fileIn = "Resources/1bit.png";
    //Verifications:
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

    cvReleaseImage(&img);
    free(message);

    return 0;
}