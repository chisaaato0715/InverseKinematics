#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	endjoint = 12;
	//bvh.countParent(bvh.joints[12]);

	bvh.load("./aachan.bvh");

	//bvh.play();


}

//--------------------------------------------------------------
void ofApp::update(){

	target.set(x, y, z);

	bvh.updateIK(target,bvh.joints[endjoint]);

	//bvh.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	cam.begin();
	//cam.disableMouseInput()
	//cam.enableMouseInput();

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

	if (key == 'a') {
		endjoint = 12;
		x = bvh.joints[12]->getPosition().x;
		y = bvh.joints[12]->getPosition().y;
		z = bvh.joints[12]->getPosition().z;
	}
	if (key == 'd') { 
		endjoint = 17;
		x = bvh.joints[17]->getPosition().x;
		y = bvh.joints[17]->getPosition().y;
		z = bvh.joints[17]->getPosition().z;	
	}
	if (key == 'z') { 
		endjoint = 22; 
		x = bvh.joints[22]->getPosition().x;
		y = bvh.joints[22]->getPosition().y;
		z = bvh.joints[22]->getPosition().z;
	}
	if (key == 'c') { 
		endjoint = 27; 
		x = bvh.joints[27]->getPosition().x;
		y = bvh.joints[27]->getPosition().y;
		z = bvh.joints[27]->getPosition().z;
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
