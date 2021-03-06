#include <string.h>
#include <stdlib.h>
#include "arguments.h"
#include "validateArguments.h"
#include "pattern/direct.h"
#include "utils/file.h"
#include "pattern/reverse.h"
#include "decompress/decompress.h"
#include "decompress/dictionary.h"


#define FIN 0
#define IN 1
#define OUT 2
#define B 3
#define C 4
#define P 5
#define MAGIC 6
#define COMPRESS 7
#define SHOW 8
#define SIZE_MESSAGE 100

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
                {"show", no_argument, NULL, SHOW},
                {NULL, 0, NULL, 0}
        };

int main(int argc, char *argv[]){
    pattern = NULL;
    fileIn = NULL;
    fileOut = NULL;
    channels = NULL;
    nbBits = -1;
    magicHexa = NULL;
    magic = NULL;
    img = NULL;
    isCompress = false;
    isShow = false;

    int long_index=0;
    int opt = 0;
    while((opt = getopt_long_only(argc, argv, "" , long_options, &long_index)!= -1)){
        switch (long_index){
            case FIN:
                formatIn = optarg;
                break;
            case IN:
                fileIn = optarg;
                break;
            case OUT:
                fileOut = optarg;
                break;
            case B:
                nbBits = atoi(optarg); //TODO: do a Try
                break;
            case C:
                channels = optarg;
                break;
            case P:
                pattern = optarg;
                break;
            case MAGIC:
                magicHexa = optarg;
                break;
            case COMPRESS:
                isCompress = true;
                break;
            case SHOW:
                isShow = true;
                break;
            default:
                printf("Not a recognized argument\n");
                exit(-1);
        }
    }

    setArguments();

    flag = patternInt;
    switch (flag){
        case 1: //is direct
            flag = revealDirect();
            break;
        case 2: //Is reverse
            flag = revealReverse();
            break;
    }
    switch (flag) {
        case -2: {
            if(isCompress){ unlink("afterReveal.txt");}
            fprintf(stderr, "Error Trying to access bit\n");
            exit(-2);
        }

        case -3: {
            unlink(fileOut);
            if(isCompress){ unlink("afterReveal.txt");}
            fprintf(stderr, "There is no magic number\n");
            exit(-3);
        }
    }

    if(!isCompress) {
        if (flag == 0) {
            if (isStandard) {
                printFile(fileOut);
                unlink(fileOut);
            } else {
                printf("Reveal in the path: %s\n", fileOut);
                exit(1);
            }

        }
    }
    else{
        if(isStandard){
            fileOut = "output.txt";
        }
        Dictionary *d = malloc(sizeof(Dictionary));
        flag = decompress("afterReveal.txt", d);
        switch (flag){
            case 0:{
                unlink("afterReveal.txt");
                if(isShow){
                    printDictionary(d);
                    printFileBinary(fileOut);
                }
                if(isStandard){
                    printFile(fileOut);
                    unlink(fileOut);
                }
                break;
            }
            case -1:
                fprintf(stderr, "Problem to open the file\n");
                exit(-1);
            case -2:{
                fprintf(stderr, "Problem when try to malloc the keys of elements\n");
                exit(-2);
            }
            case -4:
                fprintf(stderr, "Number of bits used in the last byte incorrect\n");
                exit(-4);
            case -5:{
                fprintf(stderr, "The quantity of elements in the dictionary its incorrect\n");
                exit(-5);
            }
            case -6:{
                fprintf(stderr, "Problem when try to malloc the buffer\n");
                exit(-6);
            }
            case -7:{
                fprintf(stderr, "problem to malloc elements\n");
                exit(-7);
            }

        }

    }

    cvReleaseImage(&img);
    return 0;
}