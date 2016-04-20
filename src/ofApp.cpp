#include "ofApp.h"



//--------------------------------------------------------------
void Entre2Mondes::setup() {

  // Initialize the camera
  camera = make_shared<Camera>();
  camera->setup(CameraType::WEBCAM);

  // Initialize projectoroutput
  // This class allows to align several projector outputs
  // As well as their overlaping to create one continuous screen
  projectorOutput.setup(PROJECTOR_WIDTH, PROJECTOR_HEIGHT, PROJECTOR_COUNT, PIXEL_OVERLAP);
  projectorOutput.gamma[0] = .5;
  projectorOutput.blendPower[0] = 1;

  projectorTwoOffset = 0;

  projectorOutput.luminance[0] = 0;

  //ofSetWindowShape(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());

  overlaped = PIXEL_OVERLAP;

  cout << "canvas size: " << projectorOutput.getCanvasWidth() << " x " << projectorOutput.getCanvasHeight() << endl;
  cout << "display size: " << projectorOutput.getDisplayWidth() << " x " << projectorOutput.getDisplayHeight() << endl;

  // Initialize the inside world
  // In it we store everything that will be projected on the boxes
  // also the things projected on the contours of the windows
  // and everything related to it
  insideWorld.setup(projectorOutput.getDisplayWidth(), projectorOutput.getCanvasHeight());

  // Initialize the outside world
  // This stores everything that will be projected on the windows
  outsideWorld.setup(projectorOutput.getDisplayWidth(), projectorOutput.getCanvasHeight());

  // Initialize the detector and runs it in another thread
  detector.setup(camera);

  // This loads the contours the mask for the window contours and
  // all static elements
  windowMask.load("vitres1.png");
  // We make sure it's at the right size for the window
  windowMask.resize(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());

  // Initialize
  maskGen.setup(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());

  // Initialize boxes FBO, this will store the final mask of all static and dynamic objects
  boxes.allocate(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());
  boxes.begin();
  ofClear(255, 255, 255, 0);
  boxes.end();
	  
}


//--------------------------------------------------------------
void Entre2Mondes::update(){


  // Show FPS in window title
  ofSetWindowTitle(to_string(ofGetFrameRate()));

  // Update the camera stream with the new image
  camera->update();

  // Mask generation of the detected objects from the camera

  // Delete previous contours
  maskGen.resetMask();
  // Find the new contours in the detector (runs in another thread)
  maskGen.updateMask(detector.contours);
  // Finally create the FBO with the current mask of the contours
  maskGen.generateMask();

  // Create the final mask
  boxes.begin();
  // Reset
  ofClear(0, 0);
  // Black background
  ofBackground(0);
  ofSetColor(255);
  windowMask.draw(0, 0); // Draw static mask
  maskGen.getFbo().draw(0,0); // Draw detected objects mask
  boxes.end();

  // Convert FBO to pixels
  ofPixels pix;
  boxes.readToPixels(pix);
  boxContour.setup(pix);

  // Update inside world
  insideWorld.update();

  // Update outside world
  outsideWorld.update();
  
  
}

//--------------------------------------------------------------
void Entre2Mondes::draw() {

  projectorOutput.begin();
  // reset
  ofClear(0, 0);

  // Draws inside world and outside world in the projector output
  // The mask is used here  to draw the inside world correctly
  // Draws inside world over outside world as well
  mask.applyMaskToFbo(insideWorld.insideWorld, outsideWorld.outsideWorld, boxes).draw(0, 0);
  
  projectorOutput.end();

  // Draw the final result
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
