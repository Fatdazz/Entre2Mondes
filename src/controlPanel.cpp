#include "controlPanel.h"

using namespace ofxCv;
using namespace cv;

void ControlPanel::setup() {

  
  //contourFinder.setInvert(true); // find black instead of white

  gui.setup();
  
  gui.add(threshold.set("Threshold", 128, 0, 255));
  gui.add(trackH.set("Track Hue", false));
  gui.add(trackHS.set("Track Hue/Saturation", false));
  gui.add(trackHSB.set("Track Hue/Saturation/Brightness", false));
  gui.add(trackSB.set("Track Saturation/Brightness", true));
  gui.add(trackRGB.set("Track Red/Green/Blue", false));
	
  gui.add(h.set("Hue value", 128, 0, 255));
  gui.add(s.set("Saturation value", 128, 0, 255));
  gui.add(b.set("Brightness value", 128, 0, 255));	

  gui.add(ROIH.set("ROI H", 0, 0, cam->getHeight()));
  gui.add(ROIY.set("ROI Y", 0, 0, cam->getHeight()));

  gui.add(minAreaRadius.set("Min area radius", 10, 0, 100));
  gui.add(maxAreaRadius.set("Max area radius", 500, 0, 1000));
}

void ControlPanel::update() {
    cam->update(); // ne pas effacer upate camera pour tout le programme

	//ofSetWindowTitle(to_string(ofGetFrameRate()));

	if (ROIH + ROIY > cam->getHeight()) {
		ROIH = cam->getHeight() - ROIY;
	}
	if (trackRGB) {
		targetColor.r = h;
		targetColor.g = s;
		targetColor.b = b;
	}
	else {
		targetColor.setHsb(h, s, b);
	}

	detector->ROIH.send(ROIH);
	detector->ROIY.send(ROIY);
    detector->channelColor.send(targetColor);
	detector->finder_1.setTargetColor(targetColor);
	detector->finder_1.setThreshold(threshold);
	detector->channelMinArea.send(minAreaRadius);
	detector->channelMaxArea.send(maxAreaRadius);
	if (trackH) {
		detector->finder_1.setTargetColor(targetColor, ofxCv::TRACK_COLOR_H);
	}
	else if (trackHS) {
		detector->finder_1.setTargetColor(targetColor, ofxCv::TRACK_COLOR_HS);
	}
	else if (trackHSB) {
		detector->finder_1.setTargetColor(targetColor, ofxCv::TRACK_COLOR_HSV);
	}
	else if (trackSB) {
		detector->finder_1.setTargetColor(targetColor, ofxCv::TRACK_COLOR_SV);
	}
	else if (trackRGB) {
		detector->finder_1.setTargetColor(targetColor, ofxCv::TRACK_COLOR_RGB);
	}
}

void ControlPanel::draw() {
	

    cam->draw(0, 0);
	/*
	ofImage img;
	img.setFromPixels(cam->getDepthPixels());
	img.resize(1920, 1080);
	img.draw(0, 0);
	*/
	/*

	ofSetColor(255);
	flipImage.draw(0,0);
	*/
	ofSetLineWidth(2);
	ofSetColor(0, 250, 0);
	

	ofSetColor(ofColor::purple);
	ofSetLineWidth(3);
	ofNoFill();
	ofDrawRectangle(0, ROIY, cam->getWidth(), ROIH);
	ofSetColor(ofColor::white);
	gui.draw();

	ofSetColor(0, 0, 250);

	detector->draw();



	ofTranslate(10, 10);
	ofFill();
	ofSetColor(0);
	ofDrawRectangle(-3, -3, 64 + 6, 64 + 6);
	ofSetColor(targetColor);
	ofDrawRectangle(0, 0, 64, 64);

	ofSetColor(ofColor::white);

}

void ControlPanel::mousePressed(int x, int y, int button) {
  targetColor = cam->getPixels().getColor(x, y);
  if (trackRGB) {
	  h = targetColor.r;
	  s = targetColor.g;
	  b = targetColor.b;
  }
  else {
	  float	  hh, ss, bb;
	  targetColor.getHsb(hh, ss, bb);
	  h = hh;
	  s = ss;
	  b = bb;
   }


}

void ControlPanel::keyPressed(int key){
	if (key == OF_KEY_RETURN) {
		ofImage tmp;
		tmp.setFromPixels(flipImage.getPixels());
		tmp.save(to_string(ofGetUnixTime()) + "_screenshot.png");
	}

	if (key == OF_KEY_UP) {
		threshold++;
		if (threshold > 255){
			threshold = 255;
		}
	} else if (key == OF_KEY_DOWN) {
		threshold--;
		if (threshold < 0) {
			threshold = 0;
		}
	} else if (key == '1') {
		trackH = true;
		trackHS = trackHSB = trackRGB = false;
	} else if (key == '2') {
		trackHS = true;
		trackH = trackHSB = trackRGB = false;
	} else if (key == '3') {
		trackHSB = true;
		trackHS = trackH = trackRGB = false;
	} else if (key == '4') {
		trackRGB = true;
		trackH = trackHSB = trackHS = false;
	}
}

void ControlPanel::keyReleased(int key){
}

void ControlPanel::mouseMoved(int x, int y){
}

void ControlPanel::mouseDragged(int x, int y, int button){
}

void ControlPanel::mouseReleased(int x, int y, int button){
}

void ControlPanel::mouseEntered(int x, int y){
}

void ControlPanel::mouseExited(int x, int y){
}

void ControlPanel::windowResized(int w, int h){
}

void ControlPanel::dragEvent(ofDragInfo dragInfo){
}

void ControlPanel::gotMessage(ofMessage msg){
}
