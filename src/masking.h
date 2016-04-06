#pragma once

#include "ofMain.h"

#include "boxMaskGenerator.h"

class Masking {
 public:  

	Masking();
  
  ofFbo applyMaskToFbo(const ofFbo& fboMasked,const ofFbo& fboBackground);
  ofFbo applyMaskToFbo(const ofImage& imageMasked, const ofImage& imageBackground);
  ofFbo applyMaskToFbo(ofFbo& fboMasked, ofFbo& fboBackground, ofFbo& mask);

 private:
	ofFbo res;
	ofShader mask;
	ofImage img;  
};
