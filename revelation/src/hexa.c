#include <stdio.h>
 
char a2x(char ch)
{
    switch(ch)
    {
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
    case 'a':
        return 10;
    case 'B':
    case 'b':
        return 11;
    case 'C':
    case 'c':
        return 12;
    case 'D':
    case 'd':
        return 13;
    case 'E':
    case 'e':
        return 14;
    case 'F':
    case 'f':
        return 15;
    default:
        break;;
    }
 
    return 0;
}

void hex_to_str(char hex[],char str[]){
    int i;
 
    i = 0;
    while(hex[i])
    {
        str[i >> 1] = (a2x(hex[i]) << 4) | a2x(hex[i + 1]);
        i += 2;
    }
    str[i >> 1] = '\0';


}
 
int main(int argc, char* argv[])
{
    char hex[] = "48454C50";
    char string[20];
    hex_to_str(hex , string);
    
 
    printf("%s\n", string);
 
    return 0;
}