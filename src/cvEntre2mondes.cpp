//
//  cvEntre2mondes.cpp
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#include "cvEntre2mondes.h"


cvEntre2monde::cvEntre2monde(bool _useTargetColor){
    contourFinder.setUseTargetColor(_useTargetColor);
}

void cvEntre2monde::setTrackingColorMode(ofxCv::TrackingColorMode _TrackingColorMode){
    contourFinder.setTargetColor(targetColor, _TrackingColorMode);
}

void cvEntre2monde::findContours(ofImage& _image){
    contourFinder.findContours(_image.getPixels());
}

void cvEntre2monde::setThresholdContours(float _threshold){
    contourFinder.setThreshold(_threshold);
}
