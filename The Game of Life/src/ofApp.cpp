#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	fps = 8;
	ofSetFrameRate(fps);
	ofSetBackgroundColor(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	pool.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	pool.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_RIGHT) fps = fps + 2;
	if (key == OF_KEY_LEFT)
	{
		if (fps >= 2)
		{
			fps = fps - 2;
		}
	}
	if (fps >= 2) ofSetFrameRate(fps);
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
