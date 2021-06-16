#include "automatic.h"
#include "define.h"
#include "raspiio.h"
#include "setup.h"
#include <mcp23017.h>
#include <softTone.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int main(void)
{
	int freq_multiplier = 1;

	if (setup())
	{
		exit(1);
	}

	while (1)
	{
		if (freq_multiplier > FREQ_MULTIPLIER_MAX)
		{
			freq_multiplier = 1;
		}

		if (digitalRead(GPIO_4_DO))
		{
			tone(TONE_4_DO * freq_multiplier);
			light(PINBASE + GPIO_LED_4_DO);
		}
		else if (digitalRead(GPIO_4_RE))
		{
			tone(TONE_4_RE * freq_multiplier);
			light(PINBASE + GPIO_LED_4_RE);
		}
		else if (digitalRead(GPIO_4_MI))
		{
			tone(TONE_4_MI * freq_multiplier);
			light(PINBASE + GPIO_LED_4_MI);
		}
		else if (digitalRead(GPIO_4_FA))
		{
			tone(TONE_4_FA * freq_multiplier);
			light(PINBASE + GPIO_LED_4_FA);
		}
		else if (digitalRead(GPIO_4_SO))
		{
			tone(TONE_4_SO * freq_multiplier);
			light(PINBASE + GPIO_LED_4_SO);
		}
		else if (digitalRead(GPIO_4_RA))
		{
			tone(TONE_4_RA * freq_multiplier);
			light(PINBASE + GPIO_LED_4_RA);
		}
		else if (digitalRead(GPIO_4_SI))
		{
			tone(TONE_4_SI * freq_multiplier);
			light(PINBASE + GPIO_LED_4_SI);
		}
		else if (digitalRead(GPIO_5_DO))
		{
			tone(TONE_5_DO * freq_multiplier);
			light(PINBASE + GPIO_LED_5_DO);
		}
		else if (digitalRead(GPIO_4_DOs))
		{
			tone(TONE_4_DOs * freq_multiplier);
			light(PINBASE + GPIO_LED_4_DOs);
		}
		else if (digitalRead(GPIO_4_REs))
		{
			tone(TONE_4_REs * freq_multiplier);
			light(PINBASE + GPIO_LED_4_REs);
		}
		else if (digitalRead(GPIO_4_FAs))
		{
			tone(TONE_4_FAs * freq_multiplier);
			light(PINBASE + GPIO_LED_4_FAs);
		}
		else if (digitalRead(GPIO_4_SOs))
		{
			tone(TONE_4_SOs * freq_multiplier);
			light(PINBASE + GPIO_LED_4_SOs);
		}
		else if (digitalRead(GPIO_4_RAs))
		{
			tone(TONE_4_RAs * freq_multiplier);
			light(PINBASE + GPIO_LED_4_RAs);
		}
		else if (digitalRead(OCTAVE_UP))
		{
			freq_multiplier *= 2;
		}
		else if (digitalRead(OCTAVE_DAWN))
		{
			if (freq_multiplier != 1)
			{
				freq_multiplier /= 2;
			}
		}
		else if (digitalRead(OCTAVE_RESET))
		{
			freq_multiplier = 1;
		}
		else if (digitalRead(AUTOMATIC_PLAY))
		{
			automaticPlaying(WHENTHESAINTSGOMARCHING);
		}
		else
		{
			tone(0);
		}
		delay(WAIT_MS);
	}

	return 0;
}
