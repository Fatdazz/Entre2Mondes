#pragma once

#include "ofMain.h"
#include "FboGlitch.h"

class OutsideWorld {
public:

  

  void setup(int width, int height);

  void update();

  void draw();
  
  ofFbo outsideWorld;
  
private:

  ofImage img;
  std::vector<FboGlitch> glitches;
  constexpr int numGlitches;


};
