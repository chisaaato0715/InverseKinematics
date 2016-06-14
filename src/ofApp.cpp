#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){


	bvh.load("./aachan.bvh");

	//bvh.play();


}

//--------------------------------------------------------------
void ofApp::update(){

	bvh.updateIK(bvh.joints[bvh.selectjoint]);

	//bvh.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	cam.begin();

	bvh.draw();


	ofSetColor(255, 0, 0);
	ofDrawSphere(bvh.target, 8);


	cam.end();

	int n = bvh.getNumJoints();
	float nearestDistance = 0;
	ofVec2f mouse(mouseX, mouseY);
	for (int i = 0; i < n; i++) {
		ofVec3f cur = cam.worldToScreen(bvh.joints[i]->getPosition());
		float distance = cur.distance(mouse);
		if (i == 0 || distance < nearestDistance) {
			nearestDistance = distance;
			nearestJoint = cur;
			nearestIndex = i;
		}
	}
	ofSetColor(ofColor::gray);
	ofDrawLine(nearestJoint, mouse);

	ofNoFill();
	ofSetColor(ofColor::yellow);
	ofSetLineWidth(2);
	ofDrawCircle(nearestJoint, 4);
	ofSetLineWidth(1);

	ofVec2f offset(10, -10);
	ofDrawBitmapStringHighlight(ofToString(nearestIndex), mouse + offset);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 'a') {
		bvh.selectjoint = 12;
	}
	if (key == 'd') { 
		bvh.selectjoint = 17;
	}
	if (key == 'z') { 
		bvh.selectjoint = 22; 
	}
	if (key == 'x') { 
		bvh.selectjoint = 27; 
	}

	if (key == 'c') {
		cam.disableMouseInput();
	}

	if (key == 'v') {
		cam.enableMouseInput();
	}

	if (key == 'r') {
		
		cam.reset();

	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

	//bvh.target = ofVec3f(x - ofGetWidth() / 2.0, -(y - ofGetHeight() / 2.0), 0);
	bvh.target = cam.worldToScreen(ofVec3f(x - ofGetWidth() / 2.0, -(y - ofGetHeight() / 2.0), 0));
	//bvh.target = ofVec3f(x - ofGetWidth() / 2.0, - (y - ofGetHeight() / 2.0), 0)* cam.getGlobalTransformMatrix().getInverse();
	//bvh.target = ofVec3f(x - ofGetWidth() / 2.0, -(y - ofGetHeight() / 2.0), 0);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	//bvh.target = ofVec3f(x - ofGetWidth() / 2.0,- ( y - ofGetHeight() / 2.0), 0);
	bvh.target = cam.worldToScreen(ofVec3f(x - ofGetWidth() / 2.0, -(y - ofGetHeight() / 2.0), 0));
	//bvh.target = ofVec3f(x - ofGetWidth() / 2.0, -(y - ofGetHeight() / 2.0), 0);


	bvh.selectjoint = nearestIndex;



}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
