#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8_t;

int char_to_dec(char c)
{
	if (c >= 48 && c <= 57)
		return c-48;
	else if(c >= 65 && c <= 70)
		return c-65+10;
	else if(c >= 97 && c <= 102)
		return c-97+10;
	else
		return -1;
}

int main(int argc, char **argv)
{
	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "w");
	int cnt = 0;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	uint8_t tmp;

	while ((read = getline(&line, &len, fp1)) != -1) {
		if (*line == 10 || *(line + 1) == 10 || *(line + 2) == 10 || *(line + 3) == 10) {
			continue;
		} else {
			tmp = char_to_dec(*(line + 2)) * 16 + char_to_dec(*(line + 3));
			fwrite(&tmp, 1, 1, fp2);
			tmp = char_to_dec(*(line)) * 16 + char_to_dec(*(line + 1));
			fwrite(&tmp, 1, 1, fp2);
		}
	}

	free(line);
	fclose(fp2);
	fclose(fp1);
	
	return 0;

}


