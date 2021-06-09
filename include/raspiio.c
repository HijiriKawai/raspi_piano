#include "raspiio.h"
#include "define.h"
#include <softTone.h>
#include <wiringPi.h>

void tone(int freq)
{
	softToneWrite(BUZ_PORT, freq);
}

void LEDon(int port)
{
	digitalWrite(port, 1);
}

void LEDoff(int port)
{
	digitalWrite(port, 0);
}

void light(int port)
{
	LEDon(port);
	delay(50);
	LEDoff(port);
}