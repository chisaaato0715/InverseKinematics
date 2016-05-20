#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	joints[0].set(200, 200, 0);
	joints[1].set(400, 400, 0);
	joints[2].set(600, 200, 0);
	joints[3].set(800, 400, 0);
	target.set(1000, 300,0);

	//ofVec3f v(10, 0, 0);
	//cout << v << endl;
	//v.normalize();

	ofVec3f toTarget = target - joints[2];          //基準関節→ターゲットへの方向ベクトル
	ofVec3f toEffector = joints[3] - joints[2];     //基準関節→エフェクタへの方向ベクトル

	ofQuaternion q;
	q.makeRotate(toTarget, toEffector);

	ofMatrix4x4 mat = q;
	cout << mat << endl;

	v3 = toEffector * mat;


	ofVec3f v1(5, 0, 0);
	ofVec3f v2(30, 30, 0);
	float angle = v1.angle(v2);
	cout << "angle : " << angle << endl;

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

	ofSetColor(255, 0, 0);
	ofLine(joints[2], target);

	ofSetColor(255, 0, 0);
	ofDrawSphere(v3,10);

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
