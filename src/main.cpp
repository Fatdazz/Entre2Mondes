#include "ofMain.h"
#include "ofApp.h"
#include "controlPanel.h"
#include "parametersGUI.h"
#include "DetectorBoxAndContour.h"
#include "Camera.h"



constexpr int NUM_GROUPS = 2;



//========================================================================
int main( ){
    
    
	ofGLFWWindowSettings windowSettings;
    


	// Settings for main window
	windowSettings.resizable = false;
	//windowSettings.windowMode = OF_FULLSCREEN;
	
	windowSettings.setPosition(ofVec2f(0, 100));
	windowSettings.width = PROJECTOR_WIDTH * 2;
	windowSettings.height = PROJECTOR_HEIGHT;

	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(windowSettings);


	// Settings for window with controls
	windowSettings.width = 640;
	windowSettings.height = 480;
	windowSettings.setPosition(ofVec2f(PROJECTOR_WIDTH *2 + 100, 100));
	windowSettings.resizable = true;
	//windowSettings.shareContextWith = mainWindow;

	shared_ptr<ofAppBaseWindow> controlPanel = ofCreateWindow(windowSettings);
    
    
    // Camera
    camVideo cam;
     /// fin fr la caméra
    
    // run DetectorBoxAndContour
    BoxDetector detector;
    detector.setup(&cam);
    

	shared_ptr<Entre2Mondes> entreDeuxMondesApp(new Entre2Mondes());
	shared_ptr<ControlPanel> controlPanelApp(new ControlPanel());

	entreDeuxMondesApp->control = controlPanelApp;
    entreDeuxMondesApp->detector= &detector;
    controlPanelApp->detector= &detector;
    entreDeuxMondesApp->cam= &cam;
    controlPanelApp->cam= &cam;
    
    
    ofRunApp(mainWindow, entreDeuxMondesApp);
	ofRunApp(controlPanel, controlPanelApp);
	ofRunMainLoop();


}

