#pragma once

#include "ofMain.h"
#include "ofxBvh.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		ofEasyCam cam;
		ofxBvh bvh;

		ofVec3f joints[4];
		ofVec3f target, target1;
		ofVec3f IkJointsPosition[27];
		ofQuaternion IkJointsRotate[27];

		int x = 0, y = 0, z = 0;
		int eff;

};
