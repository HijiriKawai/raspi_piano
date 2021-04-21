#include <stdio.h>
#include <wiringPi.h>
#include <softTone.h>
void tone(int freq);

/** GPIOポートの設定 **/
#define BUZ_PORT 27			/* ブザー */
#define OCTAVE_UP 21		/* 1オクターブ上げるスイッチ */
#define OCTAVE_DAWN 20	/*1オクターブ下げるスイッチ*/
#define OCTAVE_RESET 16 /*音階をデフォルトに戻す*/
#define GPIO_4_DO 14		/* ド */
#define GPIO_4_RE 15		/* レ */
#define GPIO_4_MI 17		/* ミ */
#define GPIO_4_FA 22		/* ファ */
#define GPIO_4_SO 10		/* ソ */
#define GPIO_4_RA 9			/* ラ */
#define GPIO_4_SI 11		/* シ */
#define GPIO_5_DO 7			/* ド */
#define GPIO_4_DOs 18		/* ド♯ */
#define GPIO_4_REs 23		/* レ♯ */
#define GPIO_4_FAs 24		/* ファ♯ */
#define GPIO_4_SOs 25		/* ソ♯ */
#define GPIO_4_RAs 8		/* ラ♯ */

/** 音階の設定 **/
#define TONE_4_DO 262	 /* ド */
#define TONE_4_RE 294	 /* レ */
#define TONE_4_MI 330	 /* ミ */
#define TONE_4_FA 349	 /* ファ */
#define TONE_4_SO 392	 /* ソ */
#define TONE_4_RA 440	 /* ラ */
#define TONE_4_SI 494	 /* シ */
#define TONE_5_DO 523	 /* ド */
#define TONE_4_DOs 277 /* ド♯ */
#define TONE_4_REs 311 /* レ♯ */
#define TONE_4_FAs 370 /* ファ♯ */
#define TONE_4_SOs 415 /* ソ♯ */
#define TONE_4_RAs 466 /* ラ♯ */

/** ウェイト時間 **/
#define WAIT_MS 100 /* ミリ秒 */

int main(void)
{
	int freq_multiplier = 1;
	//初期化
	if (wiringPiSetupGpio() == -1)
		return 1;
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

	while (1)
	{
		if (digitalRead(GPIO_4_DO) == 1)
		{
			tone(TONE_4_DO * freq_multiplier);
			printf("%d\n", TONE_4_DO * freq_multiplier);
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

void tone(int freq)
{
	softToneWrite(BUZ_PORT, freq);
}