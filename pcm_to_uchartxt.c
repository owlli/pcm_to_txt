#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "w");
	unsigned char *c = (unsigned char *)malloc(1);
	int cnt = 0;

	while(!feof(fp1)){
		cnt++;
		fread(c, 1, 1, fp1);

		fprintf(fp2, "0x%02x,", *c);
		if(cnt % 10 == 0)
			fprintf(fp2, "\n");
		else
			fprintf(fp2, " ");


	}

	free(c);
	fclose(fp2);
	fclose(fp1);


	return 0;
}
