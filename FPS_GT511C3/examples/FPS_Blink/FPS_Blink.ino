#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"

// Hardware setup - FPS connected to:
//	  digital pin 4(arduino rx, fps tx)
//	  digital pin 5(arduino tx - 560ohm resistor - fps tx - 1000ohm resistor - ground)
//		this voltage divider brings the 5v tx line down to about 3.2v so we dont fry our fps

FPS_GT511C3 fps(4, 5);

void setup()
{
	Serial.begin(9600);
	fps.UseSerialDebug = true; // so you can see the messages in the serial debug screen
	fps.Open();
}


void loop()
{
	// FPS Blink LED Test
	fps.SetLED(true);
	delay(1000);
	fps.SetLED(false);
	delay(1000);
}
