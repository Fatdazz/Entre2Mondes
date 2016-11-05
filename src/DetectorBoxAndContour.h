#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "Camera.h"

class BoxDetector : public ofThread {
public:
    ~BoxDetector();
    
    void setup(camVideo *cam);
    void draw();
    void mirroredImage();
    
    vector<ofPolyline>& getContours();
    
    void threadedFunction() override;
    
    ofxCv::ContourFinder finder_1, finder_2;
    vector<ofPolyline> contours;
    
    cv::Mat     imageContour,imageFond;
    cv::Mat     imageDouble;
    cv::Mat    *image1, *image2;
    ofImage mirrored, imageImport;
    camVideo *camera;

    vector<vector<cv::Point>> contoursMask;

	ofThreadChannel<int> channelMinArea;
	int minArea{ 0 };
	int maxArea{ 0 };
	ofThreadChannel<int> channelMaxArea;
	ofThreadChannel<ofColor> channelColor;
	ofColor targetColor;
	ofThreadChannel<ofParameter<int>> ROIH;
	ofThreadChannel<ofParameter<int>> ROIY;
	ofParameter<int> roiy;
	ofParameter<int> roih;

	ofThreadChannel<ofxCv::ContourFinder> c;
	ofxCv::ContourFinder contoursBoxes;

};