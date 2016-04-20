#pragma once

#include "ofMain.h"
#include "ofxKinect.h"

enum class CameraType {WEBCAM, KINECTv1, KINECTv2};

class Camera
{
public:
	Camera();
	~Camera();

	void setup(CameraType type, int width = 640, int height = 480);
	void draw(int x, int y);
	void draw(int x, int y, int w, int h);
	void update();
	bool isFrameNew();

	ofPixels& getPixels();

	shared_ptr<ofBaseVideo> camera;
	int width;
	int height;

	int getWidth();
	int getHeight();

	CameraType camType;

};

