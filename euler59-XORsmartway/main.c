#include <stdio.h>

void read_file_to_ascii(FILE *input, int *asciiv);

int main(int argc, char **argv)
{
	int keyprobe,flag1,flag2,flag3,buffer;
	int text[1201], i;
	FILE *coded;
	coded = fopen("cipher1.txt", "r");
	read_file_to_ascii(coded, text);
	for (keyprobe = 97; keyprobe < 123; keyprobe++)
	{
		flag1=0;
		flag2=0;
		flag3=0;
		for (i = 0; i < 1201; i++)
		{
			buffer=text[i]^keyprobe;
			if (buffer==32) flag1=1;
			if (buffer=='a') flag2=1;
			if (buffer=='b') flag3=1;
		}
		if (flag1==1 && flag2==1 && flag3==1) printf("%d\n",keyprobe);

	}
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
