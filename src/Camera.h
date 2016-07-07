#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxKinectForWindows2.h"

enum class CameraType {UNKNOWN, WEBCAM, KINECTv1, KINECTv2};

/*
 * Class wrapper over ofxKinect and ofVideoGrabber (more to come)
 * This makes it easy to switch from one camera to another
 * TODO: Kinect V2 support
 */
class Camera {
public:
  Camera();
  ~Camera();

  void setup(CameraType type, int width = 640, int height = 480);
  void draw(int x, int y);
  void draw(int x, int y, int w, int h);
  void update();
  bool isFrameNew();

  ofPixels& getPixels();
	
  int getWidth();
  int getHeight();

  CameraType getType();

  std::unique_ptr<ofBaseVideo>& getCamera();

private:
  std::unique_ptr<ofBaseVideo> camera;
  int width;
  int height;
  CameraType camType;
};

