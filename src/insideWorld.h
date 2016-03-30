#pragma once

#include "ofMain.h"
#include "Flock2d.h"


class InsideWorld {

 public:  
  
  void setup(int width, int height);
  void update();
  void draw();

  ofFbo insideWorld;
  
 private:
  
 
  Flock2d flock;
  ofImage img;

  int NumGroup = 3;

};
