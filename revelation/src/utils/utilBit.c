#include "utilBit.h"
#include "../arguments.h"

int get_bit(char the_byte,int which_bit)
{
    if (which_bit > 8 || which_bit < 1 ){
        return -1; //Error, out of range of a byte.
    }
    return((the_byte >> (8 - which_bit)) & 1);
}

uchar setBit(uchar ch, int pos, int bit)
{
    if (bit == 0) ch = ~(1 << pos)& ch;
    if (bit == 1) ch = (1<< pos)| ch;
    return ch;
}

//todo: - Only example - Change
void setMagic(char* hexa){
    char hexstr[] = "48454C50";
    char substr[3];
    char *ptr_hex = hexstr;
    char magic[strlen(hexstr)];

    for (int i = 0, index = 0; i < strlen(hexstr); i += 2, index++){
        strncpy(substr, ptr_hex, 2);
        printf("hex = %s\n", substr);
        int s = strtol(substr, NULL, 16);
        printf("c = %c\n", s);
        ptr_hex += 2;
        magic[index] = s;
    }
    magic[strlen(magic) - 2] = '\0';
    puts(magic);

}