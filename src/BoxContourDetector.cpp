#include "BoxContourDetector.h"

BoxContourDetector::BoxContourDetector() : newFrame(true) {
	finder.setThreshold(200);
	finder.setMinAreaRadius(50);
	finder.setMaxAreaRadius(500);
	finder.setUseTargetColor(false);

	startThread();
}

BoxContourDetector::~BoxContourDetector() {
	cout << "stop" << endl;
	stream.close();
	toStream.close();
	waitForThread(true);
}

void BoxContourDetector::threadedFunction() {
	ofPixels pixels;
	while (toStream.receive(pixels)) {
		
		mat = ofxCv::toCv(pixels);
		
		finder.findContours(mat);
		
		for (int i = 0; i < finder.size(); i++) {
			contours.push_back(ofxCv::toOf(finder.getContour(i)));
		}

		stream.send(move(pixels));
	}

}

vector<ofPolyline> BoxContourDetector::getContours() {
	//stopThread();
	return contours;
}