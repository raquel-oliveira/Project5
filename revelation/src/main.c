#include <string.h>
#include <stdlib.h>
#include "arguments.h"
#include "validateArguments.h"
#include "pattern/direct.h"
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
                //printf("B EXE: \n");
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
                magicHexa = optarg;
                printf("MAGIC number: %s \n", magicHexa);
                break;
            case COMPRESS:
               // printf("COMPRESS EXE: \n");
                isCompress = true;
                break;
            case SHOW:
                //printf("SHOW EXE: \n");
                isShow = true;
                break;
            default:
                //TODO: try to take it off the message: pattern: unrecognized option"
                printf("Not a recognized argument\n");
                exit(-1);
        }
    }

    fileIn = "Resources/1bitRedJOAO.png";
    //Verifications:
   // setArguments();
   /* printf("%d", patternInt);
    printf("----------Make reveal--------------------\n");
    flag = patternInt;
    switch (flag){
        case 1: //is direct
            printf("STARTING REVEAL DIRECT\n");
            flag = revealDirect();
            break;
        case 2: //Is reverse
            printf("STARTING REVEAL REVERSE\n");
            flag = revealReverse();
            break;
    }
    switch (flag) {
        case 0:
            printf("CASE OK\n");
            if(isStandard){
                output = fopen(fileOut, "r");
                char c;
                if (output) {
                    while ((c = getc(output)) != EOF)
                        putchar(c);
                    fclose(output);
                }
            }else{
                printf("Reveal in the path: %s", fileOut);
                exit(1);
            }
            break;
        case -2: {
            fprintf(stderr, "Error Trying to access bit\n");
            exit(-2);
        }

        case -3: {
            unlink(fileOut);
            fprintf(stderr, "There is no magic number\n");
            exit(-3);
        }
    }*/
    printf("END REVEAL\n");

    printf("----------Check if is compress---------------------\n");
    if(!isCompress) {
        printf("----------Is not compress---------------------\n");

    }
    else{
        printf("----------Is compress---------------------\n");

        //output = fopen("Resources/Compress/dictionaryAndMessage", "r");
        //output = fopen("Resources/Compress/7aComplete", "r");
        //output = fopen("Resources/Compress/arbCompEquilibreComplete", "r");
        //output = fopen("Resources/Compress/messageTestComplete", "r");
        output = fopen("Resources/Compress/charly", "r");
        //fileOut = "Resources/Compress/dictionaryAndMessage";
        //output = fopen(fileOut, "r");

        Dictionary *a ;
        a = createDictionary(output);
        if (a == NULL){
            printf("Dictionary not created\n Could not open the file \n");
            exit(EXIT_FAILURE);
        }

       /* FILE * afterDic;
        afterDic = fopen("afterDic.txt", "r");*/

        FILE * out;
        int k;
        out = fopen("afterDic.txt", "r");
        //out = fopen("Resources/Compress/onlyMessage", "r");
        //out = fopen("Resources/Compress/7aJustMessage", "r");
        //out = fopen("Resources/Compress/arbCompEquilibreJustMessage", "r");
        //out = fopen("Resources/Compress/messageTestJustMessage", "r");
       // out = fopen("Resources/Compress/charlyOnlyMessage", "r");
        k = decompress(a,out);
        if(k == 0){
            printf("Decompress finished \n");
           // exit(0);
        }
        if(isShow){
            printf("-----------SHOW DICTIONARY---------\n");
            printDictionary(a);
        }
       // free(a); free(output);
    }


    //cvReleaseImage(&img);
    //free(message);
    return 0;
}