#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


typedef struct t_table /* liste simplement chaînee ordonnée */
{
  char word;
  char *code;
  struct t_table * suivant; /* Pointeur vers l'élément suivant */
}*Table;

// division the string binary every length of 8
char ** split_with_length(char *in){
	int count = 0;

	int len = strlen(in)/8;
	char **out = (char**)malloc(len*sizeof(char *));
	for(int i = 0; i < len; i++)
		out[i] = (char*)malloc(sizeof(char)*8);

	for( ; *in ; in = in + 8){
		strncpy(out[count],in,8);
		//printf("%s\n", in);
		//printf("%d\n",count );
		//printf("%s\n", out[count]);
		count++;
	}
	return out;
			
}

//transform a string binary to a integer decimal
int btd(char *s){
	int number = 0;
	int i,n = 0;
	while(s[n])
		n++;
	for(--n, i = n; i >= 0; i--)
		number|=(s[i]-48)<<(n-i);
	return number;
}

Table creer_table(void)
{
  return NULL; /* Simple, isn't it? */
}

// add element at the head of a table
void ajout_table(Table *table, char word, char *code){
	Table tmp = malloc(sizeof(struct t_table));
	tmp->code = malloc(sizeof(char));
	//printf("sssssss\n");
	tmp->word = word;
	//printf("sssssss\n");
	//tmp->code = strdup(code);
	strcpy(tmp->code,code);
	//printf("sssssss\n");
	tmp->suivant = *table;
	*table = tmp;
	//printf("sssssss\n");
}

//get the dictionary of the symbols
Table getDic(char *in){
	char **out = split_with_length(in);
	char word;
	char *code = malloc(sizeof(char));
	char *c1,*c2,*c3;
	int n = 1 + btd(out[0]);
	Table table;
	table = creer_table();
	
	for(int i = 0; i < n; i++){
		c1 = out[1+3*i];
		c2 = out[2+3*i];
		c3 = out[3+3*i];
		//printf("%s\n",c1);
		//printf("%s\n",c2 );
		//printf("%s\n",c3 );

		word = btd(c1);
		strncpy(code,c3,btd(c2));
		code[btd(c2)] = '\0';
		//printf("%c : %s\n", word, code);
		//printf("\n");
		ajout_table(&table,word,code);
	}

	return table;

}

void imprimer_table(Table table)
{
  for (; table; table=table->suivant)
  	  printf("%c : %s\n", table->word,table->code);
    
}


//get the string which stock message
char * getString(char *in){
	//Table dic = getDic(in);
	int nmblast,sizeIn,start,end,lenstr;
	char **out = split_with_length(in);
	char *s;
	char *string = (char*)malloc(sizeof(char));
	int n = 1 + btd(out[0]);

	nmblast = btd(out[1+3*n]);
	sizeIn = strlen(in);
	start = 8*(2+3*n);
	end = sizeIn + nmblast - 9;
	lenstr = end - start + 1;
	s = in + start;
	
	strncpy(string,s,lenstr);
	string[lenstr]='\0';
	// printf("%s\n", string);
	// printf("%d\n", strlen(string));
	return string;
}

// judge if s1 contained in prefix of s2
int strcontain(char *s1, char *s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int contain = 0;
	if(len1 <= len2){
		for(int i = 0; i < len1 ; i++){
			if(s1[i] == s2[i])
				contain = 1;	
			else return 0;
		}
	}
	return contain;
}

//decompress the message
char * decompress(char *in){
	Table table = getDic(in);
	Table pre;
	imprimer_table(table);
	char word, *code;
	int contain,count = 0;
	char * result = malloc(sizeof(char));
	char * string = getString(in);
	printf("%s\n", string);
	while(*string){
		//printf("%c  ", *string);
		//string++;
		for(pre = table ; pre ; pre = pre->suivant){
			word = pre->word;
			code = pre->code;
			//printf("%c\n", word);
			//printf("%s\n", code);
			//printf("%s\n",string);
			contain = strcontain(code,string);
			//printf("%d\n", contain);
			if(contain == 1){
				string = string + strlen(code);
				result[count] = word;
				//printf("%s\n", result);
				count++;
			}
			
		}	
	}

	return result;
}


int main(int argc, char const *argv[])
{
	//00000100
	//01100100 00000010 00000000
	//01100101 00000010 01000000
	//01100011 00000011 10000000
	//01100010 00000011 10100000
	//01100001 00000010 11000000
	//00000101
	//11111010 00110000 11011011 10001000

	char *in = "000001000110010000000010000000000110010100000010010000000110001100000011100000000110001000000011101000000110000100000010110000000000010111111010001100001101101110001000";
    char *result = decompress(in);
	printf("%s\n", result);

    //printf("%d\n", strlen(in));
	// Table table = getDic(in);
	// imprimer_table(table);

	// char *string = getString(in);
	// printf("%s\n", string);
	// printf("%d\n", strlen(string));
	// printf("\n");

	return 0;
}