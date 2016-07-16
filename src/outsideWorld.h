#pragma once

#include "ofMain.h"
#include "GlitchManager.h"

constexpr int NUM_GLITCHES = 5;

class OutsideWorld {
public:

  

  void setup(int width, int height);

  void update();

  void draw();
  
  ofFbo outsideWorld;
  
private:

  ofImage img;

  uint64_t currentTime;

  std::vector<Glitch> glitches;
  std::vector<uint64_t> randomTimes;
  std::vector<uint64_t> previousTimes;

};
