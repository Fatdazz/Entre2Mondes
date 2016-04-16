#include "BoxDetector.h"




BoxDetector::~BoxDetector() {
	stopThread();
}

void BoxDetector::setup(CameraType ct, int fboWidth, int fboHeight) {

	windowMask.load("vitres1.png");

	camera.setup(ct);

	generator.setup(camera.getWidth(), camera.getHeight());

	finder.setThreshold(200);
	finder.setMinAreaRadius(50);
	finder.setMaxAreaRadius(500);

	tmp.allocate(windowMask.getWidth(), windowMask.getHeight(), OF_IMAGE_GRAYSCALE);

	fbo.allocate(windowMask.getWidth(), windowMask.getHeight());

	fbo.begin();
	ofClear(0, 0, 0, 0);
	fbo.end();

	startThread();
}

ofFbo BoxDetector::getFbo() {
	return fbo;
}

void BoxDetector::threadedFunction() {
	while (true) {
	camera.update();

	if (camera.isFrameNew()) {

		//cameraChannel.send(camera.getPixels());
		// mask generator
		/*
		generator.resetMask();
		generator.updateMask(camera.getPixels());
		*/

		/*
		// final fbo mask
		fbo.begin();
		ofClear(0, 0, 0, 0);
		ofSetColor(ofColor::white);
		windowMask.draw(0, 0);
		generator.getFbo();
		fbo.end();
		*/

		/*
		//convert fbo to image to get proper mask contours
		fbo.readToPixels(tmp);
		cv::Mat mat = ofxCv::toCv(tmp);
		finder.findContours(mat);
		
		contours.clear();

		for (int i = 0; i < finder.size(); i++) {
			contours.push_back(ofxCv::toOf(finder.getContour(i)));
		}
		*/
	}

	}
}


vector<ofPolyline> BoxDetector::getContours() {
	return contours;
}
