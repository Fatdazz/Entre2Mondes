//
//  Camera.cpp
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#include "camera.h"

void Camera::setup(CameraType cameraType, int cameraWidth, int cameraHeight){
    this->cameraType = cameraType;
    switch (this->cameraType) {
    case CameraType::KINECTV1:
      {
      shared_ptr<ofxKinect> kinect = make_shared<ofxKinect>();
      //auto kinect = dynamic_pointer_cast<ofxKinect >(camera);
      kinect->init();
      kinect->open();	    
      width = kinect->getWidth();
      height = kinect->getHeight();
      camera = kinect;
      }
      break;
	    
    case CameraType::WEBCAM:
      {
      shared_ptr<ofVideoGrabber> grabber = make_shared<ofVideoGrabber>();
      //auto grabber = dynamic_pointer_cast<ofVideoGrabber>(camera);
      grabber->setup(cameraWidth, cameraHeight);
      width = grabber->getWidth();
      height = grabber->getHeight();
      camera = grabber;
      }
      break;
    }    
}

void Camera::update() {
  camera->update();
}

bool Camera::isFrameNew() {
  return camera->isFrameNew();
}

bool Camera::isConnected(){
  switch (cameraType){
  case CameraType::WEBCAM:
    return dynamic_pointer_cast<ofVideoGrabber>(camera)->isInitialized();
    break;

  case CameraType::KINECTV1:
    return dynamic_pointer_cast<ofxKinect>(camera)->isConnected();
    break;
  }
  
}

ofPixels& Camera::getPixels(){
  return camera->getPixels();
}

int Camera::getHeight(){
    return height;
}

int Camera::getWidth(){
  return width;
}

CameraType Camera::getType() {
  return cameraType;
}


///////////////////////////////////
