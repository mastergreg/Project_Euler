/*
 * main.c
 *
 *  Created on: Jul 25, 2010
 *      Author: master
 */

#include <stdio.h>
#include <stdlib.h>

void make_asciiv(FILE *input, FILE *output);
void encode_asciiv(FILE *input,char *key,FILE *output);
void make_text(FILE *input,FILE *output);

int main(int argc, char **argv)
{
	char c, d, e, str1[3], key[3] = "asd";
	int i = 0, j;
	FILE *toencode, *toencode_ascii, *encoded, *decoded_ascii, *decoded,*decoded_text;
	toencode = fopen("toencode.txt", "r");
	toencode_ascii = fopen("toencode_asciivalues.txt", "w");
	encoded = fopen ("encoded.txt","w");
	make_asciiv(toencode, toencode_ascii);
	fclose(toencode);
	fclose(toencode_ascii);
	toencode_ascii = fopen("toencode_asciivalues.txt", "r");
	encode_asciiv(toencode_ascii,key,encoded);
	fclose(toencode_ascii);
	fclose (encoded);
	encoded = fopen ("encoded.txt","r");
	decoded =fopen("decoded.txt","w");
	encode_asciiv(encoded,key,decoded);
	fclose(encoded);
	fclose(decoded);
	decoded=fopen("decoded.txt","r");
	decoded_text=fopen("decoded_text.txt","w");
	make_text(decoded,decoded_text);
	fclose(decoded);
	fclose(decoded_text);
	return 0;
}
void make_text(FILE *input,FILE *output)
{
	char c;
	int ascii=0;
	while ((c = getc(input)) != EOF)
	{
		if (c==',')
		{
			fprintf(output,"%c",ascii);
			ascii=0;
			continue;
		}
		ascii*=10;
		ascii+=c-48;
	}
}
void encode_asciiv(FILE *input,char *key,FILE *output)
{
	char c,*buf;
	int ascii=0;
	buf=key;
	while ((c = getc(input)) != EOF)
	{
		if (c==',')
		{
			if (buf=='\0') buf=key;
			fprintf(output,"%d,",ascii^*buf);
			buf++;
			ascii=0;
			continue;
		}
		ascii*=10;
		ascii+=c-48;
	}
}
void make_asciiv(FILE *input, FILE *output)
{
	char c;
	while ((c = getc(input)) != EOF)
	{
		fprintf(output, "%d,", c);
	}

}
