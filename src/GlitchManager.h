#ifndef GLITCHMANAGER_H
#define GLITCHMANAGER_H

#include "ofMain.h"
#include "ofxPostGlitch.h"

class Glitch {
private:
  //std::vector<std::pair<int, int>> position;
  ofRectangle position;
  ofFbo fbo;
  ofxPostGlitch glitch;
  ofxPostGlitchType type;
  ofImage image;

public:

  void setup(ofImage img, int x, int y, int w=100, int h=100){
    image = img;
    fbo.allocate(w, h);
	fbo.begin();
	ofClear(0);
	fbo.end();
    glitch.setup(&fbo);

    type=OFXPOSTGLITCH_TWIST;
    glitch.setFx(type, true);
    position.x = x;
    position.y = y;
    position.width = w;
    position.height = h;
  }

  void setFx(ofxPostGlitchType g) {
    glitch.setFx(type, false);
    glitch.setFx(g, true);
    type=g;
  }

  void setPosition(int x, int y){
    position.x = x;
    position.y = y;
  }

  void setSize(int w, int h){
    position.width = w;
    position.height = h;
  }

  void update() {
    fbo.begin();
    ofClear(0);
    image.drawSubsection(0, 0, position.width, position.height, position.x, position.y);
    ofSetColor(ofColor::red);
    ofDrawCircle(position.x, position.y, 5);
    fbo.end();
	glitch.setFbo(&fbo);
    glitch.generateFx();
  }

  void draw(){
    fbo.draw(position.x, position.y);
  }

};


#endif /* GLITCHMANAGER_H */
