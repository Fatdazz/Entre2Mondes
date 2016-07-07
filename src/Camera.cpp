#include "Camera.h"



Camera::Camera() {
  camType = CameraType::UNKNOWN;
  width = 0;
  height = 0;
  camera = nullptr;
}


Camera::~Camera() {
}

void Camera::setup(CameraType type, int width, int height) {
	camType = type;
	if (camType == CameraType::WEBCAM) {
	  std::unique_ptr<ofVideoGrabber> grabber = std::unique_ptr<ofVideoGrabber>();
	  grabber->setup(width, height);
	  camera = std::move(grabber);
	  width = dynamic_pointer_cast<ofVideoGrabber>(camera)->getWidth();
	  height = dynamic_pointer_cast<ofVideoGrabber>(camera)->getHeight();
	} else if (camType == CameraType::KINECTv1) {
	  std::unique<ofxKinect> kinect = std::unique_ptr<ofxKinect>();
	  kinect->init();
	  kinect->open();
	  camera = std::move(kinect);
	  width = std::dynamic_pointer_cast<ofxKinect>(camera)->getWidth();
	  height = std::dynamic_pointer_cast<ofxKinect>(camera)->getHeight();
	} else if (camType == CameraType::KINECTv2) {
	  std::unique_ptr<ofxKinectForWindows2> kinect = std::unique_ptr<ofxKinectForWindows2>();
	  kinect->open();
	  kinect->initColorSource();
	  camera = std::move(kinect);
	  width = std::dynamic_poiter_cast<ofxKinectForWindows2>(camera)->getWidth();
	  height = std::dynamic_poiter_cast<ofxKinectForWindows2>(camera)->getHeight();
	}
}

ofPixels& Camera::getPixels() {
  return camera->getPixels();
}

int Camera::getWidth() {
  return width;
}

int Camera::getHeight() {
  return height;
}

void Camera::draw(int x, int y) {
  if (camType == CameraType::WEBCAM) {
    std::dynamic_pointer_cast<ofVideoGrabber>(camera)->draw(x, y);
  }
  else if (camType == CameraType::KINECTv1) {
    std::dynamic_pointer_cast<ofxKinect>(camera)->draw(x, y);
  } else if (camType == CameraType::KINECTv2) {
    std::dynamic_pointer_cast<ofxKinectForWindows2>(camera)->getColorSource()->draw(x, y);
  }
}

void Camera::draw(int x, int y, int w, int h) {
  if (camType == CameraType::WEBCAM) {
    std::dynamic_pointer_cast<ofVideoGrabber>(camera)->draw(x, y, w, h);
  }
  else if (camType == CameraType::KINECTv1) {
    std::dynamic_pointer_cast<ofxKinect>(camera)->draw(x, y, w, h);
  } else if (camType == CameraType::KINECTv2){
    std::dynamic_pointer_cast<ofxKinectForWindows2>(camera)->getColorSource()->draw(x, y, w, h);
  }
}

void Camera::update() {
  camera->update();
}

bool Camera::isFrameNew() {
  return camera->isFrameNew();
}
