//
//  Camera.h
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#pragma once

#include "ofMain.h"
#include "ofxKinect.h"


enum class CameraType {WEBCAM, KINECTV1, KINECTV2};

class Camera {

public:    
    
  void setup(CameraType, int cameraWidth = 640, int cameraHeight = 480);
  void update();
  bool isFrameNew();
  bool isConnected();
  ofPixels& getPixels();
  int  getWidth();
  int  getHeight();
  CameraType getType();
    
private:
    //shared_ptr<ofxKinect>   kinect;
    //shared_ptr<ofVideoGrabber> grabber;
    shared_ptr<ofBaseVideo> camera;
    CameraType cameraType;
    int width, height;
};





