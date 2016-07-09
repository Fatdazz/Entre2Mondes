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
#include "DetectorBoxAndContour.h"


#define PROJECTOR_COUNT 2
//#define PROJECTOR_WIDTH 1920
//#define PROJECTOR_HEIGHT 1080
#define PROJECTOR_WIDTH 640
#define PROJECTOR_HEIGHT 480
#define PIXEL_OVERLAP 0

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

  // Projector overlaping
  ofxProjectorBlend projectorOutput;
  int projectorTwoOffset;
  int overlaped;

  // XML settings
  ofxXmlSettings xml;  

  // Inside world
  InsideWorld insideWorld;

  // Outside world
  OutsideWorld outsideWorld;

  // Mask class to add FBOs together
  Masking mask;

  // Pointer to the control panel window
  shared_ptr<ControlPanel> control;
    
  BoxDetector  *detector;
  camVideo *cam;
    
  ofImage        opencv; // image alex
  

};
