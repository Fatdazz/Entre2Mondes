#include "DetectorBoxAndContour.h"

// TODO: refaire tout le code

BoxDetector::~BoxDetector() {
    stopThread();
    waitForThread(true);
}

void BoxDetector::setup(camVideo *cam) {

    
    ////// attention le code qui suit est une insulte à la notion même de l'imformatique ///////
    //// ps : je n'en suis pas fière /////
	imageImport.load("TEST01.png");
	roiy = 0;
	roih = imageImport.getHeight();
    cv::Mat imageFondImport=ofxCv::toCv(imageImport);
	
    finder_1.setThreshold(250);
    finder_1.setMinAreaRadius(0);
    finder_1.setMaxAreaRadius(5000);
    finder_1.setUseTargetColor(true);
    finder_1.setTargetColor(ofColor::white, ofxCv::TRACK_COLOR_SV);
	finder_1.setFindHoles(true);
    finder_1.findContours(imageFondImport);
    
    imageFond = cv::Mat::zeros(imageImport.getHeight(), imageImport.getWidth(), CV_8UC1);
        
	const size_t num_contours = finder_1.getContours().size();
	cv::Point** temp = new cv::Point*[num_contours];
	int* npt = new int[num_contours];
        
    for (int i=0; i<num_contours; i++) {
            npt[i]=finder_1.getContours()[i].size();
            temp[i]= new cv::Point[npt[i]];
	for (int j=0; j<npt[i]; j++) {
	      temp[i][j] = finder_1.getContours()[i][j];
	    }
	}
            
	cv::fillPoly( imageFond, (const cv::Point**)temp, npt, num_contours, cv::Scalar( 255, 255, 255 ), 18 );

	finder_1.setThreshold(150);
	finder_1.setMinAreaRadius(50);
	finder_1.setMaxAreaRadius(500);
	finder_1.setUseTargetColor(true);
	finder_1.setTargetColor(ofColor::white, ofxCv::TRACK_COLOR_SV);
	finder_1.getTracker().setPersistence(30);
	finder_1.getTracker().setMaximumDistance(50);
	camera=cam;
	mirrored.allocate(cam->getWidth(), cam->getHeight(), OF_IMAGE_COLOR);
	mirrored.setUseTexture(false);
	finder_2.setThreshold(50);
	finder_2.setMinAreaRadius(50);
	finder_2.setMaxAreaRadius(500);
	finder_2.setUseTargetColor(false);
	finder_2.setFindHoles(true);


    for (size_t i = 0; i < num_contours; i++)
	  {
	    delete temp[i];
	  }
	delete[] temp;
	delete[] npt;
}
void BoxDetector::threadedFunction() {
  //while (isThreadRunning()) {

  if (camera->isFrameNew()) {
    /// mask generator ///

	  ROIH.tryReceive(roih);
	  ROIY.tryReceive(roiy);
	  channelColor.tryReceive(targetColor);
	  //finder_1.setTargetColor(targetColor);
	  channelMinArea.tryReceive(minArea);
	  finder_1.setMinAreaRadius(minArea);
	  channelMaxArea.tryReceive(maxArea);
	  finder_1.setMaxAreaRadius(maxArea);

	  cv::Rect roi(0, roiy, camera->getWidth(), roih);

      mirroredImage();
            
    cv::Mat mat = ofxCv::toCv(mirrored);
	mat = mat(roi);
            
    finder_1.findContours(mat); // detection cam
	
            
    imageContour = cv::Mat::zeros(camera->getHeight(), camera->getWidth(), CV_8UC1); // mise a zero la matrix
                
    const size_t variable = finder_1.getContours().size();
    cv::Point** temp = new cv::Point*[variable];
    int* npt = new int[variable];

    for (int i = 0; i<variable; i++) {
      npt[i] = finder_1.getContours()[i].size();
      temp[i] = new cv::Point[npt[i]];
      for (int j = 0; j<npt[i]; j++) {
	    temp[i][j] = finder_1.getContours()[i][j];
      }
    }
                
    /*
      for (int i=0; i<variable; i++) {
      npt[i]=finder_1.getContours()[i].size();
      temp[i]= new cv::Point[npt[i]];
      for (int j=0; j<npt[i]; j++) {
      temp[i][j] = finder_1.getContours()[i][j];
      }
      }
    */
				

                
    cv::fillPoly( imageContour, (const cv::Point**)temp, npt, variable, cv::Scalar( 255, 255, 255 ), 18 );



    cv::Mat t;
    cv::resize(imageContour, t, imageFond.size());
    imageDouble= t + imageFond;
     // imageDouble = imageFond;
    //imageDouble=imageContour;
    // detection sur imageDouble
    contours.clear();
    finder_2.findContours(imageDouble);

	c.send(finder_1);

    for (size_t i = 0; i < variable; i++)
      {
	delete temp[i];
      }
    delete[] temp;
    delete[] npt;
            
  }
  //}
}
void BoxDetector::mirroredImage(){
	if (camera->isFrameNew()) {
		mirrored.setFromPixels(camera->getPixels());
		mirrored.mirror(false, false); // a remettre en true, true
	}
}

void BoxDetector::draw() {

	c.tryReceive(contoursBoxes);
	contoursBoxes.draw();

	auto& tracker = contoursBoxes.getTracker();
	for (int i = 0; i < contoursBoxes.size(); i++) {
		if (contoursBoxes.size()) {
			ofPoint center = ofxCv::toOf(contoursBoxes.getCenter(i));
			ofPushMatrix();
			ofTranslate(center.x, center.y);
			int label = contoursBoxes.getLabel(i);
			string msg = ofToString(label) + ":" + ofToString(tracker.getAge(label));
			ofDrawBitmapString(msg, 0, 0);
			ofPopMatrix();
		}
	}

}


vector<ofPolyline>& BoxDetector::getContours() {
  return contours;
}


