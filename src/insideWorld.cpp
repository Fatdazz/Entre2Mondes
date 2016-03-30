#include "insideWorld.h"

void InsideWorld::setup(int width, int height){
  // INIT FBO
  insideWorld.allocate(width, height, GL_RGB); // TAILLE FENETRE DE JEU
  insideWorld.begin();
  ofClear(255, 255, 255, 0);
  insideWorld.end();

  // INIT FLOCK
  flock.setBounds(0, 0, width,  height);
  flock.setBoundmode(1);

  for (int i=0; i<NumGroup; i++) {
    flock.addGoup();
        
    int lulu= ofRandom(30, 100);
    for (int j=0; j<100; j++) {
      flock.addBoidGroup(i,
			 ofVec2f(ofRandom(0, width), ofRandom(0, height)),
			 20 ,
			 10 ,
			 10 ,
			 35,
			 12,
			 20,
			 1000,
			 2);
    }
  }
  
  
}


void InsideWorld::update(){
  flock.update();
  
  insideWorld.begin();
  ofClear(255, 255, 255, 0);
  ofBackground(255, 0, 0);
  for (int i=0; i<NumGroup; i++) {
    GroupBoid2d *g = flock.groupBoid.at(i);
    ofSetColor(ofColor(100, 50 * i, 60 * i));
    for (int j=0; j<g->boids.size(); j++) {      
      Boid2d *b = g->boids.at(j);
      
      ofDrawRectangle(b->position.x, b->position.y, 5,5);
      float lm = 10.f;
      ofDrawLine(b->position.x, b->position.y, b->position.x + b->velocite.x*lm, b->position.y + b->velocite.y*lm);
      
    }
  }
  insideWorld.end();

}

void InsideWorld::draw(){
  insideWorld.draw(0, 0);
}


