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

void BoxMaskGenerator::addBox(ofPolyline contour) {
  tess.tessellateToMesh(contour, OF_POLY_WINDING_ODD, mesh, true);
  boxes.push_back(mesh);
}

void BoxMaskGenerator::generateMask() {
  
  mask.begin();
  ofClear(0, 0, 0, 0);
  ofSetColor(ofColor::red);
  //  ofFill();
  for (ofMesh& box : boxes) {
    box.drawVertices();
  }
  // ofNoFill();
  mask.end();
}


