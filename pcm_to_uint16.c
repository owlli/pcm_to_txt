#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short uint16_t;

int main(int argc, char **argv)
{
	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "w");
	uint16_t *c = (uint16_t *)malloc(2);
	long l;
	fseek(fp1, 0L, SEEK_END);
	l = ftell(fp1) - 2;
	printf("l = %ld\n", l);
	rewind(fp1);
	int cnt = 0;
	uint16_t test_data;

	for(cnt = 0; cnt < l; cnt += 2){

		//printf("cnt = %d\n", cnt);

		fread(c, 2, 1, fp1);

		fprintf(fp2, "%04x\n", *c);

	}

	free(c);
	fclose(fp2);
	fclose(fp1);


	return 0;
}
