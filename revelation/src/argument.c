#include "argument.h"

#define FIN "-Fin"
#define IN "-in"
#define OUT "-out"
#define B "-b"
#define C "-c"
#define P "-p"

char *formatIn, *fileIn, *fileOut, *nbBits, *channels, *pattern;

void argument(int argc, char *argv[]){
    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i],FIN)==0)
            formatIn = argv[i+1];
        else if(strcmp(argv[i],IN)==0)
            fileIn = argv[i+1];
        else if(strcmp(argv[i],OUT)==0)
            fileOut = argv[i+1];
        else if(strcmp(argv[i],B)==0)
            nbBits = argv[i+1];
        else if(strcmp(argv[i],C)==0)
            channels = argv[i+1];
        else if(strcmp(argv[i],P)==0)
            pattern = argv[i+1];
    }
}

char * getArg(char *what){
    if(strcmp(what,"formatIn")==0){
        if(what == NULL) printf("Argument invalide\n");
        return formatIn;
    }
    else if(strcmp(what,"fileIn")==0){
        if(what == NULL) printf("Argument invalide\n");
        return fileIn;
    }
    else if(strcmp(what,"fileOut")==0){
        if(what == NULL) printf("Argument invalide\n");
        return fileOut;
    }
    else if(strcmp(what,"nbBits")==0){
        if(what == NULL) return "1";
        return nbBits;
    }
    else if(strcmp(what,"pattern")==0){
        if(what == NULL) return "Direct";
        return pattern;
    }
    else{
        printf("Argument invalide\n");
        return NULL;
    }

}


// int main(int argc, char *argv[])
// {
// 	argument(argc,argv);
// 	printf("%s\n", formatIn);
// 	char *ch = getArg("formatIn");
// 	printf("%s\n", ch);
// 	return 0;
// }