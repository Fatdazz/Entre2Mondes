#include "MaskGenerator.h"

void MaskGenerator::setup(int width, int height) {

  mask.allocate(width, height);
  mask.begin();
  ofClear(255, 255, 255, 0);
  mask.end();

  contourToMaskRatio = ofPoint(0, 0);
}

ofFbo& MaskGenerator::getFbo() {
  return mask;
}

void MaskGenerator::addObject(ofPolyline contour) {
	if (contour.getArea() != 0) {
		// tesselate the polyline to make it more usable with opengl
		tess.tessellateToMesh(contour, OF_POLY_WINDING_ODD, mesh, true);
		boxes.push_back(mesh);
	}
}

void MaskGenerator::generateMask() {
  mask.begin();
  ofClear(0, 0, 0, 0); // Clear the FBO
  ofSetColor(ofColor::white); // Set the color to white to draw the meshes
  //ofScale(contourToMaskRatio); // aggrandissement mesh boites.
  //ofTranslate pour compenser scale
  //ofFill();
  for (ofMesh& box : boxes) { // Draw every box group
    box.draw();
  }
  //ofNoFill();
  mask.end();
}

void MaskGenerator::resetMask() {
	boxes.clear();
}

void MaskGenerator::updateMask(vector<ofPolyline> poly) {

	// Each groups contour is added to the list
	for (int i = 0; i < poly.size(); i++) {
		addObject(poly[i]);
	}

}

