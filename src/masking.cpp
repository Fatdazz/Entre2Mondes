#include "masking.h"


void Masking::setup(string shader){
  mask.load(shader);
  img.load("vitres.png");  
  
}

ofFbo Masking::applyMaskToFbo(ofFbo fboMasked, ofFbo fboBackground){
  
  ofFbo res;
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

ofFbo Masking::applyMaskToFbo(ofImage imageMasked, ofImage imageBackground){
  
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
