#pragma once

#include "ofMain.h"
#include "FboGlitch.h"


constexpr int numGlitches = 1;

class OutsideWorld {
public:

  

  void setup(int width, int height);

  void update();

  void draw();
  
  ofFbo outsideWorld;
  
private:

  ofImage img;
  FboGlitch glitches;


  float currentTime;
  float previousTime;


};
