
#include "getopt.h"
#include "stdio.h"

#define FIN 0
#define IN 1
#define OUT 2
#define B 3
#define C 4
#define P 5
#define MAGIC 6
#define COMPRESS 7
static struct option long_options[] =
        {
                {"Fin", optional_argument, NULL, FIN},
                {"in", required_argument, NULL, IN},
                {"out", optional_argument, NULL, OUT},
                {"b", optional_argument, NULL, B},
                {"c", optional_argument, NULL, C},
                {"p", optional_argument, NULL, P},
                {"magic", optional_argument, NULL, MAGIC},
                {"compress", no_argument, NULL, COMPRESS},
                {NULL, 0, NULL, 0}
        };


int main(int argc, char *argv[]){
    int long_index=0;
    int opt = 0;
    while((opt = getopt_long_only(argc, argv, "" , long_options, &long_index)!= -1)){
        printf("oi");
        printf("%d", long_index);
        switch (long_index){
            case FIN: printf("finn\n");
                break;
            case IN:
                printf("In\n");
                break;
            case OUT:
                printf("Out\n");
                break;
            case B:
                printf("bbb\n");
                break;
            case C:
                printf("ccc\n");
                break;
            case P:
                printf("p\n");
                break;
            case MAGIC:
                printf("magic\n");
                break;
            case COMPRESS:
                printf("compress/nn");
                break;
        }
    }
}