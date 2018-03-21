//--------------------------------------------------------------
//
// CS235 - Rotate Pivot Manipulator Functions
//
//  This is implemented as a set of methods in the app class
//  (and not generalied as a seperate Manipulator class)
//  as it is intended to be given as a test problem.
//
// Gaurav Gupta - SJSU - 3/17/2018
//
//
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(ofColor::black);
	rotator.setColor(ofColor::blueViolet);
	pivot.setColor(ofColor::lightGreen);

}

//  Set Pivot and Rotator Handle locations to center of image
//  and outside top edge.
//
void ofApp::setupHandles() {

	float w = picture.image.getWidth();
	float h = picture.image.getHeight();
	picture.pivot = ofVec3f(w / 2, h / 2);
	pivot.setPosition(picture.trans.x, picture.trans.y);
	rotator.setPosition(picture.trans.x, picture.trans.y - h / 2 - 20);
    pivotSelected = false;
    rotatorSelected = false;
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
// Draw picture and manipulator handles.
//
void ofApp::draw(){
	if (imageLoaded) {
		picture.draw();
		drawHandles();
	}
}

//-------------------------------------------------------------
// Draw Handles with a line connecting them
//
void ofApp::drawHandles() {
	ofDrawLine(pivot.trans, rotator.trans);
	pivot.draw();
	rotator.draw();
}

//--------------------------------------------------------------
// Delete image data
//
void ofApp::doDelete() {
	if (imageLoaded) {
		picture.image.clear();
		imageLoaded = false;
	}
}


//--------------------------------------------------------------
//
void ofApp::keyPressed(int key){
	switch (key) {
	case 'F':
	case 'f':
		ofToggleFullscreen();
		break;
	case 'd':
		doDelete();
		break;
	case 'c':
	{
		// set image in a neutral postion, reset handles
		//
		picture.rot = 0;
		picture.trans = dropPoint;
		setupHandles();
		break;
	}

	case OF_KEY_DEL:
		doDelete();
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
// mouseDragged - Do dragging of rotator and pivot handles.
//
// if rotator dragged, we need to rotate image
// if pivot dragged, update handle location but don't modifty
// actual image pivot until mouse released.
//
void ofApp::mouseDragged(int x, int y, int button){
    if(rotatorSelected){
        rotator.setPosition(x, y);
        v2.set(rotator.trans.x-pivot.trans.x, rotator.trans.y-pivot.trans.y,0);
        ofVec2f v1_new, v2_new;
        v1_new.set(v1.x, v1.y);
        v2_new.set(v2.x, v2.y);
        picture.rot =v1_new.angle(v2_new);


    }
    if(pivotSelected){

        pivot.setPosition(x, y);

    }


}

//--------------------------------------------------------------
//  mousePressed - check to see which handle we have pressed down
//  on. Save any state needed to do drag.
//
void ofApp::mousePressed(int x, int y, int button){
    if(pivot.inside(x, y)){
        cout<<"Pivot is selected at location : ( "<<x<<" , "<<y<<" )"<<endl;
        pivotSelected=true;
    }
    if(rotator.inside(x, y)){
        cout<<"Rotator is selected at location : ( "<<x<<" , "<<y<<" )"<<endl;
        rotatorSelected = true;
        v1.set(rotator.trans.x-pivot.trans.x, rotator.trans.y-pivot.trans.y,0);
    }

}

//--------------------------------------------------------------
// if pivot dragged, update pivot usign Image::setPivot().
// you need to convert from screen space to image space since pivot is in image space.
// You need to tanslate image aftewards to the screen space location of the pivot
//
void ofApp::mouseReleased(int x, int y, int button){
    if(pivotSelected){
        picture.setPivot(picture.screenToImageSpace(x, y));
        picture.trans.x =x;
        picture.trans.y =y;
        pivotSelected=false;
    }
    rotatorSelected=false;

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

//  Drop a single image into picture.  Only keeps one image at a time.
//  After images dropped. setup handles.
//
void ofApp::dragEvent(ofDragInfo dragInfo) {

	if (picture.image.load(dragInfo.files[0]) == true)
	{
		// translate image to drop location
		//
		picture.trans = ofVec3f(dragInfo.position.x, dragInfo.position.y);
		dropPoint = picture.trans;
		imageLoaded = true;
		setupHandles();

	}
	else {
		cout << "Can't load image: " << dragInfo.files[0] << endl;
	}
}
