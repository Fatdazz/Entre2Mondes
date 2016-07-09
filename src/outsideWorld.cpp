#include "outsideWorld.h"

void OutsideWorld::setup(int width, int height){
  // INIT IMG
  img.load("feu.jpg");

  // INIT FBO
  outsideWorld.allocate(width, height); // TAILLE FENETRE
  outsideWorld.begin();
  ofClear(255, 255, 255, 0);
  outsideWorld.end();

  for (int i = 0; i < numGlitches; i++) {
      glitches.emplace_back();
      cout <<glitches.size()<< endl;
    glitches[i].setup("feu.jpg");
  }
}

void OutsideWorld::update(){
    if (currentTime - previousTime > 2000) {
        previousTime = ofGetElapsedTimeMillis();
        for (int i = 0; i < numGlitches; i++) {
            glitches[i].update();
        }
    }
    
    outsideWorld.begin();
  ofClear(255, 255, 255, 0);
  img.draw(0, 0);
    
    for (int i = 0; i < numGlitches; i++) {
        std::cout << "i: " << i << std::endl;
        glitches[i].draw();
    }
  
    outsideWorld.end();
    //cout << " update "<< endl;
    
  currentTime = ofGetElapsedTimeMillis();
  
}

void OutsideWorld::draw(){
  outsideWorld.draw(0, 0);
    cout << " draw "<< endl;


}
