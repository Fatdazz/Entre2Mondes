#include "masking.h"


Masking::Masking() {
  mask.load("shader/mask");
  img.load("vitres1.png");
  cout << "test" << endl;
  res.begin();
  ofClear(255, 255, 255, 0);
  res.end();
}

ofFbo Masking::applyMaskToFbo(const ofFbo& fboMasked,  const ofFbo& fboBackground){

  res.allocate(fboMasked.getWidth(), fboMasked.getHeight());

  res.begin();
  ofClear(255, 255, 255, 0);

  fboBackground.draw(0, 0);

  ofPushMatrix();  
  mask.begin();
  mask.setUniformTexture("mask", img.getTexture(), 1);
  mask.setUniformTexture("tex", fboMasked.getTexture(), 2);
  
  fboMasked.draw(0, 0);
  mask.end();
  ofPopMatrix();
  res.end();
  
  return res;
}

ofFbo Masking::applyMaskToFbo(const ofFbo& fboMasked, const ofFbo& fboBackground, const ofFbo& fboMask) {
	mask.load("shader/mask");

	res.allocate(fboMasked.getWidth(), fboMasked.getHeight());

	res.begin();

	ofClear(255, 255, 255, 0);
	fboBackground.draw(0, 0);
	mask.begin();
	mask.setUniformTexture("mask", fboMask.getTexture(), 1);
	mask.setUniformTexture("tex", fboMasked.getTexture(), 2);
	fboMasked.draw(0, 0);
	mask.end();
	res.end();
	return res;
}

ofFbo Masking::applyMaskToFbo(const ofImage& imageMasked,const ofImage& imageBackground){
  
  ofFbo res;
  
  res.begin();
  ofClear(255, 255, 255, 0);
  ofBackground(0);
  imageBackground.draw(0, 0);
  
  mask.begin();
  mask.setUniformTexture("mask", img.getTexture(), 1);
  mask.setUniformTexture("tex", imageMasked.getTexture(), 2);
  imageMasked.draw(0, 0);
  mask.end();  
  
  res.end();
  
  return res;
}
