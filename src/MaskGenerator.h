#pragma once

#include "ofMain.h"
#include "ofxCv.h"

/*
 * This class creates of list of objets from points
 * and generates an fbo mask from all the objects
 * which works with opengl
 */

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