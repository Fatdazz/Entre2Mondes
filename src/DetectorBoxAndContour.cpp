#include "DetectorBoxAndContour.h"


BoxDetector::~BoxDetector() {
    stopThread();
    waitForThread();
}
void BoxDetector::setup(ofVideoGrabber *cam) {
    
    ////// attention le code qui suit est une insulte à la notion même de l'imformatique ///////
    //// ps : je n'en suis pas fiére /////
    imageImport.load("fond.png");
    cv::Mat imageFondImport=ofxCv::toCv(imageImport);
    finder_1.setThreshold(250);
    finder_1.setMinAreaRadius(0);
    finder_1.setMaxAreaRadius(5000);
    finder_1.setUseTargetColor(true);
    finder_1.setTargetColor(ofColor::white, ofxCv::TRACK_COLOR_SV);
    
    finder_1.findContours(imageFondImport);
    
        imageFond = cv::Mat::zeros(imageImport.getHeight(), imageImport.getWidth(), CV_8UC1);
        
		const size_t variable = finder_1.getContours().size();
		cv::Point** temp = new cv::Point*[variable];
		int* npt = new int[variable];
        
        for (int i=0; i<variable; i++) {
            npt[i]=finder_1.getContours()[i].size();
            temp[i]= new cv::Point[npt[i]];
            for (int j=0; j<npt[i]; j++) {
                temp[i][j] = finder_1.getContours()[i][j];
            }
        }
        
        
        cv::fillPoly( imageFond, (const cv::Point**)temp, npt, variable, cv::Scalar( 255, 255, 255 ), 18 );
    ///// fin
    
    finder_1.setThreshold(150);
    finder_1.setMinAreaRadius(50);
    finder_1.setMaxAreaRadius(500);
    finder_1.setUseTargetColor(true);
    finder_1.setTargetColor(ofColor::white, ofxCv::TRACK_COLOR_SV);
    camera=cam;
    mirrored.allocate(cam->getWidth(), cam->getHeight(), OF_IMAGE_COLOR);
    mirrored.setUseTexture(false);
    finder_2.setThreshold(50);
    finder_2.setMinAreaRadius(50);
    finder_2.setMaxAreaRadius(500);
    finder_2.setUseTargetColor(false);
    finder_2.setFindHoles(true);
    

    
    

}
void BoxDetector::threadedFunction() {
    //while (isThreadRunning()) {
        
        if (camera->isFrameNew()) {
            /// mask generator ///
            
            mirroredImage();
            
            cv::Mat mat = ofxCv::toCv(mirrored);
            
            finder_1.findContours(mat); // detection cam
            
            {
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
                
                for (int i=0; i<variable; i++) {
                    npt[i]=finder_1.getContours()[i].size();
                    temp[i]= new cv::Point[npt[i]];
                    for (int j=0; j<npt[i]; j++) {
                        temp[i][j] = finder_1.getContours()[i][j];
                    }
                }

                
                cv::fillPoly( imageContour, (const cv::Point**)temp, npt, variable, cv::Scalar( 255, 255, 255 ), 18 );
                
            } /// il y a des modif a faire ici
            cv::Mat temp;
            cv::resize(imageContour, temp, imageFond.size());
            imageDouble= temp + imageFond;
            isImage=false;
            //imageDouble=imageContour;
            isImage=true;
            // detection sur imageDouble
            contours.clear();
            finder_2.findContours(imageDouble);
            
        }
    //}
}
void BoxDetector::mirroredImage(){
    mirrored.setFromPixels(camera->getPixels());
    //mirrored.mirror(true, true);
}
void BoxDetector::draw() {
    ofSetColor(ofColor::green);
    for (int i = 0; i < finder_2.size(); i++) {
        for (int j = 0; j < finder_2.getContour(i).size(); j++) {
            ofDrawCircle(finder_2.getContour(i)[j].x, finder_2.getContour(i)[j].y, 4);
        }
    }
}

vector<ofPolyline>& BoxDetector::getContours() {
    return contours;
}


