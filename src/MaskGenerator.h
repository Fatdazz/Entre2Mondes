#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class MaskGenerator {
public:
	
	void setup(int width, int height);
	ofFbo& getFbo();

	void updateMask(ofPixels pixels);
	void addObject(ofPolyline contour);
	void generateMask();
	void resetMask();

private:
	ofFbo mask;
	list<ofMesh> boxes;
	list<ofMesh> finalMesh;
	ofTessellator tess;
	ofMesh mesh;
	cv::Mat matPix;

	ofxCv::ContourFinder finder;
	ofxCv::TrackingColorMode colorMode;
	ofColor targetColor;

	ofPoint contourToMaskRatio;

};

