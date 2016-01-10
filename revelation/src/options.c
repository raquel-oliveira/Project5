//
// Created by Raquel Lopes de Oliveira on 10/01/2016.
//

#include "options.h"
#include <getopt.h>

int main(int argc, char *argv[]) {
    int opt= 0;

    //Specifying the expected options
    static struct option long_options[] = {
            {"formatIN",      optional_argument,       0,  'Fin' },
            {"pathIn", required_argument,       0,  'in' },
            {"pathOut",    optional_argument, 0,  'out' },
            {"bits",   optional_argument, 0,  'b' },
            {"channel",   required_argument, 0,  'c' },//how to require, 3 arguments?
            {"pattern",   optional_argument, 0,  'p' },
            {"magicNumber",   optional_argument, 0,  'magic' },
            {0,           0,                 0,  0   }
    };

    int long_index =0;
    //int getopt_long(int argc, char * const argv[],const char *optstring,const struct option *longopts, int *longindex);
    while ((opt = getopt_long(argc, argv,"Fininoutcpmagic:"/*O que eu boto aqui?*/,
                              long_options, &long_index )) != -1) {
        switch (opt) {
            case 'Fin' :
                break;
            case 'in' :
                break;
            case 'out' :
                break;
            case 'b' :
                bits = atoi(optarg);
                break;
            case 'c' :
                break;
            case 'p' :
                break;
            case 'magic' :
                break;
            default: print_usage();
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}