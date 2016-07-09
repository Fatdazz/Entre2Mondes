#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "Camera.h"

class BoxDetector : public ofThread {
public:
    ~BoxDetector();
    
    void setup(camVideo *cam);
    void draw();
    void drawAlex();
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
    bool        isImage;
    vector<vector<cv::Point>> contoursMask;

	bool protection;

	ofThreadChannel<vector<vector<cv::Point>>> analyzedFinder;

};