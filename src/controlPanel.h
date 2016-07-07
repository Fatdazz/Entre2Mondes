#ifndef CONTROL_PANEL
#define CONTROL_PANEL

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "DetectorBoxAndContour.h"



class ControlPanel : public ofBaseApp {
public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void mousePressed(int x, int y, int button);

	ofxCv::ContourFinder contourFinder;
	ofColor targetColor;

	ofxPanel gui;
	ofParameter<float> threshold;
	ofParameter<bool> trackHS;
	ofParameter<bool> trackH;
	ofParameter<bool> trackHSB;
	ofParameter<bool> trackRGB;

	ofParameter<int> h;
	ofParameter<int> s;
	ofParameter<int> b;

	ofParameter<int> ROIH;
	ofParameter<int> ROIY;

    ofImage flipImage;

    BoxDetector  *detector;
  Camera cam;



};


#endif

