#include "util.h"

int get_bit(char the_byte,int which_bit) {
    return((the_byte>>(8-which_bit))&1);
}

char intToChar(int a){
    char c = a + '0';
    return c;
}

char intBToChar(int bin){
    char c;
    if (bin == 0){
        c = '0';
    }
    if (bin == 1){
        c = '1';
    }
    return c;
}

uchar setBit(uchar ch, int pos, int bit)
{
    if (bit == 0){ ch = ~(1 << pos)& ch;}
    if (bit == 1){ ch = (1<< pos)| ch;}
    return ch;
}