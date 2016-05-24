#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	cam.setPosition(joints[0].x, joints[0].y, -400);
	cam.lookAt(ofVec3f(0, 0, 1));

	bvh.load("./kashiyuka.bvh");
	bvh.play();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	cam.begin();
	bvh.draw();
	cam.end();

	ofSetColor(255, 0, 0);
	ofDrawSphere(target1, 20);

	//ofSetColor(255);
	//glBegin(GL_LINE_STRIP);
	//for (int i = 0; i < 4; i++) {
	//	glVertex3f(joints[i].x, joints[i].y, joints[i].z);
	//}
	//glEnd();

	//for (int i = 0; i < 4; i++) {
	//	ofDrawCircle(joints[i], 20);
	//}

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

	target1.set(x, y);


	//––’[‚©‚ç‚P‚Â–Ú‚ÌŠÖß
	ofVec3f VecTarget = (target1 - joints[12]).getNormalized();
	ofVec3f VecEffector = (joints[13] - joints[12]).getNormalized();

	ofQuaternion q;
	q.makeRotate(VecEffector, VecTarget);

	ofMatrix4x4 m;
	m.setRotate(q);
	joints[13] = (joints[13] - joints[12]) * m + joints[12];


	////––’[‚©‚ç‚Q‚Â–Ú‚ÌŠÖß
	//ofVec3f VecTarget2 = (target1 - joints[11]).getNormalized();
	//ofVec3f VecEffector2 = (joints[13] - joints[11]).getNormalized();

	//ofQuaternion q2;
	//q2.makeRotate(VecEffector2, VecTarget2);

	//ofMatrix4x4 m2;
	//m2.setRotate(q2);

	//joints[12] = (joints[12] - joints[11]) * m2 + joints[11];
	//joints[13] = (joints[13] - joints[11]) * m2 + joints[11];


	////––’[‚©‚ç‚R‚Â–Ú‚ÌŠÖß
	//ofVec3f VecTarget3 = (target - joints[0]).getNormalized();
	//ofVec3f VecEffector3 = (joints[3] - joints[0]).getNormalized();

	//ofQuaternion q3;
	//q3.makeRotate(VecEffector3, VecTarget3);

	//ofMatrix4x4 m3;
	//m3.setRotate(q3);

	//joints[1] = (joints[1] - joints[0]) * m3 + joints[0];
	//joints[2] = (joints[2] - joints[0]) * m3 + joints[0];
	//joints[3] = (joints[3] - joints[0]) * m3 + joints[0];










	//joints[0].set(200, 200, 0);
	//joints[1].set(400, 400, 0);
	//joints[2].set(600, 200, 0);
	//joints[3].set(800, 400, 0);
	//target1.set(1000, 2300, 0);

	////––’[‚©‚ç‚P‚Â–Ú‚ÌŠÖß
	//ofVec3f VecTarget = (target - joints[2]).getNormalized();
	//ofVec3f VecEffector = (joints[3] - joints[2]).getNormalized();

	//ofQuaternion q;
	//q.makeRotate(VecEffector, VecTarget);

	//ofMatrix4x4 m;
	//m.setRotate(q);
	//joints[3] = (joints[3] - joints[2]) * m + joints[2];


	////––’[‚©‚ç‚Q‚Â–Ú‚ÌŠÖß
	//ofVec3f VecTarget2 = (target - joints[1]).getNormalized();
	//ofVec3f VecEffector2 = (joints[3] - joints[1]).getNormalized();

	//ofQuaternion q2;
	//q2.makeRotate(VecEffector2, VecTarget2);

	//ofMatrix4x4 m2;
	//m2.setRotate(q2);

	//joints[2] = (joints[2] - joints[1]) * m2 + joints[1];
	//joints[3] = (joints[3] - joints[1]) * m2 + joints[1];


	////––’[‚©‚ç‚R‚Â–Ú‚ÌŠÖß
	//ofVec3f VecTarget3 = (target - joints[0]).getNormalized();
	//ofVec3f VecEffector3 = (joints[3] - joints[0]).getNormalized();

	//ofQuaternion q3;
	//q3.makeRotate(VecEffector3, VecTarget3);

	//ofMatrix4x4 m3;
	//m3.setRotate(q3);

	//joints[1] = (joints[1] - joints[0]) * m3 + joints[0];
	//joints[2] = (joints[2] - joints[0]) * m3 + joints[0];
	//joints[3] = (joints[3] - joints[0]) * m3 + joints[0];




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
