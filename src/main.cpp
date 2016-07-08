#include "ofMain.h"
#include "ofApp.h"
#include "controlPanel.h"
#include "parametersGUI.h"
#include "DetectorBoxAndContour.h"



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
  windowSettings.width = 320;
  windowSettings.height = 240;
  windowSettings.setPosition(ofVec2f(0, 100));
  windowSettings.resizable = true;
  //windowSettings.shareContextWith = mainWindow;

  shared_ptr<ofAppBaseWindow> controlPanel = ofCreateWindow(windowSettings);
    
    
  // Camera
  ofVideoGrabber cam;
  int camWidth,camHeight;
  camWidth = 320;  // try to grab at this size.
  camHeight = 240;
    
  //we can now get back a list of devices.
  vector<ofVideoDevice> devices = cam.listDevices();
    
  for(int i = 0; i < devices.size(); i++){
    if(devices[i].bAvailable){
      ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
    }else{
      ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
    }
  }
    
  cam.setDeviceID(0);
  cam.setDesiredFrameRate(60);
  cam.initGrabber(camWidth, camHeight);
  /// fin fr la camŽra
    
  // run DetectorBoxAndContour
  BoxDetector detector;
  detector.setup(&cam, "fond.png");
    

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

