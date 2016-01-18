#include <string.h>
#include <stdlib.h>
#include "arguments.h"
#include "validateArguments.h"
#include "reveal.h"

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
    img = NULL;

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


    fileIn = "Resources/1bit.png";
    //Verifications:
    setArguments();

    cvReleaseImage(&img);
    free(message);

    return 0;
}