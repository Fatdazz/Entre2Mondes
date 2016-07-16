#include "outsideWorld.h"

void OutsideWorld::setup(int width, int height){
  // INIT IMG
  img.load("ImageFond2.jpg");

  // INIT FBO
  outsideWorld.allocate(width, height); // TAILLE FENETRE
  outsideWorld.begin();
  ofClear(255, 255, 255, 0);
  outsideWorld.end();

  for (size_t i = 0; i < NUM_GLITCHES; i++)
  {
	  glitches.emplace_back();
	  glitches[i].setup(img, ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()), 250, 250);
	  randomTimes.emplace_back(ofRandom(1000, 60000));
	  previousTimes.emplace_back(0);
  }

  currentTime = 0;
  }

void OutsideWorld::update() {
	currentTime = ofGetElapsedTimeMillis();

	for (std::size_t i = 0; i < NUM_GLITCHES; i++) {
		if (currentTime - previousTimes[i] > randomTimes[i]) {
			previousTimes[i] = ofGetElapsedTimeMillis();
			glitches[i].setPosition(ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()));
			glitches[i].setFx((ofxPostGlitchType)(int)ofRandom(0, 17)); // pas propre
		}
		glitches[i].update();
	}

	outsideWorld.begin();
	ofClear(255, 255, 255, 0);
	img.draw(0, 0);


	for (std::size_t i = 0; i < NUM_GLITCHES; i++) {
		glitches[i].draw();
	}
  outsideWorld.end();


}

void OutsideWorld::draw() {
  outsideWorld.draw(0, 0);

}
