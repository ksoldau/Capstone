#include "Stair.h"

Stair *stairs;

void setup() {
  Serial.begin(9600);
  
  // initialize array of Colors
  Color oneColor(100, 100, 100, 200);
  const int numOfColors = 1;
  Color colors[numOfColors] = {oneColor};
  
  int led[3] = {1, 1, 1}; 

  // initialize the stairs
  Stair one(3, led, colors); // led pins not legit
  Stair two(4, led, colors); // led pins not legit
  Stair stairs[2] = {one, two}; // number depends on how many stairs
  int numOfStairs = (sizeof(stairs)/sizeof(Stair));

  // initialize the output pins for the stairs
  
  for (int s = 0; s < numOfStairs; s++) {

  }
  

};


void loop() {
  
  for (int i=0; i < (sizeof(stairs)/sizeof(Stair)); i++) {
    Stair s = stairs[i];
    int threshold = 30;
    if (analogRead(s.sensorPin) > threshold) {
      s.stepp();
      Serial.println("pressing");
    }
  }
};


