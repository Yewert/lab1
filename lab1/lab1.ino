#include "button.h"
#include "rgb.h"

#define R_OUT 2
#define G_OUT 3
#define B_OUT 4

RGB ledState(0, 0, 0);
Button redInc(8);
Button greenInc(9);
Button blueInc(10);
Button redDec(5);
Button greenDec(6);
Button blueDec(7);


void setup()
{
    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

void loop() 
{
    set_rgb_led(ledState);
    if (redInc.wasPressed())
    {
    	ledState.red = inc_number_with_max(ledState.red, 16);
    	return;
    }
    if (redDec.wasPressed())
    {
    	ledState.red = dec_number_with_min(ledState.red, 16);
    	return;
    }
    if (greenInc.wasPressed())
    {
    	ledState.green = inc_number_with_max(ledState.green, 16);
    	return;
    }
	  if (greenDec.wasPressed())
    {
    	ledState.green = dec_number_with_min(ledState.green, 16);
    	return;
    }
    if (blueInc.wasPressed())
    {
    	ledState.blue = inc_number_with_max(ledState.blue, 16);
    	return;
    }
	  if (blueDec.wasPressed())
    {
    	ledState.blue = dec_number_with_min(ledState.blue, 16);
    	return;
    }
}

void set_rgb_led(RGB rgb)
{
    analogWrite(R_OUT, 255 - rgb.red);
    analogWrite(G_OUT, 255 - rgb.green);
    analogWrite(B_OUT, 255 - rgb.blue);
}

int inc_number_with_max(int val, int inc)
{
	int sum = val + inc;

	return sum > 255 ? 255 : sum;
}

int dec_number_with_min(int val, int dec)
{
	int diff = val - dec;

	return diff < 0 ? 0 : diff;
}
