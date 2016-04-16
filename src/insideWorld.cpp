#include "insideWorld.h"

void InsideWorld::setup(int width, int height) {
  // INIT FBO  
  insideWorld.allocate(width, height, GL_RGBA); // TAILLE FENETRE DE JEU
  insideWorld.begin();
  ofClear(255, 255, 255, 0);
  insideWorld.end();
/*
  // INIT FLOCK
  flock.setBounds(0, 0, width,  height);
  flock.setBoundmode(1);

  for (int i=0; i<NumGroup; i++) {    
    flock.addGoup();
        
    for (int j = 0; j < 100; j++) {      
      flock.addBoidGroup(i,
			 ofVec2f(ofRandom(0, width), ofRandom(0, height)),
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
*/
    
    boids.initBoids(width, height);
    
  staticMask.load("image8.914860.png");
  
  staticMask.resize(width, height);
  
  dynamicMask.load("structure_boites.png");
  dynamicMask.resize(width, height);
    
  insideWorldMaskContoursStatic.setThreshold(200);
  insideWorldMaskContoursStatic.setMinAreaRadius(50);
  insideWorldMaskContoursStatic.setMaxAreaRadius(500);
  insideWorldMaskContoursStatic.findContours(staticMask);

  insideWorldMaskContours.setThreshold(200);
  insideWorldMaskContours.setMinAreaRadius(50);
  insideWorldMaskContours.setMaxAreaRadius(500);

  insideWorldMask.allocate(width, height);
}

void InsideWorld::update(ofPixels stream, shared_ptr<ControlPanel>& control) {
    /*              à effacer alexandre
    flock.update();
    */

  //streamImage.setFromPixels(stream);
  //streamImage.mirror(true, true);

  //cv::Rect roi(0, control->ROIY, stream.getWidth(), control->ROIH);

 // resizedStream = ofxCv::toCv(streamImage);
  //resizedStream = resizedStream(roi);
  //cv::blur(resizedStream, resizedStream, cv::Size(50, 50));
  //streamImage.update();

  //insideWorldMaskContours.findContours(dynamicMask);


/*                  //////// Notion  de lines à trasféré
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
    
  insideWorldMask.begin();
  ofClear(0, 0, 0, 0);
  staticMask.draw(0, 0);
  insideWorldMask.end(); 

  
  insideWorld.begin(); // FBO
  ofClear(255, 255, 255, 0);
  ofBackground(0, 0, 0);
/*                       ///// à effacer alexandre
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
  
  ofSetColor(ofColor::green);
  int sizeAttr = flock.attractionLines.size();
  for (int i = 0; i < sizeAttr; i++){
    ofSetLineWidth(3);
    ofSetColor(ofColor::purple);
    auto& t = flock.attractionLines[i];
    ofDrawLine(t->a[0], t->a[1], t->b[0], t->b[1]);
  }
 */
    
    
  //ofSetColor(0);
  //ofImage i;
  //ofxCv::toOf(resizedStream, i);
  //streamImage.draw(0, 0);
  insideWorld.end();



}

void InsideWorld::draw(){
  insideWorld.draw(0, 0);
}

