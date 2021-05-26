#include <wiringPi.h>
#include <softTone.h>
#include "raspiio.h"
#include "define.h"

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