#include "button.h"
#include "rgb.h"

#define R_OUT 2
#define G_OUT 3
#define B_OUT 4
#define RED 0
#define GREEN 1
#define BLUE 2

auto* ledState = new RGB();
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
    set_rgb_led();
    if (redInc.wasPressed())
    {
    	set_led_color(RED, 16);
    	return;
    }
    if (redDec.wasPressed())
    {
    	set_led_color(RED, -16);
    	return;
    }
    if (greenInc.wasPressed())
    {
    	set_led_color(GREEN, 16);
    	return;
    }
	  if (greenDec.wasPressed())
    {
    	set_led_color(GREEN, -16);
    	return;
    }
    if (blueInc.wasPressed())
    {
    	set_led_color(BLUE, 16);
    	return;
    }
	  if (blueDec.wasPressed())
    {
    	set_led_color(BLUE, -16);
    	return;
    }
}

void set_rgb_led()
{
    analogWrite(R_OUT, 255 - (ledState -> colors)[RED]);
    analogWrite(G_OUT, 255 - (ledState -> colors)[GREEN]);
    analogWrite(B_OUT, 255 - (ledState -> colors)[BLUE]);
}

void set_led_color(int index, int diff)
{
	int sum = (ledState -> colors)[index] + diff;
  if(sum > 255){
    sum = 255;
  }
  if (sum < 0){
    sum = 0;
  }

	(ledState -> colors)[index] = sum;
}
