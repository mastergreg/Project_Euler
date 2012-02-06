/*
 * main.c
 *
 *  Created on: Jul 23, 2010
 *      Author: master
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int failure;
int list[19] =
{ 97, 99, 100, 101, 103, 104, 105, 106, 107, 110, 111, 113, 115, 116, 117, 118,
		119, 121, 122 };

void decode_asciiv(char *input, char *key, char *output);
void read_file_to_ascii(FILE *input,char *asciiv);
int accept(char c);
int find_the(char *input);
int main(void)
{
	char  key[] = "aaa";
    failure = 0;
	char text[1202];
	char outtext[1202];
    char nothing;
	FILE *coded, *decoded;
	coded = fopen("cipher1.txt", "r");
	read_file_to_ascii(coded, text);
	fclose(coded);
    printf("\n\n\n");
    for (int i = 0 ; i < 1201 ; ++i )
    {
        printf("%d,",text[i]);
    }
	decoded = fopen("final", "w");
	for (int i = 0; i < 19; i++)
	{
		key[0] = list[i];
		for (int j = 0; j < 19; j++)
		{
			key[1] = list[j];
			for (int k = 0; k < 19; k++)
			{

				key[2] = list[k];

				decode_asciiv(text, key, outtext);
                find_the(outtext);
                if ( failure == 0 )
                {
                    for ( int i = 0 ; i < 1201 ; ++i )
                    {
                        printf("%c",outtext[i]);
                    }
                    scanf("%c",&nothing);
                }


			}
		}
	}
	fclose(decoded);
	return 0;
}

void read_file_to_ascii(FILE *input,char *asciiv)
{
    int ascii;
    for( int i = 0 ; i < 1201 ; i++)
    {
        fscanf(input,"%d",&ascii);
        asciiv[i] = ( char ) ascii;
        fscanf(input,",");
    }
}
void decode_asciiv(char *input,char *key, char *output)
{
	char buf, character;
	int i;
    failure = 0;
	for (i = 0; i < 1201; i++)
	{
		//if (buf == '\0')
		buf = key[i%3];
		character = input[i] ^ buf;
		sprintf(output, "%c", character);
        //if ( !accept( character ) )
        //{
        //    failure = 1;
        //    printf("\nFAIL\n");
        //    return;
        //}
        //if ( character < 0 ) 
        //{
        //    fprintf(stdout,"FAIL\n");
        //    break;
        //}
		//buf++;
	}
	fprintf(stdout, "\n\n%s\n\n", key);
}


int find_the(char *input)
{
    char *the = "apple";
    for( int i = 0 ; i < 1198 ; ++i )
    {
        if ( strncmp(&input[i],the,5)==0 )
        {
            printf("found one!\n");
            failure = 0;
            return 1;
        }

    }
    failure=1;
    return 0;
}
int accept(char c)
{
    if( c == ' ' || ( c >= 97 && c <= 122) || ( c >= 65 && c <= 90) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
