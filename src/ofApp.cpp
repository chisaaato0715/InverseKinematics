#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//cam.setPosition(0, 0, 400);
	//cam.lookAt(ofVec3f(0, 0, 0));

	bvh.load("./kashiyuka.bvh");
	bvh.play();

	//bvh.getTpose();

	//IKåvéZópÇ…èÓïÒÇî≤Ç´èoÇ∑
	//for (int i = 0; i < bvh.getNumJoints(); i++)
	//{
	//	IkJointsPosition[i] = bvh.getJoint(i)->getPosition();
	//}

	//for (int i = 0; i < bvh.getNumJoints(); i++)
	//{
	//	IkJointsRotate[i] = bvh.getJoint(i)->getRotate();
	//}


    /*
	joints[0].set(200, 200, 0);
	joints[1].set(400, 400, 0);
	joints[2].set(600, 200, 0);
	joints[3].set(800, 400, 0);
	target.set(1000, 2300, 0);*/

}

//--------------------------------------------------------------
void ofApp::update(){

	target.set(x, y, z);

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	//cam.begin();
	easycam.begin();
	


	//for (int i = 0; i < bvh.getNumJoints(); i++)
	//{
	//	ofSetColor(ofColor::white);
	//	ofDrawSphere(IkJoints[i], 2);
	//}

	bvh.draw();
	ofSetColor(255, 0, 0);
	ofDrawSphere(target, 8);


	//ofSetColor(255,0,0);
	//ofDrawSphere(joints[13],20);

	
	//cam.end();
	easycam.end();



//	ofSetColor(255);
//	glBegin(GL_LINE_STRIP);
//	for (int i = 0; i < 4; i++) {
//		glVertex3f(joints[i].x, joints[i].y, joints[i].z);
//	}
//	glEnd();
//
//	for (int i = 0; i < 4; i++) {
//		ofDrawCircle(joints[i], 20);
//	}
//
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == OF_KEY_LEFT) {
		x += -10;
	}

	if (key == OF_KEY_RIGHT) {
		x += 10;
	}

	if (key == OF_KEY_UP) {
		y += 10;
	}

	if (key == OF_KEY_DOWN) {
		y += -10;
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

	//target.set(x, y,0);





	////ññí[Ç©ÇÁÇPÇ¬ñ⁄ÇÃä÷êﬂ
	//ofVec3f VecTarget = (target - IkJoints[11]).getNormalized();
	//ofVec3f VecEffector = (IkJoints[12] - IkJoints[11]).getNormalized();

	//ofQuaternion q;
	//q.makeRotate(VecEffector, VecTarget);

	//ofMatrix4x4 m;
	//m.setRotate(q);
	//IkJoints[12] = (IkJoints[12] - IkJoints[11]) * m + IkJoints[11];


	////ññí[Ç©ÇÁÇQÇ¬ñ⁄ÇÃä÷êﬂ
	//ofVec3f VecTarget2 = (target - joints[10]).getNormalized();
	//ofVec3f VecEffector2 = (joints[12] - joints[10]).getNormalized();

	//ofQuaternion q2;
	//q2.makeRotate(VecEffector2, VecTarget2);

	//ofMatrix4x4 m2;
	//m2.setRotate(q2);

	//IkJoints[11] = (IkJoints[11] - IkJoints[10]) * m2 + IkJoints[10];
	//IkJoints[12] = (IkJoints[12] - IkJoints[10]) * m2 + IkJoints[10];





	////ññí[Ç©ÇÁÇPÇ¬ñ⁄ÇÃä÷êﬂ
	//ofVec3f VecTarget = (target - joints[2]).getNormalized();
	//ofVec3f VecEffector = (joints[3] - joints[2]).getNormalized();

	//ofQuaternion q;
	//q.makeRotate(VecEffector, VecTarget);

	//ofMatrix4x4 m;
	//m.setRotate(q);
	//joints[3] = (joints[3] - joints[2]) * m + joints[2];


	////ññí[Ç©ÇÁÇQÇ¬ñ⁄ÇÃä÷êﬂ
	//ofVec3f VecTarget2 = (target - joints[1]).getNormalized();
	//ofVec3f VecEffector2 = (joints[3] - joints[1]).getNormalized();

	//ofQuaternion q2;
	//q2.makeRotate(VecEffector2, VecTarget2);

	//ofMatrix4x4 m2;
	//m2.setRotate(q2);

	//joints[2] = (joints[2] - joints[1]) * m2 + joints[1];
	//joints[3] = (joints[3] - joints[1]) * m2 + joints[1];


	////ññí[Ç©ÇÁÇRÇ¬ñ⁄ÇÃä÷êﬂ
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
