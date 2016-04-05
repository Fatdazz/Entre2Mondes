#include "ControlPanel.h"

using namespace ofxCv;
using namespace cv;

void ControlPanel::setup() {
	kinect.init();
	kinect.open();

	contourFinder.setMinAreaRadius(10);
	contourFinder.setMaxAreaRadius(150);
	//contourFinder.setInvert(true); // find black instead of white

	gui.setup();
	gui.add(threshold.set("Threshold", 128, 0, 255));
	gui.add(trackH.set("Track Hue", true));
	gui.add(trackHS.set("Track Hue/Saturation", false));
	gui.add(trackHSB.set("Track Hue/Saturation/Brightness", false));
	gui.add(trackRGB.set("Track Red/Green/Blue", false));

}

void ControlPanel::update() {
	kinect.update();

	if (kinect.isFrameNew()) {

		flipImage = kinect.getPixels();
		flipImage.mirror(true, true);

		
		if (trackH) {
			contourFinder.setTargetColor(targetColor, TRACK_COLOR_H);
		}
		else if (trackHS) {
			contourFinder.setTargetColor(targetColor, TRACK_COLOR_HS);
		}
		else if (trackHSB) {
			contourFinder.setTargetColor(targetColor, TRACK_COLOR_HSV);
		}
		else if (trackRGB) {
			contourFinder.setTargetColor(targetColor, TRACK_COLOR_RGB);
		}
		
		contourFinder.setThreshold(threshold);
		contourFinder.findContours(flipImage.getPixels());
	}
}

void ControlPanel::draw() {
	ofSetColor(255);
	flipImage.draw(0,0);

	ofSetLineWidth(2);
	ofSetColor(0, 250, 0);
	//contourFinder.draw();
	for (size_t i = 0; i < contourFinder.getContours().size(); i++)
	{
		ofSetColor(0, 200, 0);
		ofPolyline contours = ofxCv::toOf(contourFinder.getContour(i));
		contours.draw();
	}
	

	gui.draw();

	ofTranslate(8, 275);
	ofFill();
	ofSetColor(0);
	ofDrawRectangle(-3, -3, 64 + 6, 64 + 6);
	ofSetColor(targetColor);
	ofDrawRectangle(0, 0, 64, 64);
}

void ControlPanel::mousePressed(int x, int y, int button) {
	targetColor = flipImage.getPixels().getColor(x, y);
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