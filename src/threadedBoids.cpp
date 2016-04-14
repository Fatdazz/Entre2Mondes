//
//  threadedBoids.cpp
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//
#pragma once

#include "threadedBoids.h"


threadedBoids::threadedBoids(){
    }

void threadedBoids::initBoids(int _width,int _height){
    flock.setBounds(0, 0, _width,  _height);
    flock.setBoundmode(1);
    NumGroup=3;
    for (int i=0; i<NumGroup; i++) {
        flock.addGoup();
        
        for (int j = 0; j < 100; j++) {
            flock.addBoidGroup(i,
                               ofVec2f(ofRandom(0, _width), ofRandom(0, _height)),
                               20,
                               10,
                               10,
                               35,
                               12,
                               20,
                               1000,
                               2);
        }
    }  
    startThread();
}

void threadedBoids::threadedFunction(){
    while (true) {
        
        flock.update();
    }
}

void threadedBoids::drawBoids(){
    
    for (int i=0; i < NumGroup; i++) {
        GroupBoid2d* g = flock.groupBoid.at(i);
        ofSetColor(ofColor(255, 0, 0));
        int boidNum = g->boids.size();
        for (int j=0; j < boidNum; j++) {
            Boid2d* b = g->boids.at(j);
            
            ofDrawRectangle(b->position.x, b->position.y, 5,5);
            float lm = 10.f;
            ofDrawLine(b->position.x, b->position.y, b->position.x + b->velocite.x*lm, b->position.y + b->velocite.y*lm);
        }
    }
}

void threadedBoids::drawLines(){
    int sizeAttr = flock.attractionLines.size();
    for (int i = 0; i < sizeAttr; i++){
        ofSetLineWidth(3);
        ofSetColor(ofColor::purple);
        auto& t = flock.attractionLines[i];
        ofDrawLine(t->a[0], t->a[1], t->b[0], t->b[1]);
    }
}

vector<Boid2d*> threadedBoids::getBoids(){
    vector<Boid2d*> boids;
    for (int i=0; i<flock.getNumGroups(); i++) {
        boids=flock.groupBoid[i]->boids;
        ///// il fait linker les groupBoid en eux
    }
    return boids;
}