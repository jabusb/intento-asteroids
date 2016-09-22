#include "ofApp.h"

void ofApp::createNave()
{
	nave.init(line);
	nave.addPoint(Vector3(0, 0));
}

//--------------------------------------------------------------
void ofApp::setup(){

	line.init(); 
	line.Linea(200,200,400,400,252,252,252);
}

//--------------------------------------------------------------
void ofApp::update() {

	line.update();

	
}

//--------------------------------------------------------------
void ofApp::draw(){

 line.draw(); 
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
