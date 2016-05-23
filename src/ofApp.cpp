#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	joints[0].set(200, 200, 0);
	joints[1].set(400, 400, 0);
	joints[2].set(600, 200, 0);
	joints[3].set(800, 400, 0);
	target.set(1000,2300,0);


	//float angle1 = toTarget.angle(toEffector);
	//cout << "angle ; " << angle1 << endl << endl;

	//cout << "v3" << endl << v3 << endl;

	//ofVec3f v1(5, 0, 0);
	//ofVec3f v2(30, 30, 0);
	//float angle = v1.angle(v2);
	//cout << "angle : " << angle << endl;

}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	ofSetColor(255, 0, 0);
	ofDrawSphere(target, 20);

	ofSetColor(255);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 4; i++) {
		glVertex3f(joints[i].x, joints[i].y, joints[i].z);
	}
	glEnd();

	for (int i = 0; i < 4; i++) {
		ofDrawCircle(joints[i], 20);
	}

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

	//––’[‚©‚ç‚P‚Â–Ú‚ÌŠÖß
	ofVec3f VecTarget = (target - joints[2]).getNormalized();
	ofVec3f VecEffector = (joints[3] - joints[2]).getNormalized();

	ofQuaternion q;
	q.makeRotate(VecEffector, VecTarget);

	ofMatrix4x4 m;
	m.setRotate(q);
	joints[3] = (joints[3] - joints[2]) * m + joints[2];


	//––’[‚©‚ç‚Q‚Â–Ú‚ÌŠÖß
	ofVec3f VecTarget2 = (target - joints[1]).getNormalized();
	ofVec3f VecEffector2 = (joints[3] - joints[1]).getNormalized();

	ofQuaternion q2;
	q2.makeRotate(VecEffector2, VecTarget2);

	ofMatrix4x4 m2;
	m2.setRotate(q2);

	joints[2] = (joints[2] - joints[1]) * m2 + joints[1];
	joints[3] = (joints[3] - joints[1]) * m2 + joints[1];


	//––’[‚©‚ç‚R‚Â–Ú‚ÌŠÖß
	ofVec3f VecTarget3 = (target - joints[0]).getNormalized();
	ofVec3f VecEffector3 = (joints[3] - joints[0]).getNormalized();

	ofQuaternion q3;
	q3.makeRotate(VecEffector3, VecTarget3);

	ofMatrix4x4 m3;
	m3.setRotate(q3);

	joints[1] = (joints[1] - joints[0]) * m3 + joints[0];
	joints[2] = (joints[2] - joints[0]) * m3 + joints[0];
	joints[3] = (joints[3] - joints[0]) * m3 + joints[0];




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

void ofApp::transformQuaternionToRotMat(ofMatrix4x4 & m, ofQuaternion q) {
	m(0, 0) = 1.0 - 2.0f * q.y() * q.y() - 2.0f * q.z() * q.z();
	m(0, 1) = 2.0f * q.x() * q.y() + 2.0f * q.w() * q.z();
	m(0, 2) = 2.0f * q.x() * q.z() - 2.0f * q.w() * q.y();

	m(1, 0) = 2.0f * q.x() * q.y() - 2.0f * q.w() * q.z();
	m(1, 1) = 1.0f - 2.0f * q.x() * q.x() - 2.0f * q.z() * q.z();
	m(1, 2) = 2.0f * q.y() * q.z() + 2.0f * q.w() * q.x();

	m(2, 0) = 2.0f * q.x() * q.z() + 2.0f * q.w() * q.y();
	m(2, 1) = 2.0f * q.y() * q.z() - 2.0f * q.w() * q.x();
	m(2, 2) = 1.0f - 2.0f * q.x() * q.x() - 2.0f * q.y() * q.y();
}

ofVec3f ofApp::toEulerXYZ(const ofMatrix4x4 &m)
{
	ofVec3f v;

	float &thetaX = v.x;
	float &thetaY = v.y;
	float &thetaZ = v.z;

	const float &r00 = m(0, 0);
	const float &r01 = m(1, 0);
	const float &r02 = m(2, 0);

	const float &r10 = m(0, 1);
	const float &r11 = m(1, 1);
	const float &r12 = m(2, 1);

	const float &r20 = m(0, 2);
	const float &r21 = m(1, 2);
	const float &r22 = m(2, 2);

	if (r02 < +1)
	{
		if (r02 > -1)
		{
			thetaY = asinf(r02);
			thetaX = atan2f(-r12, r22);
			thetaZ = atan2f(-r01, r00);
		}
		else     // r02 = -1
		{
			// Not a unique solution: thetaZ - thetaX = atan2f(r10,r11)
			thetaY = -PI / 2;
			thetaX = -atan2f(r10, r11);
			thetaZ = 0;
		}
	}
	else // r02 = +1
	{
		// Not a unique solution: thetaZ + thetaX = atan2f(r10,r11)
		thetaY = +PI / 2;
		thetaX = atan2f(r10, r11);
		thetaZ = 0;
	}

	thetaX = ofRadToDeg(thetaX);
	thetaY = ofRadToDeg(thetaY);
	thetaZ = ofRadToDeg(thetaZ);

	return v;
}