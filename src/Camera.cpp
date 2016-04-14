//
//  Camera.cpp
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#include "Camera.h"

camera::camera(int _val){
    val=_val;
    switch (val) {
        case 1:
            kinect_1 = make_shared<ofxKinect>();
            kinect_1->init();
            kinect_1->open();
            cameraWidth=kinect_1->width;
            cameraHeight=kinect_1->height;
            break;
        case 2:
            grabber = make_shared<ofVideoGrabber>();
            grabber->setup(640,480);
            cameraWidth=640;
            cameraHeight=480;
        default:
            break;
    }
    
}

void camera::cameraUpdate(){
    switch (val) {
        case 1:
            kinect_1->update();
            break;
        case 2:
            grabber->update();
            break;
    }
}

bool camera::cameraGetNewFrame(){
    switch (val) {
        case 1:
            return kinect_1->isFrameNewVideo();
            break;
        case 2:
            return grabber->isFrameNew();
            break;
    }
}

bool camera::cameraIsConnect(){
    switch (val) {
        case 1:
            return kinect_1->isConnected();
            break;
        case 2:
            return true;
            break;
    }
}

ofPixels camera::cameraGetPixel(){
    switch (val) {
        case 1:
            return kinect_1->getPixels();
            break;
        case 2:
            return grabber->getPixels();
            break;
    }
}

int camera::cameraGetHeight(){
    return cameraHeight;
}
int camera::cameraGetWidth(){
    return cameraGetWidth();
}


///////////////////////////////////
