#include "ofApp.h"



//--------------------------------------------------------------
void Entre2Mondes::setup() {
	
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


	  boxes.allocate(projectorOutput.getDisplayWidth(), projectorOutput.getDisplayHeight());
	  boxes.begin();
	  ofClear(255, 255, 255, 0);
	  boxes.end();
	  
}


//--------------------------------------------------------------
void Entre2Mondes::update(){
	ofSetWindowTitle(to_string(ofGetFrameRate()));
    camera->update();

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
	if (boxContour.isThreadRunning())
	{
		boxContour.setup(pix);
	}
	
	
	insideWorld.update();
	outsideWorld.update();
	

}

//--------------------------------------------------------------
void Entre2Mondes::draw() {

	projectorOutput.begin();
	ofClear(0, 0);

	mask.applyMaskToFbo(insideWorld.insideWorld, outsideWorld.outsideWorld, boxes).draw(0, 0);

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
