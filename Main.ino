#include "Stair.h"

  
  // initialize array of Colors
  Color color1(255, 0, 0, 0);
  Color color2(0, 255, 0, 0);
  Color color3(0, 0, 255, 0);
  const int numOfColors = 3;
  Color colors[numOfColors] = {color1, color2, color3};
  
  
  //stair 1
  int led1[3] = {2, 3, 4};
  Stair stair1(3, led1, colors); 
  
  //stair 2
  int led2[3] = {5, 6, 7};
  Stair stair2(4, led2, colors);
  
  // initialize the stairs  
  Stair stairs[2] = {stair1, stair2};
  int numOfStairs = (sizeof(stairs)/sizeof(Stair));


void setup() {
  Serial.begin(9600);


  const int testVar = 5;
  
  for (int i = 0; i < numOfStairs; i++) {
    stairs[i].setupLedPins();
  }
};


void loop() {
  for (int i=0; i < numOfStairs; i++) {
    Stair s = stairs[i];
    int threshold = 15;
    if (analogRead(s.sensorPin) > threshold) {
      //Serial.println("above threshold");
      s.stepp();
    }
  }
};


