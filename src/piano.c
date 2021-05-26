#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <mcp23017.h>
#include <softTone.h>
#include "raspiio.h"
#include "define.h"

int main(void)
{
	int freq_multiplier = 1;
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

	while (1)
	{
		if (freq_multiplier > FREQ_MULTIPLIER_MAX)
		{
			freq_multiplier = 1;
		}

		if (digitalRead(GPIO_4_DO) == 1)
		{
			tone(TONE_4_DO * freq_multiplier);
			LEDon(PINBASE + GPIO_LED_4_DO);
			delay(50);
			LEDoff(PINBASE + GPIO_LED_4_DO);
		}
		else if (digitalRead(GPIO_4_RE) == 1)
		{
			tone(TONE_4_RE * freq_multiplier);
		}
		else if (digitalRead(GPIO_4_MI) == 1)
		{
			tone(TONE_4_MI * freq_multiplier);
		}
		else if (digitalRead(GPIO_4_FA) == 1)
		{
			tone(TONE_4_FA * freq_multiplier);
		}
		else if (digitalRead(GPIO_4_SO) == 1)
		{
			tone(TONE_4_SO * freq_multiplier);
		}
		else if (digitalRead(GPIO_4_RA) == 1)
		{
			tone(TONE_4_RA * freq_multiplier);
		}
		else if (digitalRead(GPIO_4_SI) == 1)
		{
			tone(TONE_4_SI * freq_multiplier);
		}
		else if (digitalRead(GPIO_5_DO) == 1)
		{
			tone(TONE_5_DO * freq_multiplier);
		}
		else if (digitalRead(GPIO_4_DOs) == 1)
		{
			tone(TONE_4_DOs * freq_multiplier);
		}
		else if (digitalRead(GPIO_4_REs) == 1)
		{
			tone(TONE_4_REs * freq_multiplier);
		}
		else if (digitalRead(GPIO_4_FAs) == 1)
		{
			tone(TONE_4_FAs * freq_multiplier);
		}
		else if (digitalRead(GPIO_4_SOs) == 1)
		{
			tone(TONE_4_SOs * freq_multiplier);
		}
		else if (digitalRead(GPIO_4_RAs) == 1)
		{
			tone(TONE_4_RAs * freq_multiplier);
		}
		else if (digitalRead(OCTAVE_UP) == 1)
		{
			freq_multiplier *= 2;
		}
		else if (digitalRead(OCTAVE_DAWN) == 1)
		{
			if (freq_multiplier != 1)
			{
				freq_multiplier /= 2;
			}
		}
		else if (digitalRead(OCTAVE_RESET) == 1)
		{
			freq_multiplier = 1;
		}

		else
		{
			tone(0);
		}
		delay(WAIT_MS);
	}

	return 0;
}
