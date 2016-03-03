#ifndef Stair_H
#define Stair_H

#include "Stair.h"
#include "Arduino.h"

Stair::Stair(int sensPin, int *lp, Color *colors)
{
  state = 0; // index of color in colors
  isSteppedOn = false;
  sensorPin = sensPin;
//  Serial.print("lp[0] = ");
//  Serial.println(ledPins[0]);

  ledPins = lp;
//
//  Serial.print("ledPins[0] = ");
//  Serial.println(ledPins[0]);
  _colors = colors;
  
  _numOfColors = sizeof(colors)/sizeof(colors[0]);
};

void Stair::setupLedPins()
{
//  // set up pins 
  Serial.print("in setupLedPins()...");
  Serial.print("ledPins[0] = ");
  Serial.println(ledPins[0]);
  
  for (int p = 0; p < _numLedPins ; p++) {
    pinMode(ledPins[p], OUTPUT);
  }  
}

// change the state of the stair once someone has stepped on it
void Stair::stepp()
{
  Serial.print("_numOfColors:");
  Serial.println(_numOfColors);
  Serial.println("firststate:");
  Serial.println(state);
  Stair::state = (state + 1) %  3;
  Serial.println(state);
  writeToLeds();
};

void Stair::writeToLeds()
{
  //Serial.println("in writeToLeds()");
  // get the individual colors for the RGB pins
  int red = _colors[state].red;
  int green = _colors[state].green;
  int blue = _colors[state].blue;
  
  // write to all LED pins
  digitalWrite(ledPins[0], red);
  digitalWrite(ledPins[1], green);
  digitalWrite(ledPins[2], blue);
};

#endif
