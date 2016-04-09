#pragma once

#include "ofMain.h"
#include "Flock2d.h"
#include "parametersGUI.h"
#include "masking.h"
#include "ofxCv.h"

class InsideWorld  {
 public:  
  
  void setup(int width, int height);
  void update();
  void draw();


  
  ofFbo insideWorld;
  ofFbo insideWorldMask;
  
  shared_ptr<ParametersGUI> parametersGui;
  
 private:
  
  Flock2d flock;
  ofImage img;

  /* MASK */
  ofImage staticMask;

  BoxMaskGenerator gen;
  ofImage dynamicMask;    
  
  ofxCv::ContourFinder insideWorldMaskContours;
  

  /* END MASK */
  
  int NumGroup = 3;
  
};
