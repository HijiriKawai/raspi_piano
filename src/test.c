#include "score.h"
#include <stdio.h>
#include <stdlib.h>

int gyousuu(char *cp);

int main(void)
{
	FILE *fp;
	char *fname = "../score/WhenTheSaintsGoMarching.csv";
	int ret, scale, length;
	int counter = 0;

	int a = gyousuu(fname);

	score score[a];

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("%sファイルが開けません¥n", fname);
		return -1;
	}

	while ((ret = fscanf(fp, "%d,%d", &scale, &length) != EOF))
	{
		score[counter].scale = scale;
		score[counter].length = length;

		counter++;
	}

	counter = 0;
	while (counter <= a)
	{
		printf("%d %d\n", score[counter].scale, score[counter].length);
		counter++;
	}

	fclose(fp);
	return 0;
}

int gyousuu(char *cp)
{
	FILE *fp;
	char buf[256];
	size_t read_size;
	int line = 0;

	if ((fp = fopen(cp, "r")) == NULL)
	{
		return -1;
	}

	while ((read_size = fread(buf, 1, 256, fp)) > 0)
	{
		for (size_t i = 0; i < read_size; i++)
		{
			if (buf[i] == '\n')
				line++;
		}
	}

	return line;
}