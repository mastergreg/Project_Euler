/*
 * main.c
 *
 *  Created on: Jul 23, 2010
 *      Author: master
 */

#include <stdio.h>
#include <stdlib.h>
int list[18] =
{ 97, 99, 100, 101, 103, 104, 105, 106, 107, 110, 111, 113, 115, 116, 117, 118,
		119, 121 };

void decode_asciiv(int *input, char *key, FILE *output);
void read_file_to_ascii(FILE *input, int *asciiv);
int main(int argc, char **argv)
{
	char  key[3] = "aaa";
	int i, j, k,text[1202];
	FILE *coded, *decoded;
	coded = fopen("cipher1.txt", "r");
	read_file_to_ascii(coded, text);
	fclose(coded);
	decoded = fopen("final", "w");
	for (i = 0; i < 18; i++)
	{
		key[0] = list[i];
		for (j = 0; j < 18; j++)
		{
			key[1] = list[j];
			for (k = 0; k < 18; k++)
			{

				key[2] = list[k];

				decode_asciiv(text, key, decoded);

			}
		}
	}
	fclose(decoded);
	return 0;
}

void read_file_to_ascii(FILE *input, int *asciiv)
{
	char c;
	int ascii;
	while ((c = getc(input)) != EOF)
	{
		if (c == ',')
		{
			*asciiv = ascii;
			asciiv++;
			ascii = 0;
			continue;
		}
		ascii *= 10;
		ascii += c - 48;
	}
}
void decode_asciiv(int *input, char *key, FILE *output)
{
	char *buf, character;
	int i;
	buf = key;
	for (i = 0; i < 1202; i++)
	{
		if (buf == '\0')
			buf = key;
		character = *input ^ *buf;
		fprintf(output, "%d,", character);
		buf++;
		input++;
	}
	fprintf(output, "\n\n%s\n\n", key);
}
