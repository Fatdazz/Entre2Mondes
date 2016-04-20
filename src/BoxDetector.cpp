#include "BoxDetector.h"




BoxDetector::~BoxDetector() {
	stopThread();
	waitForThread();
}

void BoxDetector::setup(shared_ptr<Camera> cam, int fboWidth, int fboHeight) {

	finder.setThreshold(200);
	finder.setMinAreaRadius(50);
	finder.setMaxAreaRadius(500);
	finder.setUseTargetColor(true);
	finder.setTargetColor(ofColor::white, ofxCv::TRACK_COLOR_RGB);

	camera = cam;

	mirrored.allocate(camera->getWidth(), camera->getHeight(), OF_IMAGE_COLOR);
	mirrored.setUseTexture(false);

	startThread();
}

void BoxDetector::threadedFunction() {
	while (isThreadRunning()) {
	camera->update();

	if (camera->isFrameNew()) {

		///////// mask generator
		
		mirrored.setFromPixels(camera->getPixels());
		//mirrored.mirror(true, true);

		
		cv::Mat mat = ofxCv::toCv(mirrored);
		finder.findContours(mat);
		
		contours.clear();

		for (int i = 0; i < finder.size(); i++) {
			contours.push_back(ofxCv::toOf(finder.getContour(i)));
		}
		
	}

	}
}

void BoxDetector::draw() {
	for (int i = 0; i < contours.size(); i++) {
		contours[i].draw();
	}
}


vector<ofPolyline>& BoxDetector::getContours() {
	return contours;
}
