#include "outsideWorld.h"

void OutsideWorld::setup(int width, int height){
  // INIT IMG
  img.load("feu.jpg");

  // INIT FBO
  outsideWorld.allocate(width, height); // TAILLE FENETRE
  outsideWorld.begin();
  ofClear(255, 255, 255, 0);
  outsideWorld.end();

  // for (int i = 0; i < numGlitches; i++) {
  //   glitches.emplace_back();
  //   glitches[i].setup("feu.jpg");
  // }
  glitches.setup("feu.jpg");
  /*
    glitches[1].setup("feu.jpg");
    glitches[2].setup("feu.jpg");
    glitches[3].setup("feu.jpg");
    glitches[4].setup("feu.jpg");
  */
}

void OutsideWorld::update(){
  outsideWorld.begin();
  ofClear(255, 255, 255, 0);
  img.draw(0, 0);
  glitches.draw();
  outsideWorld.end();

  currentTime = ofGetElapsedTimeMillis();
  if (currentTime - previousTime > 2000) {
    previousTime = ofGetElapsedTimeMillis();
    //for (int i = 0; i < numGlitches; i++) {
    glitches.update();
    //}
  }
}

void OutsideWorld::draw() {
  outsideWorld.draw(0, 0);
  //for (int i = 0; i < numGlitches; i++) {
  //
  //}
}
