#ifndef FBOGLITCH_H
#define FBOGLITCH_H

#include "ofMain.h"
#include "ofxPostGlitch.h"

class FboGlitch {
  ofFbo fbo;
  int x, y;
  int w, h;
  ofxPostGlitch glitch;
  ofImage image;

public:

  void setup(std::string image_path,  ofxPostGlitchType t=OFXPOSTGLITCH_CONVERGENCE, int w=250, int h=250){
    image.load(image_path);
    fbo.allocate(w, h);
    glitch.setup(&fbo);
    glitch.setFx(t, true);
    x = 0;
    y = 0;
    this->w = w;
    this->h = h;
  }

  void setPosition(int x, int y){
    this->x = x;
    this->y = y;

    fbo.begin();
    ofClear(0);
    image.drawSubsection(0, 0, w, h, x, y);
    fbo.end();
  }

  void addFx(ofxPostGlitchType t){
    glitch.setFx(t, true);
  }

  void toggleFx(ofxPostGlitchType t){
    glitch.toggleFx(t);
  }

  bool getFx(ofxPostGlitchType t){
    return glitch.getFx(t);
  }

  void update(int w = ofGetWindowWidth(), int h = ofGetWindowHeight()){
    x = ofRandom(0, w);
    y = ofRandom(0, h);

    fbo.begin();
    ofClear(0);
    image.drawSubsection(0, 0, w, h, x, y);
    fbo.end();
  }

  void draw() {
    glitch.generateFx();
    fbo.draw(x, y);
  }
};


#endif /* FBOGLITCH_H */
