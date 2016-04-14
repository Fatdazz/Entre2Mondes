//
//  threadedBoids.hpp
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#pragma once

#include "ofMain.h"
#include "Flock2d.h"

class threadedBoids: public ofThread{
public:
    
    threadedBoids();
    ~threadedBoids();
    
private:
    void threadedFunction();
    
};