#include "ofMain.h"
#include "ofApp.h"
#include "controlPanel.h"
#include "parametersGUI.h"
#include "Camera.h"

constexpr int NUM_GROUPS = 6;


//========================================================================
int main( ){  

  /*
  ofGLFWWindowSettings settings;
  settings.setGLVersion(3, 2); //we define the OpenGL version we want to use
  settings.width = 1024;
  settings.height = 768;
  ofCreateWindow(settings);
  */

	ofGLFWWindowSettings windowSettings;

	// Settings for window with controls
	
	
	windowSettings.width = 1200;
	windowSettings.height = 800;
	windowSettings.setPosition(ofVec2f(0, 100));
	windowSettings.resizable = true;

	shared_ptr<ofAppBaseWindow> controlPanel = ofCreateWindow(windowSettings);

	// Settings for main window
	windowSettings.resizable = false;
	//windowSettings.windowMode = OF_FULLSCREEN;
	//windowSettings.shareContextWith = controlPanel;
	windowSettings.setPosition(ofVec2f(0, 100));
	windowSettings.width = 1980;
	windowSettings.height = 1080;

	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(windowSettings);

	shared_ptr<Entre2Mondes> entreDeuxMondesApp(new Entre2Mondes());
	shared_ptr<ControlPanel> controlPanelApp(new ControlPanel());

	entreDeuxMondesApp->control = controlPanelApp;

    ofRunApp(mainWindow, entreDeuxMondesApp);
    sleep(10);
	ofRunApp(controlPanel, controlPanelApp);
	ofRunMainLoop();
    
    //camera  camera(1);

}

