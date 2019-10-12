#include "button.h"

#define R_OUT 6
#define G_OUT 7
#define B_OUT 8


void setup()
{
    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

void loop() 
{
    set_rgb_led(10, 10, 10);
}

void set_rgb_led(int red, int green, int blue)
{
    analogWrite(R_OUT, 255 - red);
    analogWrite(G_OUT, 255 - green);
    analogWrite(B_OUT, 255 - blue);
}
