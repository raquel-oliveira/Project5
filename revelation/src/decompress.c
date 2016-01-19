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

char ** split_with_length(char *in){
	int count = 0;

	int len = strlen(in)/8;
	char **out = (char**)malloc(len*sizeof(char *));
	for(int i = 0; i < len; i++)
		out[i] = (char*)malloc(sizeof(char)*8);

	for( ; *in ; in = in + 8){
		strncpy(out[count],in,8);
		//printf("%s\n", in);
		printf("%d\n",count );
		printf("%s\n", out[count]);
		count++;
	}
	return out;
			
}

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

void ajout_table(Table *table, char word, char *code){
	Table tmp = malloc(sizeof(struct t_table));
	//printf("sssssss\n");
	tmp->word = word;
	//printf("sssssss\n");
	tmp->code = strdup(code);
	//printf("sssssss\n");
	tmp->suivant = *table;
	*table = tmp;
	//printf("sssssss\n");
}

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

// char * decompress(char *in){
// 	Table dic = getDic(in);
// 	char * string = getString(in);
// }



int main(int argc, char const *argv[])
{
	char *in = "00000001011001000000001000000000011001010000001001000000000001000001000100010000";
                                                                              //000100010001
	Table table = getDic(in);
	imprimer_table(table);

	char *string = getString(in);
	printf("%s\n", string);
	printf("%d\n", strlen(string));
	printf("\n");
	
	//char **out = split_with_length(in);
	//printf("%d\n", sizeof(out));
	// int i = 0;
	// while(i < 4){
	// 	printf("%s\n", out[i]);
	// 	i++;
	// }

	// int b = btd("01100100");
	// char c = b;
	// printf("%d\n", b);
	// printf("%c\n", c);
	

	return 0;
}