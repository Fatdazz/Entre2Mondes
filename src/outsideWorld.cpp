#include "outsideWorld.h"

void OutsideWorld::setup(int width, int height){
  // INIT IMG
  img.load("feu.jpg");

  // INIT FBO
  outsideWorld.allocate(width, height); // TAILLE FENETRE
  outsideWorld.begin();
  ofClear(255, 255, 255, 0);
  outsideWorld.end();
  }

void OutsideWorld::update() {


	outsideWorld.begin();
	ofClear(255, 255, 255, 0);
	img.draw(0, 0);
	
  outsideWorld.end();


}

void OutsideWorld::draw() {
  outsideWorld.draw(0, 0);

}
