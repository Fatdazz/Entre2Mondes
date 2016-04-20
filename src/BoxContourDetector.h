#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class BoxContourDetector : public ofThread {
public:
	BoxContourDetector();
	~BoxContourDetector();

	void threadedFunction() override;

	vector<ofPolyline> getContours();

	ofThreadChannel<ofPixels> stream;
	ofThreadChannel<ofPixels> toStream;

	void update();
	void analyze(ofPixels & pixels);

	ofPixels pixels;

	bool newFrame;

	ofImage img;
	cv::Mat mat;

	vector<ofPolyline> contours;

	ofxCv::ContourFinder finder;
	ofxCv::TrackingColorMode colorMode;
	ofColor targetColor;

};

