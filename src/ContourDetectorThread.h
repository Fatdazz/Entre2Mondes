#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ContourDetectorThread : public ofThread {
public:
	ContourDetectorThread();
	~ContourDetectorThread();

	void setup(ofPixels& pixels);
	void threadedFunction();

	vector<ofPolyline> getContours();

	ofPixels pixels;

	ofImage img;
	cv::Mat mat;

	ofThreadChannel<vector<ofPolyline> > tcContours;
	vector<ofPolyline> contours;

	ofxCv::ContourFinder finder;
	ofxCv::TrackingColorMode colorMode;
	ofColor targetColor;

};

