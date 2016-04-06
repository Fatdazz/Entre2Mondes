#pragma once

#include "ofMain.h"

class BoxMaskGenerator
{
public:
	
	void setup(int width, int height);
	ofFbo& getMaskFbo();
	void addBox(ofPolyline convexHull);
	void generateMask();
	void resetMask();

private:

	ofFbo mask;
	vector<ofMesh> boxes;

};

