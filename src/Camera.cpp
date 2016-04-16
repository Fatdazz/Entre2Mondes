//
//  Camera.cpp
//  Entre2mondes
//
//  Created by FatDazz_mac on 14/04/2016.
//
//

#include "Camera.h"

void Camera::setup(CameraType ct, int camWidth, int camHeight){
    camType = ct;
	
    switch (camType) {
		case CameraType::KINECTv1:
            kinect_1 = make_shared<ofxKinect>();
            kinect_1->init();
            kinect_1->open();
            width=kinect_1->width;
            height=kinect_1->height;

			camera = kinect_1;
            break;

        case CameraType::WEBCAM:
            grabber = make_shared<ofVideoGrabber>();
            grabber->setup(camWidth, camHeight);
            width = grabber->getWidth();
            height = grabber->getHeight();

			camera = grabber;
			break;
    }
	

	/*
	if (camType == CameraType::KINECTv1){
		shared_ptr<ofxKinect> kinect_1 = make_shared<ofxKinect>();
		kinect_1->init();
		kinect_1->open();
		width = kinect_1->width;
		height = kinect_1->height;

		camera = move(kinect_1);
	}
	else if (camType == CameraType::WEBCAM){
		shared_ptr<ofVideoGrabber> grabber = make_shared<ofVideoGrabber>();
		grabber->setup(camWidth, camHeight);
		width = grabber->getWidth();
		height = grabber->getHeight();
		camera = grabber;
	}

	*/
    
}

void Camera::update(){
	
	switch (camType) {
		case CameraType::KINECTv1:
            kinect_1->update();
            break;
	case CameraType::WEBCAM:
            grabber->update();
            break;
    }
	

	//camera->update();
}

bool Camera::isFrameNew(){

	
	switch (camType) {
		case CameraType::KINECTv1:
            return kinect_1->isFrameNewVideo();
            break;
		case CameraType::WEBCAM:
            return grabber->isFrameNew();
            break;
    }
	
	//return camera->isFrameNew();
}

bool Camera::isConnected(){
	switch (camType) {
	case CameraType::KINECTv1:
            return kinect_1->isConnected();
            break;
		case CameraType::WEBCAM:
            return grabber->isInitialized();
            break;
    }
	
}

ofPixels& Camera::getPixels(){

	switch (camType) {
		case CameraType::KINECTv1:
			img = kinect_1->getPixels();
			img.mirror(true, true);
			return img.getPixels();
            break;

		case CameraType::WEBCAM:
			img.setFromPixels(grabber->getPixels());
			img.mirror(true, true);
			return img.getPixels();
			break;
    }
}

int Camera::getHeight(){
    return height;
}
int Camera::getWidth(){
    return width;
}

void Camera::draw(int x, int y, int w, int h) {
	switch (camType) {
	case CameraType::KINECTv1:
		return kinect_1->draw(0,0, w, h);
		break;
	case CameraType::WEBCAM:
		return grabber->draw(0,0, w, h);
		break;
	}
}

void Camera::draw(int x, int y) {
	switch (camType) {
	case CameraType::KINECTv1:
		return kinect_1->draw(0, 0);
		break;
	case CameraType::WEBCAM:
		return grabber->draw(0, 0);
		break;
	}
}


///////////////////////////////////
