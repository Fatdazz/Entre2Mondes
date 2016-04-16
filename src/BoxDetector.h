#pragma once

#include "ofMain.h"
#include "Camera.h"
#include "MaskGenerator.h"
#include "masking.h"
#include "ofxCv.h"

class BoxDetector : public ofThread {
public:
	~BoxDetector();

	void setup(CameraType ct, int fboWidth = 0, int fboHeight = 0);

	ofFbo getFbo();

	vector<ofPolyline> getContours();

	ofFbo fbo;
	Camera camera;
	MaskGenerator generator;
	Masking masking;
	ofImage windowMask;

	void threadedFunction() override;

	ofxCv::ContourFinder finder;
	vector<ofPolyline> contours;

	ofImage tmp;
};

