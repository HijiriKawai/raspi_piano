#include "automatic.h"
#include "define.h"
#include "raspiio.h"
#include <mcp23017.h>
#include <softTone.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int main()
{
	//初期化
	if (wiringPiSetupGpio() == -1)
	{
		exit(1);
	}

	if (mcp23017Setup(PINBASE, I2CADDRESS) == -1)
	{
		printf("Setup Fail\n");
		exit(1);
	}

	softToneCreate(BUZ_PORT);
	pinMode(OCTAVE_UP, INPUT);
	pinMode(OCTAVE_DAWN, INPUT);
	pinMode(OCTAVE_RESET, INPUT);
	pinMode(GPIO_4_DO, INPUT);
	pinMode(GPIO_4_RE, INPUT);
	pinMode(GPIO_4_MI, INPUT);
	pinMode(GPIO_4_FA, INPUT);
	pinMode(GPIO_4_SO, INPUT);
	pinMode(GPIO_4_RA, INPUT);
	pinMode(GPIO_4_SI, INPUT);
	pinMode(GPIO_5_DO, INPUT);
	pinMode(GPIO_4_DOs, INPUT);
	pinMode(GPIO_4_REs, INPUT);
	pinMode(GPIO_4_FAs, INPUT);
	pinMode(GPIO_4_SOs, INPUT);
	pinMode(GPIO_4_RAs, INPUT);
	pinMode(PINBASE + GPIO_LED_4_DO, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_RE, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_MI, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_FA, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_SO, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_RA, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_SI, OUTPUT);
	pinMode(PINBASE + GPIO_LED_5_DO, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_DOs, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_REs, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_FAs, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_SOs, OUTPUT);
	pinMode(PINBASE + GPIO_LED_4_RAs, OUTPUT);

	while (1)
	{
		if (digitalRead(GPIO_4_DO) == 1)
		{
			automaticPlaying(WHENTHESAINTSGOMARCHING);
		}
	}
}