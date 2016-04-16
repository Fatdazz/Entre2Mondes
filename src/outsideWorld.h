#pragma once

#include "ofMain.h"

#include "Camera.h"

class OutsideWorld {
 public:

  

  void setup(int width, int height);

  void update();

  void draw();
  
  ofFbo outsideWorld;
  
 private:

  ofImage img;

  Camera cam;
};
