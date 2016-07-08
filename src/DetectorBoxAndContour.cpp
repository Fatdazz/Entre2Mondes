#include "DetectorBoxAndContour.h"


BoxDetector::~BoxDetector() {
    stopThread();
    waitForThread();
}
void BoxDetector::setup(ofVideoGrabber *cam, std::string image) {

  imageFondImport.setUseTexture(false);
  imageFondImport.load(image);
  imageFond = ofxCv::toCv(imageFondImport);
  finder_1.setThreshold(200);
  finder_1.setMinAreaRadius(50);
  finder_1.setMaxAreaRadius(500);
  finder_1.setUseTargetColor(true);
  finder_1.setTargetColor(ofColor::white, ofxCv::TRACK_COLOR_SV);
  finder_2.setThreshold(200);
  finder_2.setMinAreaRadius(50);
  finder_2.setMaxAreaRadius(500);
  finder_2.setUseTargetColor(false);
  camera=cam;
  mirrored.allocate(cam->getWidth(), cam->getHeight(), OF_IMAGE_COLOR);
  mirrored.setUseTexture(false);
  /*
    imageFond = cv::Mat::zeros(camera->getHeight(), camera->getWidth(), CV_8UC1);
    int w=40;
    // Draw a circle
    cv::Point rook_points[1][20];
    rook_points[0][0] = cv::Point( w/4.0, 7*w/8.0 );
    rook_points[0][1] = cv::Point( 3*w/4.0, 7*w/8.0 );
    rook_points[0][2] = cv::Point( 3*w/4.0, 13*w/16.0 );
    rook_points[0][3] = cv::Point( 11*w/16.0, 13*w/16.0 );
    rook_points[0][4] = cv::Point( 19*w/32.0, 3*w/8.0 );
    rook_points[0][5] = cv::Point( 3*w/4.0, 3*w/8.0 );
    rook_points[0][6] = cv::Point( 3*w/4.0, w/8.0 );
    rook_points[0][7] = cv::Point( 26*w/40.0, w/8.0 );
    rook_points[0][8] = cv::Point( 26*w/40.0, w/4.0 );
    rook_points[0][9] = cv::Point( 22*w/40.0, w/4.0 );
    rook_points[0][10] = cv::Point( 22*w/40.0, w/8.0 );
    rook_points[0][11] = cv::Point( 18*w/40.0, w/8.0 );
    rook_points[0][12] = cv::Point( 18*w/40.0, w/4.0 );
    rook_points[0][13] = cv::Point( 14*w/40.0, w/4.0 );
    rook_points[0][14] = cv::Point( 14*w/40.0, w/8.0 );
    rook_points[0][15] = cv::Point( w/4.0, w/8.0 );
    rook_points[0][16] = cv::Point( w/4.0, 3*w/8.0 );
    rook_points[0][17] = cv::Point( 13*w/32.0, 3*w/8.0 );
    rook_points[0][18] = cv::Point( 5*w/16.0, 13*w/16.0 );
    rook_points[0][19] = cv::Point( w/4.0, 13*w/16.0) ;
    
    const cv::Point* ppt[1] = { rook_points[0] };
    int npt[] = { 20 };
    
    fillPoly( imageFond, ppt, npt, 1, cv::Scalar( 255, 255, 255 ), 8 );
  */
  //startThread();
}
void BoxDetector::threadedFunction() {
    //while (isThreadRunning()) {
        
        if (camera->isFrameNew()) {
            /// mask generator ///
            
            mirroredImage();
            
            cv::Mat mat = ofxCv::toCv(mirrored);
            
            finder_1.findContours(mat); // detection cam

	    imageContour = cv::Mat::zeros(cv::Size(camera->getWidth(), camera->getHeight()), CV_8UC1); // mise a zero la matrix
                
	    const size_t variable = finder_1.getContours().size();
	    cv::Point** temp = new cv::Point*[variable]; // code pour passe une vector en tableau

	    int* npt = new int[variable];
                
	    for (int i=0; i<variable; i++) {
	      npt[i]=finder_1.getContours()[i].size();
	      temp[i]= new cv::Point[npt[i]];
	      for (int j=0; j<npt[i]; j++) {
		temp[i][j] = finder_1.getContours()[i][j];
	      }
	    }

	    cv::fillPoly( imageContour, (const cv::Point**)temp, npt, variable, cv::Scalar( 255, 255, 255 ), 18 );

	    for (auto i = 0; i < variable; i++){
	      delete temp[i];
	    }
	    delete[] temp;
	    delete[] npt;
            

	    imageDouble = cv::Mat::zeros(cv::Size(2*camera->getWidth(), camera->getHeight()), CV_8UC1);
	    cv::resize(imageContour, imageDouble, imageDouble.size());
	    /*
	      isImage=false;
	      imageDouble=imageContour;
	      isImage=true;
	    */
	    // detection sur imageDouble
	    std::cout << "taille imagedouble: " << imageDouble.size() << std::endl;
	    std::cout << "taille imagefond: " << imageFond.size() << std::endl;
	    std::cout << "taille imageContour: " << imageContour.size() << std::endl;
	    imageDouble = imageFond + imageDouble; // somme le fond et le poly
	    //finder_2.findContours(imageDouble);
			
	    for(int i = 0; i < finder_2.size(); i++) {
	      contours.push_back(ofxCv::toOf(finder_2.getContour(i)));
	    }


	}
	//}
}
void BoxDetector::mirroredImage(){
  mirrored.setFromPixels(camera->getPixels());
  //mirrored.mirror(true, true);
}

void BoxDetector::draw() {
  for (int i = 0; i < contours.size(); i++) {
    contours[i].draw();
  }

}

vector<ofPolyline>& BoxDetector::getContours() {
  return contours;
}


