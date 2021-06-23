#ifndef AUTOMATIC_H
#define AUTOMATIC_H

typedef enum
{
	DO_4,
	RE_4,
	MI_4,
	FA_4,
	SO_4,
	RA_4,
	SI_4,
	DO_5,
	DOs_4,
	REs_4,
	FAs_4,
	SOs_4,
	RAs_4
} scale_e;

typedef enum
{
	WHENTHESAINTSGOMARCHING,
	TWINKLELITTLESTAR,
	MARYHADALITTLELAMB
} title_e;

typedef struct
{
	scale_e scale;
	int length;
} score_t;

int numberOfLine(char *cp);
void play(score_t score);
int automaticPlaying(title_e number);

#endif