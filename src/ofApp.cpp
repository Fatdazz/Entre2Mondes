#include "ofApp.h"

#define PROJECTOR_COUNT 2
//#define PROJECTOR_WIDTH 1920
//#define PROJECTOR_HEIGHT 1080
#define PROJECTOR_WIDTH 960
#define PROJECTOR_HEIGHT 540
#define PIXEL_OVERLAP 545

//--------------------------------------------------------------
void Entre2Mondes::setup() {
   

  //need this for alpha to come through
  ofEnableAlphaBlending();
  
  projectorOutput.setup(PROJECTOR_WIDTH, PROJECTOR_HEIGHT, PROJECTOR_COUNT, PIXEL_OVERLAP);
  projectorOutput.gamma[0] = .5;
  projectorOutput.blendPower[0] = 1;

  projectorTwoOffset = 0;

  projectorOutput.luminance[0] = 0;

  ofSetWindowShape(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());

  overlaped = PIXEL_OVERLAP;

  cout << "canvas size: " << projectorOutput.getCanvasWidth() << " x " << projectorOutput.getCanvasHeight() << endl;
  cout << "display size: " << projectorOutput.getDisplayWidth() << " x " << projectorOutput.getDisplayHeight() << endl;

  //insideWorld.setup(projectorOutput.getCanvasWidth(), projectorOutput.getCanvasHeight());
  outsideWorld.setup(projectorOutput.getCanvasWidth(), projectorOutput.getCanvasHeight());

	  
}


//--------------------------------------------------------------
void Entre2Mondes::update(){

	ofSetWindowTitle(to_string(ofGetFrameRate()));
   

  //insideWorld.update(cam.getPixels(), control);

  outsideWorld.update();
}

//--------------------------------------------------------------
void Entre2Mondes::draw(){

  //outsideWorld.draw();
  //insideWorld.draw();      
  
  projectorOutput.begin();
  
  ofSetColor(100, 100, 100);
  ofDrawRectangle(0, 0, projectorOutput.getCanvasWidth(), projectorOutput.getCanvasHeight());

  ofSetColor(255, 255, 255);
  ofSetLineWidth(3);

  for (int i = 0; i < projectorOutput.getCanvasWidth(); i += 40) {
    ofDrawLine(i, 0, i, projectorOutput.getCanvasHeight());
  }

  for (int j = 0; j < projectorOutput.getCanvasHeight(); j += 40) {
    ofDrawLine(0, j, projectorOutput.getCanvasWidth(), j);      
  }
  
  //mask.applyMaskToFbo(insideWorld.insideWorld, outsideWorld.outsideWorld, insideWorld.insideWorldMask).draw(0, 0);


  projectorOutput.end();
  
  projectorOutput.draw();
}

//--------------------------------------------------------------
void Entre2Mondes::keyPressed(int key){

}

//--------------------------------------------------------------
void Entre2Mondes::keyReleased(int key){

}

//--------------------------------------------------------------
void Entre2Mondes::mouseMoved(int x, int y ){
 
}

//--------------------------------------------------------------
void Entre2Mondes::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Entre2Mondes::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Entre2Mondes::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Entre2Mondes::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Entre2Mondes::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Entre2Mondes::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Entre2Mondes::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Entre2Mondes::dragEvent(ofDragInfo dragInfo){ 

}
