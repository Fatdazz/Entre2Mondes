//
//  threadedCamera.hpp
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#pragma once

#include "ofMain.h"
#include "Camera.h"


class threadedCamera: public ofThread{
public:
    camera  cam = camera(1);
    threadedCamera();
    ~threadedCamera();
    ofImage maskInsideWorld,maskCamera;
    
private:
    void threadedFunction();

};