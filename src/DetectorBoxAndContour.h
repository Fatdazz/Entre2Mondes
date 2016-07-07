#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class BoxDetector : public ofThread {
public:
  ~BoxDetector();
    
  void setup(ofVideoGrabber *cam, std::string image);
  void draw();
  void drawAlex();
  void mirroredImage();
    
  vector<ofPolyline>& getContours();
    
  void threadedFunction() override;
    
  ofxCv::ContourFinder finder_1, finder_2;
  vector<ofPolyline> contours;
    
  cv::Mat     imageContour,imageFond;
  cv::Mat     imageDouble;
  cv ::Mat    *image1, *image2;
  ofImage mirrored;
  ofVideoGrabber *camera;
  bool        isImage;
  ofImage imageFondImport;
    
};
