#pragma once

#include "ofMain.h"
#include "Flock2d.h"
#include "parametersGUI.h"
#include "masking.h"
#include "ofxCv.h"
#include "controlPanel.h"
#include "BoidsThread.h"
#include "DetectorBoxAndContour.h"

/*
 * This class is the entry point for all the things that appear on the boxes
 * and on the edges of the windows and other objects.
 */

class InsideWorld  {
 public:  
  
  void setup(int width, int height,BoxDetector  *_detector);
  void update();
  void draw();
  
  ofFbo insideWorld;  
  
  //shared_ptr<ParametersGUI> parametersGui;
  
 private:
  
  //Flock2d flock;
  threadedBoids   boids;
  
  
  int NumGroup = 2;
  
};
