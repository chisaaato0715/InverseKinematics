#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	joints[0].set(200, 200, 0);
	joints[1].set(400, 400, 0);
	joints[2].set(600, 200, 0);
	joints[3].set(800, 400, 0);
	target.set(1000, 300);

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	ofSetColor(255);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 4; i++) {
		glVertex3f(joints[i].x, joints[i].y, joints[i].z);
	}
	glEnd();

	for (int i = 0; i < 4; i++) {
		ofDrawSphere(joints[i], 20);
	}
	ofDrawSphere(target, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	target.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
