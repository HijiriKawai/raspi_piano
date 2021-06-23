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
	int freqMultiplier = 1;
	int songSelector = 0;

	if (setup())
	{
		exit(1);
	}

	while (1)
	{
		if (freqMultiplier > FREQ_MULTIPLIER_MAX)
		{
			freqMultiplier = 1;
		}

		if (songSelector > SONG_SELECTOR_MAX)
		{
			songSelector = 0;
		}

		if (digitalRead(GPIO_4_DO))
		{
			tone(TONE_4_DO * freqMultiplier);
			light(PINBASE + GPIO_LED_4_DO);
		}
		else if (digitalRead(GPIO_4_RE))
		{
			tone(TONE_4_RE * freqMultiplier);
			light(PINBASE + GPIO_LED_4_RE);
		}
		else if (digitalRead(GPIO_4_MI))
		{
			tone(TONE_4_MI * freqMultiplier);
			light(PINBASE + GPIO_LED_4_MI);
		}
		else if (digitalRead(GPIO_4_FA))
		{
			tone(TONE_4_FA * freqMultiplier);
			light(PINBASE + GPIO_LED_4_FA);
		}
		else if (digitalRead(GPIO_4_SO))
		{
			tone(TONE_4_SO * freqMultiplier);
			light(PINBASE + GPIO_LED_4_SO);
		}
		else if (digitalRead(GPIO_4_RA))
		{
			tone(TONE_4_RA * freqMultiplier);
			light(PINBASE + GPIO_LED_4_RA);
		}
		else if (digitalRead(GPIO_4_SI))
		{
			tone(TONE_4_SI * freqMultiplier);
			light(PINBASE + GPIO_LED_4_SI);
		}
		else if (digitalRead(GPIO_5_DO))
		{
			tone(TONE_5_DO * freqMultiplier);
			light(PINBASE + GPIO_LED_5_DO);
		}
		else if (digitalRead(GPIO_4_DOs))
		{
			tone(TONE_4_DOs * freqMultiplier);
			light(PINBASE + GPIO_LED_4_DOs);
		}
		else if (digitalRead(GPIO_4_REs))
		{
			tone(TONE_4_REs * freqMultiplier);
			light(PINBASE + GPIO_LED_4_REs);
		}
		else if (digitalRead(GPIO_4_FAs))
		{
			tone(TONE_4_FAs * freqMultiplier);
			light(PINBASE + GPIO_LED_4_FAs);
		}
		else if (digitalRead(GPIO_4_SOs))
		{
			tone(TONE_4_SOs * freqMultiplier);
			light(PINBASE + GPIO_LED_4_SOs);
		}
		else if (digitalRead(GPIO_4_RAs))
		{
			tone(TONE_4_RAs * freqMultiplier);
			light(PINBASE + GPIO_LED_4_RAs);
		}
		else if (digitalRead(OCTAVE_UP))
		{
			freqMultiplier *= 2;
		}
		else if (digitalRead(OCTAVE_DAWN))
		{
			if (freqMultiplier != 1)
			{
				freqMultiplier /= 2;
			}
		}
		else if (digitalRead(OCTAVE_RESET))
		{
			freqMultiplier = 1;
		}
		else if (digitalRead(AUTOMATIC_PLAY))
		{
			automaticPlaying(songSelector);
			songSelector++;
		}
		else
		{
			tone(0);
		}
		delay(WAIT_MS);
	}

	return 0;
}
