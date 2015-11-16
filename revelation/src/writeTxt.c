#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *fp;
	char ch;
	if((fp = fopen("../resource/text.txt","wt+"))==NULL){
		printf("Cannot open file\n");
		getchar();
		exit(1);
	}
	printf("Input the text:\n");
	ch = getchar();
	while(ch!='\n'){
		fputc(ch,fp);
		ch = getchar();
	}
	rewind(fp);
	ch = fgetc(fp);
	while(ch!=EOF){
		putchar(ch);
		ch = fgetc(fp);
	}
	printf("\n");
	fclose(fp);
}