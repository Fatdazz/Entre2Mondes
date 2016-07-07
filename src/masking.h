#pragma once

#include "ofMain.h"

/*
 * This allows to add FBOs and images with a mask, computed with using a shader
 */

class Masking {
 public:  

	Masking();
  
  ofFbo applyMaskToFbo(const ofFbo& fboMasked,const ofFbo& fboBackground);
  ofFbo applyMaskToFbo(const ofImage& imageMasked, const ofImage& imageBackground);
  ofFbo applyMaskToFbo(const ofFbo& fboMasked, const ofFbo& fboBackground, const ofFbo& mask);

 private:
	ofFbo res;
	ofShader mask;
	ofImage img;  
};
