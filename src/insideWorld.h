#pragma once

#include "ofMain.h"
#include "Flock2d.h"
#include "parametersGUI.h"

class InsideWorld  {
 public:  
  
  void setup(int width, int height);
  void update();
  void draw();


  ofFbo insideWorld;

  shared_ptr<ParametersGUI> parametersGui;
  
 private:
  
  Flock2d flock;
  ofImage img;

  int NumGroup = 3;

  
  
};
