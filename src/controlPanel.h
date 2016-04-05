#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"

class ControlPanel : public ofBaseApp {
public:

	void setup();
	void update();
	void draw();

	ofxKinect kinect;

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

	ofImage flipImage;

};

