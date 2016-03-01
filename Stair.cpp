#include "Stair.h"
#include "Arduino.h"

Stair::Stair(int sensorPin, int ledPins[3], Color colors[])
{
  state = 0; // index of color in colors
  isSteppedOn = false;
  sensorPin = *sensorPin;
  Serial.println(sensorPin);

  _numOfColors = (sizeof(colors)/sizeof(Color));


  // set up pins 
  for (int p = 0; p < _numLedPins ; p++) {
    pinMode(ledPins[p], OUTPUT);
  }  
};

// change the state of the stair once someone has stepped on it
void Stair::stepp()
{
  state = (state + 1) %  _numOfColors;
  writeToLeds();
};

void Stair::writeToLeds()
{
  // get the individual colors for the RGB pins
  int red = _colors[state].red;
  int green = _colors[state].green;
  int blue = _colors[state].blue;
  
  // write to all LED pins
  analogWrite(ledPins[0], red);
  analogWrite(ledPins[1], green);
  analogWrite(ledPins[2], blue);
};
