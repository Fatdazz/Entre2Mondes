#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class BoxContourDetector : public ofThread {
public:
	BoxContourDetector();
	~BoxContourDetector();

	void threadedFunction() override;
	
	void imgToFind(ofImage image);
	vector<ofPolyline> getContours();

	ofThreadChannel<ofPixels> stream;
	ofThreadChannel<ofPixels> toStream;

	void analyze(ofPixels & pixels) {
		toStream.send(pixels);
	}

	void update() {
		newFrame = false;
		while (stream.tryReceive(pixels)) {
			newFrame = true;
		}
		if (newFrame) {
			if (!texture.isAllocated()) {
				texture.allocate(pixels);
			}
			texture.loadData(pixels);
		}
	}

	ofTexture texture;
	ofPixels pixels;

	bool newFrame;

	ofImage img;
	cv::Mat mat;

	vector<ofPolyline> contours;

	ofxCv::ContourFinder finder;
	ofxCv::TrackingColorMode colorMode;
	ofColor targetColor;

};

