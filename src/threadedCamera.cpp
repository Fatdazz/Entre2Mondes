//
//  threadedCamera.cpp
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#include "threadedCamera.h"

threadedCamera::threadedCamera(){
    startThread();
}

void threadedCamera::threadedFunction(){
    while (cam.cameraIsConnect()) {
        cam.cameraUpdate();
    }
}