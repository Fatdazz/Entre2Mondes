#include "insideWorld.h"

void InsideWorld::setup(int width, int height) {
  // init fbo
  insideWorld.allocate(width, height); 
  insideWorld.begin();
  ofClear(255, 255, 255, 0);
  insideWorld.end();

    
    boids.initBoids(width, height);

}

void InsideWorld::update() {
    
    if(!boids.isThreadRunning()){
        boids.startThread();
    }

  // TODO: rellocate and use after camera update to optimize computer vision
  //cv::Rect roi(0, control->ROIY, stream.getWidth(), control->ROIH);
  // resizedStream = ofxCv::toCv(streamImage);
  //resizedStream = resizedStream(roi);  
  //streamImage.update();

 
  // TODO: fix attractionlines expanding over their assigned segment  
  // TODO: add to threaded boids
  /*
  flock.attractionLines.clear();
  auto& attrPoints = insideWorldMaskContours.getContours();
  for (int i = 0; i < attrPoints.size(); i++){
    for (int j = 0 ; j < attrPoints[i].size()-1;j++){
      flock.addAttrationLine(ofPoint(attrPoints[i][j].x, attrPoints[i][j].y), ofPoint(attrPoints[i][j+1].x, attrPoints[i][j+1].y), -200, 10, 10, 0);
    }
  }

  auto& attrPointsStatic = insideWorldMaskContoursStatic.getContours();
  for (int i = 0; i < attrPointsStatic.size(); i++) {
	  for (int j = 0; j < attrPointsStatic[i].size() - 1; j++) {
		  flock.addAttrationLine(ofPoint(attrPointsStatic[i][j].x, attrPointsStatic[i][j].y), ofPoint(attrPointsStatic[i][j + 1].x, attrPointsStatic[i][j + 1].y), -200, 10, 10, 0);
	  }
  }
  */
    
  
  insideWorld.begin(); // FBO
  ofClear(255, 255, 255, 0);
  ofBackground(0, 0, 0);
  ofSetColor(ofColor::blue);  
  boids.drawBoids();
  insideWorld.end();
}

void InsideWorld::draw(){
  insideWorld.draw(0, 0);
}

