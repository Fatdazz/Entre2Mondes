#include "MaskGenerator.h"

void MaskGenerator::setup(int width, int height) {

  mask.allocate(width, height);
  mask.begin();
  ofClear(255, 255, 255, 0);
  mask.end();

  targetColor = ofColor::white;
  colorMode = ofxCv::TRACK_COLOR_RGB;

  finder.setThreshold(200);
  finder.setMinAreaRadius(50);
  finder.setMaxAreaRadius(500);
  finder.setTargetColor(targetColor, ofxCv::TRACK_COLOR_RGB);

  contourToMaskRatio = ofPoint(0, 0);
}

ofFbo& MaskGenerator::getFbo() {
  return mask;
}

void MaskGenerator::addObject(ofPolyline contour) {
	// tesselate the polyline to make it more usable with opengl
  tess.tessellateToMesh(contour, OF_POLY_WINDING_ODD, mesh, true);
  boxes.push_back(mesh);
}

void MaskGenerator::generateMask() {
  mask.begin();
  ofClear(0, 0, 0, 0); // Clear the FBO
  ofSetColor(ofColor::white); // Set the color to white to draw the meshes
  //ofScale(contourToMaskRatio); // aggrandissement mesh boites.
  //ofTranslate pour compenser scale
  ofFill();
  for (ofMesh& box : boxes) { // Draw every box group
    box.drawVertices();
  }
  ofNoFill();
  mask.end();
}

void MaskGenerator::resetMask() {
	boxes.clear();
	finalMesh.clear();
}

void MaskGenerator::updateMask(ofPixels pixels) {

	//Copy the pixels into an opencv object
	matPix = ofxCv::toCv(pixels);

	// Find the contours. These are the contours of every group of box.
	finder.findContours(matPix);

	// Each groups contour is added to the list
	for (int i = 0; i < finder.getContours().size(); i++) {
		addObject(ofxCv::toOf(finder.getContour(i)));
	}
		
	// Once all the boxes are added create the mask
	generateMask();
}

