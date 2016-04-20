#include "ContourDetectorThread.h"

ContourDetectorThread::ContourDetectorThread() {
	finder.setThreshold(200);
	finder.setMinAreaRadius(50);
	finder.setMaxAreaRadius(500);
	finder.setUseTargetColor(false);

}

void ContourDetectorThread::setup(ofPixels& _pixels) {
	if (!isThreadRunning()) {
		pixels = _pixels;

		startThread();
	}
}

ContourDetectorThread::~ContourDetectorThread() {

}

void ContourDetectorThread::threadedFunction() {
	contours.clear();
	finder.findContours(pixels);
	for(int i = 0; i < finder.size(); i++) {
		contours.push_back(ofxCv::toOf(finder.getContour(i)));
	}
	tcContours.send(contours);
	//stopThread();
}

vector<ofPolyline> ContourDetectorThread::getContours() {
	vector<ofPolyline> poly;
	tcContours.receive(poly);
	return poly;
}