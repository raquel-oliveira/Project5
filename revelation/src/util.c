#include "util.h"

int get_bit(char the_byte,int which_bit)
{
    return((the_byte >> (8 - which_bit)) & 1);
}

char intToChar(int a)
{
    return (a + '0');
}

char intBToChar(int bin)
{
    if(bin == 0) return '0';
    else if(bin == 1) return '1';
}

uchar setBit(uchar ch, int pos, int bit)
{
    if (bit == 0) ch = ~(1 << pos)& ch;
    if (bit == 1) ch = (1<< pos)| ch;
    return ch;
}