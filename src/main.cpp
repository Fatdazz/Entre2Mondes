#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){  

  /*
  ofGLFWWindowSettings settings;
  settings.setGLVersion(3, 2); //we define the OpenGL version we want to use
  settings.width = 1024;
  settings.height = 768;
  ofCreateWindow(settings);
  */
    ofSetupOpenGL(1024,768,OF_WINDOW);
    ofRunApp(new Entre2Mondes());

}

