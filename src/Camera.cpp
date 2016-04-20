#include "Camera.h"



Camera::Camera() {
	width = 0;
	height = 0;
	camera = nullptr;
}


Camera::~Camera()
{
}

void Camera::setup(CameraType type, int width, int height) {
	camType = type;
	if (camType == CameraType::WEBCAM) {
		shared_ptr<ofVideoGrabber> grabber = make_shared<ofVideoGrabber>();
		grabber->setup(width, height);
		camera = std::move(grabber);
		width = dynamic_pointer_cast<ofVideoGrabber>(camera)->getWidth();
		height = dynamic_pointer_cast<ofVideoGrabber>(camera)->getHeight();

	} else if (camType == CameraType::KINECTv1) {
		shared_ptr<ofxKinect> kinect = make_shared<ofxKinect>();
		kinect->init();
		kinect->open();
		camera = std::move(kinect);
		width = dynamic_pointer_cast<ofxKinect>(camera)->getWidth();
		height = dynamic_pointer_cast<ofxKinect>(camera)->getHeight();
	}


}

ofPixels& Camera::getPixels() {
	return camera->getPixels();
}

int Camera::getWidth() {
	return width;
}

int Camera::getHeight() {
	return height;
}

void Camera::draw(int x, int y) {
	if (camType == CameraType::WEBCAM) {
		dynamic_pointer_cast<ofVideoGrabber>(camera)->draw(x, y);
	}
	else if (camType == CameraType::KINECTv1) {
		dynamic_pointer_cast<ofxKinect>(camera)->draw(x, y);
	}
}

void Camera::draw(int x, int y, int w, int h) {
	if (camType == CameraType::WEBCAM) {
		dynamic_pointer_cast<ofVideoGrabber>(camera)->draw(x, y, w, h);
	}
	else if (camType == CameraType::KINECTv1) {
		dynamic_pointer_cast<ofxKinect>(camera)->draw(x, y, w, h);
	}
}

void Camera::update() {
	camera->update();
}

bool Camera::isFrameNew() {
	return camera->isFrameNew();
}
