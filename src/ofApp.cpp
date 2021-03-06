#include "ofApp.h"



//--------------------------------------------------------------
void Entre2Mondes::setup() {

  // Initialize projectoroutput
  // This class allows to align several projector outputs
  // As well as their overlaping to create one continuous screen
  projectorOutput.setup(PROJECTOR_WIDTH, PROJECTOR_HEIGHT, PROJECTOR_COUNT, PIXEL_OVERLAP);
  projectorOutput.gamma[0] = .5;
  projectorOutput.blendPower[0] = 1;

  projectorTwoOffset = 3;

  projectorOutput.luminance[0] = 0.55;

  //ofSetWindowShape(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());

  overlaped = PIXEL_OVERLAP;

  cout << "canvas size: " << projectorOutput.getCanvasWidth() << " x " << projectorOutput.getCanvasHeight() << endl;
  cout << "display size: " << projectorOutput.getDisplayWidth() << " x " << projectorOutput.getDisplayHeight() << endl;

  // Initialize the inside world
  // In it we store everything that will be projected on the boxes
  // also the things projected on the contours of the windows
  // and everything related to it
  //insideWorld.setup(projectorOutput.getDisplayWidth(), projectorOutput.getCanvasHeight(),detector);

  // Initialize the outside world
  // This stores everything that will be projected on the windows
  outsideWorld.setup(projectorOutput.getDisplayWidth(), projectorOutput.getCanvasHeight());
    
    opencv.allocate(PROJECTOR_WIDTH, PROJECTOR_HEIGHT, OF_IMAGE_COLOR);

    ///////////////////////////////////// fichier vitre windowMask.load("vitres1.png");
	redBall.position.y = 400;
}


//--------------------------------------------------------------
void Entre2Mondes::update(){
	ofSetWindowTitle(std::to_string(ofGetFrameRate()));

    if (!detector->isThreadRunning()) {
        detector->startThread();
    }

  // Update inside world
  //insideWorld.update();

  // Update outside world
  outsideWorld.update();
}

//--------------------------------------------------------------
void Entre2Mondes::draw() {
	ofSetBackgroundColor(ofColor::blue);
  projectorOutput.begin();
  // reset
  ofClear(0, 0);
    
    //if (detector->isImage) {
        ofxCv::toOf(detector->imageDouble, opencv);
        opencv.update();
    //}

    ofFbo res;
    res.allocate(2*PROJECTOR_WIDTH, projectorOutput.getCanvasHeight());
    res.begin();
    ofClear(0, 0, 255, 0);
	
    opencv.draw(0, 0);
    opencv.draw(opencv.getWidth(), 0);
    res.end();
    // Draws inside world and outside world in the projector output
    // The mask is used here  to draw the inside world correctly
    // Draws inside world over outside world as well
    // mask.applyMaskToFbo(insideWorld.insideWorld, outsideWorld.outsideWorld, res).draw(0, 0);
	//outsideWorld.draw();

  projectorOutput.end();

  // Draw the final result
  //projectorOutput.draw();
  ofSetColor(ofColor::red);
  if (redBall.movingRight) {
	  redBall.position += ofPoint(75, 0);
	  if (redBall.position.x > (ofGetWindowWidth() - 300)) {
		  redBall.movingRight = false;
	  }
  }
  else {
	  redBall.position -= ofPoint(75, 0);
	  if (redBall.position.x <= 300) {
		  redBall.movingRight = true;
	  }
  }
  ofDrawCircle	  (redBall.position, 300);
}

//--------------------------------------------------------------
void Entre2Mondes::keyPressed(int key){
	if (key == '&') {           ///// Fullscreen
		ofToggleFullscreen();
	}
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
