#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*----------------- OF SETUP ------------------*/
	ofEnableSmoothing();
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    /*------------------ DRAWING ------------------*/
    isDrawing = false;
    shapeSmoothing = 1;
    // Margins: top, right, bottom, left
    margins[0] = 20;
    margins[1] = 20;
    margins[2] = 20;
    margins[3] = 240;
    setCanvas();
    
    /*-------------------- GUI --------------------*/
    setGUI();
    
    /*-------------------- 3D ---------------------*/
    useCamera = false;
//    ofSetSmoothLighting(true);
    light.setDiffuseColor(ofFloatColor(1.0, 0.9, 0.8));
//    light.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    light.setPosition(ofPoint(-ofGetWidth()*0.5, 0.0, 0.0));
    cam.setVFlip(true); // you need this, otherwise the camera starts flipped vertically
                        // I have no idea why
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < shapes.size(); i++){
        shapes[i].update(shapeSmoothing);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofNoFill();
    ofSetColor(255);
    ofSetLineWidth(1);
    ofRect(canvasPos, canvasSize.x, canvasSize.y);

    if(useCamera){
        cam.begin();
        light.enable();
        ofEnableLighting();
        ofEnableDepthTest();
    }else{
        // If there's no camera ('drawing mode'), push matrix to center
        ofPushMatrix();
        ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
    }
    
    for(int i = 0; i < shapes.size(); i++){
        shapes[i].draw(useCamera);
    }
    
    if(useCamera){
        ofDisableDepthTest();
        ofDisableLighting();
        light.disable();
        cam.end();
        
        ofDrawBitmapString("Drag: rotate camera\nCTRL+drag: zoom\nALT+drag: pan"
                           , 20, ofGetHeight() - 40);
    }else{
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // Activate camera
    if(key == 32){
        useCamera = !useCamera;
        cam.reset();
        cam.enableMouseInput();
        
    // Erase lines
    }else if(key == 'e'){
        while(shapes.size() > 0){
            int i = shapes.size() - 1;
            shapes.erase(shapes.begin() + i);
        }

    }else if(key == 'g'){
        gui->toggleVisible();        
    
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    if(useCamera){
       if(x < margins[3] || x > ofGetWidth() - margins[1] ||
          y < margins[0] || y > ofGetHeight() - margins[2]){
            cam.disableMouseInput();
       }else{
            cam.enableMouseInput();
       }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(!useCamera &&
       x > margins[3] && x < ofGetWidth() - margins[1] &&
       y > margins[0] && y < ofGetHeight() - margins[2]){
        Ribbon newRibbon;
        // Save coordinates based on the center
        newRibbon.setup(x - ofGetWidth()*0.5, y - ofGetHeight()*0.5);
        shapes.push_back(newRibbon);
        isDrawing = true;
    }
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    isDrawing = false;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(isDrawing &&
       x > margins[3] && x < ofGetWidth() - margins[1] &&
       y > margins[0] && y < ofGetHeight() - margins[2]){
            if(!useCamera){
                // Save coordinates based on the center
                shapes[shapes.size() - 1].addPoint(x - ofGetWidth()*0.5, y - ofGetHeight()*0.5);
            }else{
                cam.enableMouseInput();
            }
    }else{
        isDrawing = false;
    }
}

void ofApp::setCanvas(){
    canvasPos.set(margins[3], margins[0]);
    canvasSize.set(ofGetWidth() - margins[1] - margins[3], ofGetHeight() - margins[0] - margins[2]);
}

void ofApp::setGUI(){
    
    gui = new ofxUISuperCanvas("SHAPE");
    ofColor guiColor = ofColor(0, 150, 200, 100);
    gui->setColorFill(255);
    gui->setColorBack(guiColor);
    
    gui->addSpacer();
    
    gui->addToggle("3D", useCamera);
    gui->addSpacer();
    
    gui->addSlider("SMOOTH", 1, 5, shapeSmoothing);
    gui->addSpacer();
    
    gui->addToggle("FULLSCREEN", TRUE);
    
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
    gui->loadSettings("guiSettings.xml");
}

void ofApp::guiEvent(ofxUIEventArgs &e){
    
	string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if(e.getName() == "FULLSCREEN"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());
        setCanvas();
        
	}else if(name == "3D"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        useCamera = toggle->getValue();
        cam.reset();
        cam.enableMouseInput();        
        
    }else if(name == "SMOOTH"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		shapeSmoothing = slider->getScaledValue();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
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
