#define Stair_h
#include "Color.h"

class Stair
{
  public:
    Stair (int sensorPin, int *ledPins, Color *colors);
    int state; // index from array of colors
    int isSteppedOn;
    int sensorPin;
    void stepp();
    void setupPins();
    int  *ledPins;
    void setupLedPins();
  private:
    Color *_colors;
    int _numOfColors;
    const int _numLedPins = 3;
    void writeToLeds();
};

