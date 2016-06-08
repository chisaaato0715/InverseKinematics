#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//eff = 17;

	bvh.load("./aachan.bvh");

	//bvh.play();

	////IKåvéZópÇ…èÓïÒÇî≤Ç´èoÇ∑
	//for (int i = 0; i < bvh.getNumJoints(); i++)
	//{
	//	IkJointsPosition[i] = bvh.getJoint(i)->getPosition(); 
	//}

	//for (int i = 0; i < bvh.getNumJoints()-1; i++)
	//{
	//	IkJointsRotate[i] = bvh.getJoint(i+1)->getRotate();
	//}


}

//--------------------------------------------------------------
void ofApp::update(){

	target.set(x, y, z);

	bvh.updateIK(target,bvh.joints[0]);


	////ññí[Ç©ÇÁÇPÇ¬ñ⁄ÇÃä÷êﬂ
	//ofVec3f VecTarget = (target - IkJointsPosition[eff-1]).getNormalized();
	//ofVec3f VecEffector = (IkJointsPosition[eff] - IkJointsPosition[eff-1]).getNormalized();

	//ofQuaternion q;
	//q.makeRotate(VecEffector, VecTarget);

	//ofMatrix4x4 m;
	//m.setRotate(q);
	//IkJointsPosition[eff] = (IkJointsPosition[eff] - IkJointsPosition[eff-1]) * m + IkJointsPosition[eff-1];


	////ññí[Ç©ÇÁÇQÇ¬ñ⁄ÇÃä÷êﬂ
	//ofVec3f VecTarget2 = (target - IkJointsPosition[eff-2]).getNormalized();
	//ofVec3f VecEffector2 = (IkJointsPosition[eff] - IkJointsPosition[eff-2]).getNormalized();

	//ofQuaternion q2;
	//q2.makeRotate(VecEffector2, VecTarget2);

	//ofMatrix4x4 m2;
	//m2.setRotate(q2);

	//IkJointsPosition[eff-1] = (IkJointsPosition[eff-1] - IkJointsPosition[eff-2]) * m2 + IkJointsPosition[eff-2];
	//IkJointsPosition[eff] = (IkJointsPosition[eff] - IkJointsPosition[eff-2]) * m2 + IkJointsPosition[eff-2];

	////ññí[Ç©ÇÁÇRÇ¬ñ⁄ÇÃä÷êﬂ
	//ofVec3f VecTarget3 = (target - IkJointsPosition[eff-3]).getNormalized();
	//ofVec3f VecEffector3 = (IkJointsPosition[eff] - IkJointsPosition[eff-3]).getNormalized();

	//ofQuaternion q3;
	//q3.makeRotate(VecEffector3, VecTarget3);

	//ofMatrix4x4 m3;
	//m3.setRotate(q3);

	//IkJointsPosition[eff-2] = (IkJointsPosition[eff-2] - IkJointsPosition[eff-3]) * m3 + IkJointsPosition[eff-3];
	//IkJointsPosition[eff-1] = (IkJointsPosition[eff-1] - IkJointsPosition[eff-3]) * m3 + IkJointsPosition[eff-3];
	//IkJointsPosition[eff] = (IkJointsPosition[eff] - IkJointsPosition[eff-3]) * m3 + IkJointsPosition[eff-3];

	////ññí[Ç©ÇÁÇSÇ¬ñ⁄ÇÃä÷êﬂ
	//ofVec3f VecTarget4 = (target - IkJointsPosition[eff - 4]).getNormalized();
	//ofVec3f VecEffector4 = (IkJointsPosition[eff] - IkJointsPosition[eff - 4]).getNormalized();

	//ofQuaternion q4;
	//q4.makeRotate(VecEffector4, VecTarget4);

	//ofMatrix4x4 m4;
	//m4.setRotate(q4);

	//IkJointsPosition[eff - 3] = (IkJointsPosition[eff - 3] - IkJointsPosition[eff - 4]) * m4 + IkJointsPosition[eff - 4];
	//IkJointsPosition[eff - 2] = (IkJointsPosition[eff - 2] - IkJointsPosition[eff - 4]) * m4 + IkJointsPosition[eff - 4];
	//IkJointsPosition[eff - 1] = (IkJointsPosition[eff - 1] - IkJointsPosition[eff - 4]) * m4 + IkJointsPosition[eff - 4];
	//IkJointsPosition[eff] = (IkJointsPosition[eff] - IkJointsPosition[eff - 4]) * m4 + IkJointsPosition[eff - 4];


	//bvh.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	cam.begin();
	

	//for (int i = 0; i < bvh.getNumJoints(); i++)
	//{
	//	ofSetColor(ofColor::white);
	//	ofDrawSphere(IkJointsPosition[i], 2);
	//}


	bvh.draw();

	ofSetColor(255, 0, 0);
	ofDrawSphere(target, 8);

	cam.end();

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

	if (key == 'q') {
		eff = 17;
	}
	if (key == 'w') {
		eff = 12;
	}
	if (key == 'e') {
		eff = 27;
	}
	if (key == 'r') {
		eff = 22;
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
