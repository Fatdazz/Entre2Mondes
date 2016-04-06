#include "boxMaskGenerator.h"
#include "cv.h"

void BoxMaskGenerator::setup(int width, int height) {
	mask.allocate(width, height);
	mask.begin();
	ofClear(255, 255, 255, 0);
	mask.end();
}


ofFbo& BoxMaskGenerator::getMaskFbo() {
	return mask;
}

void BoxMaskGenerator::resetMask() {
	boxes.clear();
}

void BoxMaskGenerator::addBox(ofPolyline convexHull) {
	ofTessellator tess;
	ofMesh mesh;
	tess.tessellateToMesh(convexHull, OF_POLY_WINDING_POSITIVE, mesh, false);
	boxes.push_back(mesh);
}

void BoxMaskGenerator::generateMask() {
	mask.begin();
	ofClear(0, 0, 0, 0);
	ofSetColor(ofColor::white);
	ofFill();
	
	for (ofMesh& box : boxes) {
		box.draw();
	}
	ofNoFill();
	mask.end();
}