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
    Flock2d flock;
    
    threadedBoids();
    ~threadedBoids(){
        stopThread();
    };
    void initBoids(int _width,int _height);
    void drawBoids();
    void drawLines();
    vector<Boid2d *> getBoids();
  
    
private:
    void threadedFunction();
    int NumGroup;
    
};