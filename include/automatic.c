#include "automatic.h"
#include "define.h"
#include "raspiio.h"
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int numberOfLine(char *cp)
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

void play(score_t score)
{
	int freqMultiplier = 1;

	for (size_t i = 0; i < score.length; i++)
	{
		switch (score.scale)
		{
		case DO_4:
			tone(TONE_4_DO * freqMultiplier);
			light(PINBASE + GPIO_LED_4_DO);
			break;

		case RE_4:
			tone(TONE_4_RE * freqMultiplier);
			light(PINBASE + GPIO_LED_4_RE);
			break;

		case MI_4:
			tone(TONE_4_MI * freqMultiplier);
			light(PINBASE + GPIO_LED_4_MI);
			break;

		case FA_4:
			tone(TONE_4_FA * freqMultiplier);
			light(PINBASE + GPIO_LED_4_FA);
			break;

		case SO_4:
			tone(TONE_4_SO * freqMultiplier);
			light(PINBASE + GPIO_LED_4_SO);
			break;

		case RA_4:
			tone(TONE_4_RA * freqMultiplier);
			light(PINBASE + GPIO_LED_4_RA);
			break;

		case SI_4:
			tone(TONE_4_SI * freqMultiplier);
			light(PINBASE + GPIO_LED_4_SI);
			break;

		case DO_5:
			tone(TONE_5_DO * freqMultiplier);
			light(PINBASE + GPIO_LED_5_DO);
			break;

		case DOs_4:
			tone(TONE_4_DOs * freqMultiplier);
			light(PINBASE + GPIO_LED_4_DOs);
			break;

		case REs_4:
			tone(TONE_4_REs * freqMultiplier);
			light(PINBASE + GPIO_LED_4_REs);
			break;

		case FAs_4:
			tone(TONE_4_FAs * freqMultiplier);
			light(PINBASE + GPIO_LED_4_FAs);
			break;

		case SOs_4:
			tone(TONE_4_SOs * freqMultiplier);
			light(PINBASE + GPIO_LED_4_SOs);
			break;

		case RAs_4:
			tone(TONE_4_RAs * freqMultiplier);
			light(PINBASE + GPIO_LED_4_RAs);
			break;

		default:
			tone(0);
			break;
		}
	}
}

int automaticPlaying(title_e number)
{
	FILE *fp;
	char *fname;
	int ret, scale, length;
	int counter = 0;

	switch (number)
	{
	case WHENTHESAINTSGOMARCHING:
		fname = "./score/WhenTheSaintsGoMarching.csv";
		break;

	case TWINKLELITTLESTAR:
		fname = "./score/TwinkleLittleStar.csv";
		break;

	case MARYHADALITTLELAMB:
		fname = "./score/MaryHadALittleLamb.csv";
		break;

	default:
		fname = "./score/WhenTheSaintsGoMarching.csv";
		break;
	}

	size_t size = numberOfLine(fname);

	score_t score[size];

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("%sが開けません \n", fname);
		return -1;
	}

	while ((ret = fscanf(fp, "%d,%d", &scale, &length) != EOF))
	{
		score[counter].scale = scale;
		score[counter].length = length;
		counter++;
	}

	for (size_t i = 0; i <= size; i++)
	{
		play(score[i]);
		delay(500);
	}
	tone(0);

	fclose(fp);

	return 0;
}