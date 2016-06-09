#pragma once

#include "ofMain.h"
#include "Camera.h"
#include "MaskGenerator.h"
#include "masking.h"
#include "ofxCv.h"

class BoxDetector : public ofThread {
public:
	~BoxDetector();

	void setup(shared_ptr<Camera> cam, int fboWidth = 0, int fboHeight = 0);
	void draw();

	vector<ofPolyline>& getContours();

	void threadedFunction() override;

	ofxCv::ContourFinder finder;
	vector<ofPolyline> contours;

	ofImage mirrored;

	shared_ptr<Camera> camera;

	
};

