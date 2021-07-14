#include "setup.h"
#include "define.h"
#include "raspiio.h"
#include <mcp23017.h>
#include <softTone.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int setup()
{
	//初期化
	if (wiringPiSetupGpio() == -1)
	{
		printf("セットアップに失敗しました\n");
		return ERROR;
	}

	if (mcp23017Setup(PINBASE, I2CADDRESS) == -1)
	{
		printf("セットアップに失敗しました\n");
		return ERROR;
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

	for (size_t i = 0; i < 7; i++)
	{
		LEDon(PINBASE + i);
	}
	for (size_t i = 11; i < 15; i++)
	{
		LEDon(PINBASE + i);
	}
	tone(TONE_5_DO * 4);
	delay(100);
	tone(0);
	for (size_t i = 0; i < 7; i++)
	{
		LEDoff(PINBASE + i);
	}
	for (size_t i = 11; i < 15; i++)
	{
		LEDoff(PINBASE + i);
	}

	return 0;
}