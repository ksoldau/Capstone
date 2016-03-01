#define Stair_h
#include "Color.h"

class Stair
{
  public:
    Stair (int sensorPin, int ledPins[3], Color colors[]);
    int state; // index from arary of colors
    int isSteppedOn;
    int sensorPin;
    void stepp();
    void setupPins();
    int  ledPins[3];
  private:
    Color _colors[];
    int _numOfColors;
    const int _numLedPins = 3;
    void writeToLeds();
};

