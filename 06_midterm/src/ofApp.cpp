/*--------------------------------------------------------------
 Ribbon mesh code adapted from:
 oF > examples > 3d > cameraRibbonExample, by James George
--------------------------------------------------------------*/
 
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*----------------- OF SETUP ------------------*/
	ofEnableSmoothing();
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetWindowShape(1280, 720);
    
    /*------------------ DRAWING ------------------*/
    isDrawing = false;
    shapeSmoothing = 1;
    // Margins: top, right, bottom, left
    margins[0] = 20;
    margins[1] = 20;
    margins[2] = 20;
    margins[3] = 240;
    setCanvas();
    thickness = 10;
    
    /*-------------------- GUI --------------------*/
    cursorModes.push_back("camera/draw");
    cursorModes.push_back("modify");
    setGUI();
    
    /*-------------------- 3D ---------------------*/
    useCamera = false;
//    ofSetSmoothLighting(true);
    light.setDiffuseColor(ofFloatColor(1.0, 0.9, 0.8));
//    light.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    light.setPosition(ofPoint(-ofGetWidth()*0.5, 0.0, 0.0));
    cam.setVFlip(true); // you need this, otherwise the camera starts flipped vertically
                        // I have no idea why
    zDepth = -1;
    
    /*----------------- PHYSICS -------------------*/
    mouseRadius = 10;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(selectedCursorMode == "modify"){
        for (int i = 0; i < shapes.size(); i++) {
            shapes[i].update();
        }
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
        ofPushMatrix();
        ofTranslate(-ofGetWidth()*0.5, -ofGetHeight()*0.5);
    }
    
    for(int i = 0; i < shapes.size(); i++){
        shapes[i].draw(useCamera, thickness, zDepth);
    }
    
    if(selectedCursorMode == "modify"){
        ofNoFill();
        ofSetLineWidth(1);
        ofSetColor(255);
        ofCircle(mouseX, mouseY, mouseRadius);
    }
    
    if(useCamera){
        ofPopMatrix();
        ofDisableDepthTest();
        ofDisableLighting();
        light.disable();
        cam.end();
        
        ofDrawBitmapString("Drag: rotate camera\nCTRL+drag: zoom\nALT+drag: pan"
                           , 20, ofGetHeight() - 40);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // Activate camera
    if(key == 32){
        
        
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
void ofApp::mousePressed(int x, int y, int button){
    
    if(selectedCursorMode != "modify"){
        // Add new ribbon, only if mouse is within the canvas AND not on 3D mode
        if(!useCamera &&
           x > margins[3] && x < ofGetWidth() - margins[1] &&
           y > margins[0] && y < ofGetHeight() - margins[2]){

            Ribbon newRibbon;
            newRibbon.setup(x, y);
            shapes.push_back(newRibbon);
            isDrawing = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    // Camera is only enabled inside the canvas area
    if(useCamera &&
       selectedCursorMode != "modify" &&
       x > margins[3] && x < ofGetWidth() - margins[1] &&
       y > margins[0] && y < ofGetHeight() - margins[2]){

       cam.enableMouseInput();

    }else{
        cam.disableMouseInput();
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(selectedCursorMode != "modify"){
        
        if(!useCamera &&
           isDrawing &&
           x > margins[3] && x < ofGetWidth() - margins[1] &&
           y > margins[0] && y < ofGetHeight() - margins[2]){
            
            shapes[shapes.size() - 1].addPoint(x, y);

        }else{
            // this stops drawing when the mouse leave the canvas area
            isDrawing = false;
        }
        
    }else{

    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    // Whatever mode we're in (modify, camera, drawing...), releasing the mouse stops drawing
    isDrawing = false;
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
    
    gui->addSlider("RIBBON THICKNESS", 2, 50, thickness);
    gui->addSpacer();
    
    gui->addToggle("3D", useCamera);
    gui->addSpacer();
    
    gui->addSlider("Z DEPTH", -1, -50, zDepth);
    gui->addSpacer();
    
	gui->addRadio("CURSOR MODE", cursorModes, OFX_UI_ORIENTATION_VERTICAL);
    gui->addSpacer();
    
    gui->addSlider("SMOOTH", 1, 5, shapeSmoothing);
	gui->addButton("APPLY", false);
	gui->addButton("RESET", false);
    gui->addSpacer();
    
    gui->addSlider("MOUSE RADIUS", 10, 200, mouseRadius);
    gui->addSpacer();
    
    gui->addToggle("FULLSCREEN", false);
    
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
//    gui->loadSettings("guiSettings.xml");
}

void ofApp::guiEvent(ofxUIEventArgs &e){
    
	string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if(name == "RIBBON THICKNESS"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        thickness = slider->getScaledValue();
    
	}else if(name == "3D"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        useCamera = toggle->getValue();
        cam.reset();
        cam.enableMouseInput();

    }else if(name == "Z DEPTH"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		zDepth = slider->getScaledValue();
        
    }else if(name == "SMOOTH"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		shapeSmoothing = round(slider->getScaledValue());

    }else if(name == "APPLY"){
		ofxUIButton *button = (ofxUIButton *) e.getButton();
        if(button->getValue()){
            for (int i = 0; i < shapes.size(); i++) {
                shapes[i].applySmoothing(shapeSmoothing);
            }
        }
        
    }else if(name == "RESET"){
        ofxUIButton *button = (ofxUIButton *) e.getButton();
        if(button->getValue()){
            for (int i = 0; i < shapes.size(); i++) {
                shapes[i].resetSmoothing();
            }
        }

    }else if(name == "CURSOR MODE"){
        ofxUIRadio *radio = (ofxUIRadio *) e.widget;
        selectedCursorMode = radio->getActiveName();
        
    }else if(name == "MOUSE RADIUS"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		mouseRadius = slider->getScaledValue();
        
    }else if(e.getName() == "FULLSCREEN"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());
        setCanvas();
    }
}

void ofApp::exit(){
    gui->saveSettings("guiSettings.xml");
	delete gui;
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
