#include "ofApp.h"



//--------------------------------------------------------------
void Entre2Mondes::setup() {
	/*
	camera = make_shared<Camera>();
	camera->setup(CameraType::KINECTv1);
  
  projectorOutput.setup(PROJECTOR_WIDTH, PROJECTOR_HEIGHT, PROJECTOR_COUNT, PIXEL_OVERLAP);
  projectorOutput.gamma[0] = .5;
  projectorOutput.blendPower[0] = 1;

  projectorTwoOffset = 0;

  projectorOutput.luminance[0] = 0;

  //ofSetWindowShape(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());

  overlaped = PIXEL_OVERLAP;

  cout << "canvas size: " << projectorOutput.getCanvasWidth() << " x " << projectorOutput.getCanvasHeight() << endl;
  cout << "display size: " << projectorOutput.getDisplayWidth() << " x " << projectorOutput.getDisplayHeight() << endl;

  insideWorld.setup(projectorOutput.getDisplayWidth(), projectorOutput.getCanvasHeight());
  outsideWorld.setup(projectorOutput.getDisplayWidth(), projectorOutput.getCanvasHeight());

	  detector.setup(camera);


	  windowMask.load("vitres1.png");
	  windowMask.resize(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());
  
	  maskGen.setup(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());

	  //tmpBoxContour.allocate(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight(), OF_IMAGE_GRAYSCALE);
	  tmpBoxContour.setImageType(OF_IMAGE_GRAYSCALE);

	  boxes.allocate(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());
	  boxes.begin();
	  ofClear(255, 255, 255, 0);
	  boxes.end();
	  */
}


//--------------------------------------------------------------
void Entre2Mondes::update(){
	ofSetWindowTitle(to_string(ofGetFrameRate()));

   /*
	maskGen.resetMask();
	maskGen.updateMask(detector.contours);
	maskGen.generateMask();

	boxes.begin();
	ofClear(0, 0);
	ofBackground(0);
	ofSetColor(255);
	windowMask.draw(0, 0);
	maskGen.getFbo().draw(0,0);
	boxes.end();

	ofPixels pix;
	boxes.readToPixels(pix);
	boxContour.setup(pix);
	
	insideWorld.update();
	outsideWorld.update();
	*/

}

//--------------------------------------------------------------
void Entre2Mondes::draw() {

	//projectorOutput.begin();
	ofClear(0, 0);

	ofFbo masked;
	masked.allocate(500, 500);
	masked.begin();
	ofClear(0);
	masked.end();

	ofFbo background;
	background.allocate(500, 500);
	background.begin();
	ofClear(0);
	background.end();

	ofFbo m;
	m.allocate(500, 500);
	m.begin();
	ofClear(0);
	m.end();

	background.begin();
	ofClear(0);
	ofBackground(255, 0, 0);
	background.end();

	masked.begin();
	ofClear(0);
	ofBackground(0, 255, 0);
	ofSetColor(ofColor::purple);
	ofDrawRectangle(0, 0, 200, 200);
	masked.end();

	m.begin();
	ofClear(0);
	ofBackground(0);
	ofSetColor(ofColor::white);
	ofDrawRectangle(0, 0, 300, 300);
	m.end();

	//mask.applyMaskToFbo(masked, background, m).draw(0, 0);
	//masked.draw(0, 0);
	//background.draw(0, 0);
	//m.draw(0, 0);


	//projectorOutput.end();

	//projectorOutput.draw();
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
