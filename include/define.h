#ifndef DEFINE_H
#define DEFINE_H

/* I/Oエキスパンダのport */
#define PINBASE 100
#define I2CADDRESS 0x20

/** GPIOポートの設定 **/
#define BUZ_PORT 27			/* ブザー */
#define OCTAVE_UP 21		/* 1オクターブ上げるスイッチ */
#define OCTAVE_DAWN 20	/*1オクターブ下げるスイッチ*/
#define OCTAVE_RESET 16 /*音階をデフォルトに戻す*/
#define AUTOMATIC_PLAY 5 /* 自動演奏 */
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
#define GPIO_LED_4_DO 0 /* ドのLED */
#define GPIO_LED_4_RE 1 /* レのLED */
#define GPIO_LED_4_MI 2 /* ミのLED */
#define GPIO_LED_4_FA 3 /* ファのLED */
#define GPIO_LED_4_SO 4 /* ソのLED */
#define GPIO_LED_4_RA 5 /* ラのLED */
#define GPIO_LED_4_SI 6 /* シのLED */
#define GPIO_LED_5_DO 7 /* ドのLED */
#define GPIO_LED_4_DOs 11 /* ド♯のLED */
#define GPIO_LED_4_REs 12 /* レ♯のLED */
#define GPIO_LED_4_FAs 13 /* ファ♯のLED */
#define GPIO_LED_4_SOs 14 /* ソ♯のLED */
#define GPIO_LED_4_RAs 15 /* ラ♯のLED */

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

/* 最大オクターブ */
#define FREQ_MULTIPLIER_MAX 16

/* 最大曲数 */
#define SONG_SELECTOR_MAX 2

#define ERROR -1

#endif