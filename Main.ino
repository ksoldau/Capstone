#include "Stair.h"

Stair *stairs;
const int testVar = 5;
void setup() {
  Serial.begin(9600);

  // initialize array of Colors
  Color color1(255, 0, 0, 0);
  Color color2(0, 255, 0, 0);
  Color color3(0, 0, 255, 0);
  const int numOfColors = 3;
  Color colors[numOfColors] = {color1, color2, color3};
  
  //stair 1
  int led1[3] = {2, 3, 4};
  Stair stair1(3, led1, colors); 
  //Serial.println(stair1.sensorPin);

  //stair 2
  int led2[3] = {5, 6, 7};
  Stair stair2(3, led2, colors);

  // initialize the stairs  
  Stair stairs[2] = {stair1, stair2}; // number depends on how many stairs
  int numOfStairs = (sizeof(stairs)/sizeof(Stair));
};


void loop() {
  int test = stairs[0].sensorPin;
  Serial.println(test);
  for (int i=0; i < (sizeof(stairs)/sizeof(Stair)); i++) {
    Stair s = stairs[i];
    int threshold = 30;
    if (analogRead(s.sensorPin) > threshold) {
      s.stepp();
      Serial.println("pressing");
    }
  }
};


