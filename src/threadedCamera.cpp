//
//  threadedCamera.cpp
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#include "threadedCamera.h"

threadedCamera::threadedCamera(){
    // changer la taile pour metre la vrais taille youpi
    maskCamera.allocate(cam.cameraGetWidth(), cam.cameraGetHeight(), ofImageType::OF_IMAGE_GRAYSCALE);
    maskInsideWorld.allocate(cam.cameraGetWidth(), cam.cameraGetHeight(), ofImageType::OF_IMAGE_GRAYSCALE);
    
    
    startThread();
}

void threadedCamera::threadedFunction(){
    while (cam.cameraIsConnect()) {
        cam.cameraUpdate();
        if (cam.cameraGetNewFrame()) {
            
        }
    }
}