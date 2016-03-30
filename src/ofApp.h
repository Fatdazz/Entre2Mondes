#pragma once

#include "ofMain.h"

#include "ofxProjectorBlend.h"
#include "ofxXmlSettings.h"
#include "Flock2d.h"
#include "insideWorld.h"
#include "outsideWorld.h"
#include "masking.h"

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

  ofImage tmp1;
  ofImage tmp2;
  ofImage masker;

  ofShader shader;  
};
