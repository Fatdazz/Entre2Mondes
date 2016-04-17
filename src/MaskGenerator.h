#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class MaskGenerator {
public:
	
	void setup(int width, int height);
	ofFbo& getFbo();

	void updateMask(vector<ofPolyline> poly);
	void addObject(ofPolyline contour);
	void generateMask();
	void resetMask();
	 
private:
	ofFbo mask;
	vector<ofMesh> boxes;

	ofTessellator tess;
	ofMesh mesh;

	ofPoint contourToMaskRatio;

};

