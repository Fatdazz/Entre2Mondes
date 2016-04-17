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

enum class CameraType {WEBCAM, KINECTv1, KINECTv2};

class Camera {

public:

    void setup(CameraType ct, int camWidth = 640, int camHeight = 480);
    void update();
    bool isFrameNew();
    bool isConnected();
    ofPixels& getPixels();
    int  getWidth();
    int  getHeight();
	void draw(int x, int y);
	void draw(int x, int y, int w, int h);
    
private:
    shared_ptr<ofxKinect>   kinect_1;
    shared_ptr<ofVideoGrabber> grabber;

	shared_ptr<ofBaseVideo> camera;
    CameraType camType;
    int width , height;
};





