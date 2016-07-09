#include "DetectorBoxAndContour.h"

// TODO: refaire tout le code

BoxDetector::~BoxDetector() {
    stopThread();
    waitForThread(true);
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
			protection = true;
				finder_2.findContours(imageDouble);
				contoursMask = finder_2.getContours();
				analyzedFinder.send(contoursMask);
            
        }
    //}
}
void BoxDetector::mirroredImage(){
    mirrored.setFromPixels(camera->getPixels());
    //mirrored.mirror(true, true);
}
void BoxDetector::draw() {

	//std::cout << "size: " << analyzedFinder[0].size() << std::endl;
	vector<vector<cv::Point>> tmp;
	analyzedFinder.tryReceive(tmp);
	//int s = analyzedFinder[0].size();
    ofSetColor(ofColor::green);
    for (int i = 0; i < tmp.size(); i++) {
        for (int j = 0; j < tmp[i].size(); j++) {
			/*
			if (s != analyzedFinder[i].size()) {
				std::cout << "problem!" << std::endl;
				std::cout << "i " << i << " j: " << j << " s: " << s << " size: " << contoursMask[i].size() << std::endl;
			}
			*/
            ofDrawCircle(tmp[i][j].x, tmp[i][j].y, 2);
        }
    }
}

vector<ofPolyline>& BoxDetector::getContours() {
    return contours;
}


