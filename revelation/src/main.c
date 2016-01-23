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
                {"show", no_argument, NULL, SHOW},
                {NULL, 0, NULL, 0}
        };

int main(int argc, char *argv[]){
    pattern = NULL; //"direct";
    fileIn = NULL;
    fileOut = NULL;
    channels = NULL;// "Red,Green,Blue";
    nbBits = -1; //1;
    uchar *message = malloc(SIZE_MESSAGE);
    magicHexa = NULL; //"48454C50";
    magic = NULL; //"HELP";
    img = NULL;
    isCompress = false;
    isShow = false;

    int long_index=0;
    int opt = 0;
    //TODO: fix why he goes to 0(Fin) if the option is not valid.
    while((opt = getopt_long_only(argc, argv, "" , long_options, &long_index)!= -1)){
        switch (long_index){
            case FIN:
                formatIn = optarg;
                printf("Format in: %s \n", formatIn);
                break;
            case IN:
                fileIn = optarg;
                printf("Path in: %s \n", fileIn);
                break;
            case OUT:
                fileOut = optarg;
                printf("File Out: %s \n", fileOut);
                break;
            case B:
                nbBits = atoi(optarg); //TODO: do a Try
                printf("Number of bits: %d \n", nbBits);
                break;
            case C:
                channels = optarg;
                printf("Channels: %s \n", channels);
                break;
            case P:
                pattern = optarg;
                printf("Pattern: %s \n", pattern);
                break;
            case MAGIC:
                magicHexa = optarg;
                printf("MAGIC number: %s \n", magicHexa);
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
            fprintf(stderr, "Error Trying to access bit\n");
            exit(-2);
        }

        case -3: {
            unlink(fileOut);
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
                printf("Reveal in the path: %s", fileOut);
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
                if(isStandard){ printFile(fileOut); unlink(fileOut);}
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

        }
        if(isShow){
            printf("-----------SHOW DICTIONARY---------\n");
            printDictionary(d);

        }
       // unlink("afterReveal.txt");
       // free(a); free(output);
    }

    cvReleaseImage(&img);
    free(message);
    return 0;
}