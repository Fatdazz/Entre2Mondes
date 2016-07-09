//
//  Camera.hpp
//  Entre2Mondes
//
//  Created by FatDazz_mac on 09/07/2016.
//
//

#pragma once
#include "ofMain.h"

#define Cam 0

#if Cam == 0
#include "ofxKinectForWindows2.h"
#else

#endif

class camVideo{
public:
    int videoWidth,videoHeight;
    #if Cam == 0
    ofxKFW2::Device kinect;
    camVideo(){
        kinect.open();
        kinect.initDepthSource();
        kinect.initColorSource();
        kinect.initInfraredSource();
        kinect.initBodySource();
        kinect.initBodyIndexSource();
        
    };
    
    
    void draw(int _x, int _y){
        kinect.draw(_x, _y);
    }
    
    bool isFrameNew(){
        return kinect.isFrameNew();
    }
    ofPixels& getPixels(){
        return kinect.getPixels();
    }
    void update(){
        cam.update();
    }
    #else
    ofVideoGrabber cam;
    camVideo(){
        videoWidth = 640;  // try to grab at this size.
        videoHeight = 480;
        
        //we can now get back a list of devices.
        vector<ofVideoDevice> devices = cam.listDevices();
        
        for(int i = 0; i < devices.size(); i++){
            if(devices[i].bAvailable){
                ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
            }else{
                ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
                }
                }
                
                cam.setDeviceID(0);
                cam.setDesiredFrameRate(60);
                cam.initGrabber(videoWidth,videoHeight);
    };
    void draw(int _x, int _y){
        cam.draw(_x, _y);
    }
    
    bool isFrameNew(){
        return cam.isFrameNew();
    }
    ofPixels& getPixels(){
        return cam.getPixels();
    }
    void update(){
        cam.update();
    }
    
    #endif
    
    int getWidth(){
        return videoWidth;
    }
    int getHeight(){
        return videoHeight;
    }
    
    
    
};