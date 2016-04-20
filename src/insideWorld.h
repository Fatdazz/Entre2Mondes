#pragma once

#include "ofMain.h"
#include "Flock2d.h"
#include "parametersGUI.h"
#include "masking.h"
#include "ofxCv.h"
#include "controlPanel.h"
#include "threadedBoids.h"


class InsideWorld  {
 public:  
  
  void setup(int width, int height);
  void update();
  void draw();
  
  ofFbo insideWorld;
  ofFbo insideWorldMask;
  
shared_ptr<ParametersGUI> parametersGui;
  
 private:
  
  //Flock2d flock;
    threadedBoids   boids;
  ofImage img;
    
  /* MASK */
  ofImage staticMask;

  ofImage dynamicMask;    
  
  ofxCv::ContourFinder insideWorldMaskContours;
  ofxCv::ContourFinder insideWorldMaskContoursStatic;
  
  cv::Mat resizedStream;

  ofImage streamImage;

  /* END MASK */
  
  int NumGroup = 3;
  
};
