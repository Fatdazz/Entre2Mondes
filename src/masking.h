#pragma once

#include "ofMain.h"

class Masking {
 public:  

  void setup(string shader);
  
  ofFbo applyMaskToFbo(ofFbo fboMasked, ofFbo fboBackground);
  ofFbo applyMaskToFbo(ofImage imageMasked, ofImage imageBackground);
  
 private:
  ofShader mask;
  ofImage img;  
};
