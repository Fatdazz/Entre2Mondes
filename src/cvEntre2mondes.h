//
//  cvEntre2mondes.hpp
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"



class cvEntre2monde{
public:
    ofxCv::ContourFinder contourFinder;
    
    cvEntre2monde(bool _useTargetColor);
    void setTrackingColorMode(ofxCv::TrackingColorMode _TrackingColorMode);
    void findContours(ofImage& _image);
    void setThresholdContours(float _threshold);
    
private:
    float threshold;
    ofColor targetColor;
    ofxCv::TrackingColorMode TrackingColorMode;
};