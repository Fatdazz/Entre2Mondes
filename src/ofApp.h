#pragma once
#include "ofMain.h"
#include "ofxProjectorBlend.h"
#include "ofxXmlSettings.h"
#include "Flock2d.h"
#include "insideWorld.h"
#include "outsideWorld.h"
#include "masking.h"
#include "ofxCv.h"
#include "ofxKinect.h"
#include "controlPanel.h"
#include "Camera.h"
#include "ContourDetectorThread.h"


#define PROJECTOR_COUNT 2
//#define PROJECTOR_WIDTH 1920
//#define PROJECTOR_HEIGHT 1080
#define PROJECTOR_WIDTH 960
#define PROJECTOR_HEIGHT 540
#define PIXEL_OVERLAP 545

class Entre2Mondes : public ofBaseApp{

 public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  // PROJECTOR OUTPUT
  ofxProjectorBlend projectorOutput;
  int projectorTwoOffset;
  int overlaped;
  // END PROJECTOR OUTPUT

  // XML SETTINGS
  ofxXmlSettings xml;
  // END XML SETTINGS
  
  InsideWorld insideWorld;
  OutsideWorld outsideWorld;

  Masking mask;
  ofShader shader;

  MaskGenerator maskGen;

  ofFbo insideWorldMask;

  shared_ptr<ControlPanel> control;

  BoxDetector detector;

  shared_ptr<Camera> camera;

  ofFbo boxes;
  ofImage windowMask;

  ContourDetectorThread boxContour;

  ofImage tmpBoxContour;

  vector<ofPolyline> poly;

};
