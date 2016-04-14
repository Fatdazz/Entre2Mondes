//
//  Camera.h
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#pragma once

#include "ofMain.h"
#include "ofxKinect.h"


class camera {

public:
    

    
    camera(int _val);
    void cameraUpdate();
    bool cameraGetNewFrame();
    bool cameraIsConnect();
    ofPixels    cameraGetPixel();
    int  cameraGetWidth();
    int  cameraGetHeight();
    
    
    
private:
    shared_ptr<ofxKinect>   kinect_1;
    shared_ptr<ofVideoGrabber> grabber;
    int val;
    int cameraWidth , cameraHeight;
};





