/* ---------------------------------------------------------------------
 Created by Gabriel Gianordoli on November, 2014
 Repo: https://github.com/gianordoli/giang063_sims2014
 
 MFA Design and Technology, Parsons The New School for Design
 [Creative Coding: Simulation Studio] Professor Patricio Gonzalez Vivo
 Class repo: github.com/patriciogonzalezvivo/sims2014
 
 Ribbon mesh code adapted from:
 oF > examples > 3d > cameraRibbonExample, by James George
 
 Spring and Vector Field code adapted from Charlie Whitney's examples
 ---------------------------------------------------------------------*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*----------------- OF SETUP ------------------*/
    ofEnableSmoothing();
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
//    ofSetWindowShape(1280, 720);
    ofToggleFullscreen();
    
    /*------------------ DRAWING ------------------*/
    isDrawing = false;

    // Margins: top, right, bottom, left
    margins[0] = 20;
    margins[1] = 20;
    margins[2] = 20;
    margins[3] = 240;
    setCanvas(ofGetWidth(), ofGetHeight());
    thickness = 10;
    isErasing = false;
    
    
    /*----------------- PHYSICS -------------------*/
    addForceRadius = 10.0;
    addForceStrength = 0.25;
    
    // "Wind" controls
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
//    myField.setPerlin();
    initMouse.set(0.0, 0.0);
    
    
    /*----------------- OSCILLATE -------------------*/
    amplitude = 50.0f;
    frequencyInSeconds = 10.0f;
    nModifier = 100;
    isOscillating = false;
    
    
    /*-------------------- 3D ---------------------*/
    
    zDepth = -1.0;
    thickness = 10.0;
    
    lightColor.set(1.0, 0.0, 0.0);
    //    ofSetSmoothLighting(true);
    light.setDiffuseColor(lightColor);
    //    light.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    light.setPosition(ofPoint(-ofGetWidth()*0.5, 0.0, 10.0));
    cam.setVFlip(true); // you need this, otherwise the camera starts flipped vertically
    // I have no idea why
//    zDepth = -1;
    material.setShininess( 120 );
    // the light highlight of the material //
    material.setSpecularColor(ofColor(255, 255, 255, 255));
    
    
    /*----------------- PLAYBACK -------------------*/
    totalVertices = 0;
    playbackSlider = 1;
    snapCounter = 0;
    isRecording = false;
    isSnapshoting = false;
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    fbo.begin();
    ofClear(0);
    fbo.end();
    pixels.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
    

    /*-------------------- GUI --------------------*/
    modes.push_back("camera");
    modes.push_back("draw");
    modes.push_back("repulsion");
    modes.push_back("attraction");
    modes.push_back("wind");
    selectedMode = "draw";
    setGUI();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // This variable controls the ribbons drawing playback
    // (see nVerices inside the FBO below)
    // Because the number of vertices might change inside the Ribbon class,
    // we need to keep track of the total during every frame.
    totalVertices = getTotalVertices();
    
    // Any physics simulation mode (repulsion, oscillate, wind...)
    // only takes place if te user is not drawing
    if(shapes.size() > 0 && selectedMode != "draw"){
        
        // Update physics (doesn't depend on wind)
        for (int i = 0; i < shapes.size(); i++) {
            shapes[i].updatePhysics(selectedMode, ofPoint(mouseX, mouseY), addForceRadius, addForceStrength);
        }

        // For every mode besides oscillation, update physics
        // This is because oscillation look weird with the springs simulation
        if(isOscillating){
            for (int i = 0; i < shapes.size(); i++) {
                shapes[i].updateOscillation(amplitude, frequencyInSeconds ,nModifier);
            }
        }
            
        // Wind?
        if(selectedMode == "wind"){
            // Only changes direction if user is dragging the mouse
            if (isWinding) {
                ofVec2f dir = ofVec2f(mouseX, mouseY) - initMouse;
                myField.setDirection(dir);
            }
            // Sending the field to each ribbon
            for (int i = 0; i < shapes.size(); i++) {
                shapes[i].updateWind(myField);
            }
            // Damping
            myField.update();
        }
    }
//    else{
//
//        }
//    }
    
    
    // Draw the whole scene in an FBO
    fbo.begin();
    
        ofClear(0);
    
        if(selectedMode != "draw"){
            cam.begin();
            light.enable();
            ofEnableLighting();
            ofEnableDepthTest();
            material.begin();
            ofPushMatrix();
            ofTranslate(-ofGetWidth()*0.5, -ofGetHeight()*0.5);
        }
        
        //    cout << totalVertices << endl;
        int nVertices = ofMap(playbackSlider, 0, 1, 0, totalVertices);
        //    cout << v << endl;
        for(int i = 0; i < shapes.size(); i++){
            if(nVertices > 0){
                shapes[i].draw(selectedMode, isOscillating, nVertices, thickness, zDepth, lightColor);
            }
            nVertices -= shapes[i].currentLine.size();
        }
        
        if(selectedMode != "draw"){
            ofPopMatrix();
            material.end();
            ofDisableDepthTest();
            ofDisableLighting();
            light.disable();
            cam.end();
            
        }else{
            cam.reset();
        }
    
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    // Drawing
    ofSetColor(255, 255);
    ofEnableAlphaBlending();
    fbo.draw(0, 0);

    // Canvas
    ofNoFill();
    if(isRecording){
        int flashRed = powf(1 - (sin(ofGetElapsedTimef()*5)*.5 + .5), 2) * 255;
        ofSetColor(255, 255-flashRed, 255-flashRed);
    }else{
        ofSetColor(255);
    }
    ofSetLineWidth(1);
    ofRect(canvasPos, canvasSize.x, canvasSize.y);
    
//    ofSetColor(255, 50);
//    myField.draw();
    
    if(selectedMode != "draw"){
        
        // Vector Field ("wind")
        if(selectedMode == "wind"){
            
            ofDrawBitmapString("WIND CONTROLS\n---------------\nClick and drag to set\nspeed and direction", 20, ofGetHeight() - 80);
            
            if(isWinding){
                ofPushMatrix();
                    ofTranslate(initMouse.x, initMouse.y);
                    
                    ofVec2f mouseDir(mouseX - initMouse.x, mouseY - initMouse.y);
                    ofRotate(ofRadToDeg(atan2(mouseDir.y, mouseDir.x)) - 90);
                    
                        // Line
                        ofNoFill();
                        ofSetLineWidth(1);
                        ofSetColor(255);
                        ofLine(0, 0, 0, mouseDir.length());
                        
                        // Cap
                        ofTranslate(0, mouseDir.length());
                            ofFill();
                            ofTriangle(0, 0, - 5, - 5, 5, - 5);
                
                ofPopMatrix();
            }
            
        }else{
            
            // Camera controls
            ofDrawBitmapString("CAMERA CONTROLS\n---------------\nDrag: rotate camera\nCTRL+drag: zoom\nALT+drag: pan", 20, ofGetHeight() - 80);
            
            // Mouse modifier
            if(selectedMode == "repulsion" || selectedMode == "attraction"){
                ofNoFill();
                ofSetLineWidth(1);
                ofSetColor(255);
                ofCircle(mouseX, mouseY, addForceRadius);
            }
        }
    }
    
    // Save frames
    if(isRecording || isSnapshoting){
        
        //get the frame buffer pixels
        fbo.readToPixels(pixels);
        
        //save
        ofSaveImage(pixels,  "snapshot_"+ofToString(10000+snapCounter)+".tif");
        snapCounter++;
        
        if (isSnapshoting) {
            isSnapshoting = false;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g'){
        gui->toggleVisible();
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // Whatever mode we're at, the camera controls
    // are only enabled inside the canvas area
    if((x < canvasPos.x || x > canvasPos.x + canvasSize.x ||
        y < canvasPos.y || y > canvasPos.y + canvasSize.y)){
        cam.disableMouseInput();

    // Wind, on the other hand, is only enabled inside
    }else if(selectedMode == "wind"){
        isWinding = true;
        initMouse.set(x, y);
        cam.disableMouseInput();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    /*------------------ DRAWING MODE ------------------*/
    
    // Create new ribbon or add new point
    // Conditions: drawing mode AND mouse within canvas
    if(selectedMode == "draw"){
        if(x > canvasPos.x && x < canvasPos.x + canvasSize.x &&
           y > canvasPos.y && y < canvasPos.y + canvasSize.y){
        
            // First point
            // Conditions: mouse is moving (compare with previous coordinates)
            // The app starts with the mouse at 0, 0
            if(!isDrawing &&
               ofGetPreviousMouseX() != x && ofGetPreviousMouseX() != 0 &&
               ofGetPreviousMouseY() != y && ofGetPreviousMouseY() != 0){
                cout << "Added new line" << endl;
                Ribbon newRibbon;
                newRibbon.setup(ofGetPreviousMouseX(), ofGetPreviousMouseY());
                newRibbon.addPoint(x, y);
                shapes.push_back(newRibbon);
                isDrawing = true; // SWITCH

            // Current point (if at least one ribbon has been created)
            }else if(shapes.size() > 0 && isDrawing){
                shapes[shapes.size() - 1].addPoint(x, y);
            }

        // this stops drawing when the mouse leave the canvas area
        }else{
            isDrawing = false;
            if(shapes.size() > 0){
                shapes[shapes.size() - 1].createParticles();
                shapes[shapes.size() - 1].connectSprings();
    //            cout << shapes[shapes.size() - 1].myParticles.size();
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if(isDrawing){
        shapes[shapes.size() - 1].createParticles();
        shapes[shapes.size() - 1].connectSprings();
    }
    // Whatever mode we're at, releasing the mouse stops:
    isDrawing = false;
    isWinding = false;
    cam.enableMouseInput();    
}

void ofApp::setCanvas(int _w, int _h){
    canvasPos.set(margins[3], margins[0]);
    canvasSize.set(_w - margins[1] - margins[3], _h - margins[0] - margins[2]);
}

void ofApp::eraseShapes(){
    // "Freeze" the particles update by changing the current mode to draw
    selectedMode = "draw";
    ((ofxUIRadio *)gui->getWidget("MODE"))->activateToggle(selectedMode);
    
    while(shapes.size() > 0){
        int i = shapes.size() - 1;
        shapes[i].eraseParticles();
        shapes[i].eraseSprings();
        shapes.erase(shapes.begin() + i);
    }
    shapes.clear();    
}

int ofApp::getTotalVertices(){
    int total = 0;
    for (int i = 0; i < shapes.size(); i++) {
        total += shapes[i].currentLine.size();
    }
    return total;
}

void ofApp::setGUI(){
    
    gui = new ofxUISuperCanvas("CONTROLS");
    ofColor guiColor = ofColor(0, 150, 200, 100);
    gui->setColorFill(255);
    gui->setColorBack(guiColor);
    gui->addSpacer();
    
    gui->addLabel("MODES");
    gui->addRadio("MODE", modes, OFX_UI_ORIENTATION_VERTICAL);
    ((ofxUIRadio *)gui->getWidget("MODE"))->activateToggle(selectedMode);
    gui->addSpacer();

    gui->addLabel("SHAPES");
    gui->addButton("APPLY SMOOTHING", false);
    gui->addButton("RESET SHAPES", false);
    gui->addButton("ERASE SHAPES", false);
    gui->addSlider("RED", 0.0, 1.0, lightColor.r);
    gui->addSlider("GREEN", 0.0, 1.0, lightColor.g);
    gui->addSlider("BLUE", 0.0, 1.0, lightColor.b);
    gui->addSpacer();

    gui->addLabel("3D");
    gui->addSlider("THICKNESS", 2.0, 50.0, thickness);
    gui->addSlider("DEPTH", -1.0, -20.0, zDepth);
    gui->addSpacer();
    
    gui->addLabel("REPULSION/ATTRACTION");
    gui->addSlider("FORCE RADIUS", 10.0, 200.0, addForceRadius);
    gui->addSlider("FORCE STRENGTH", 0.1, 1.0, addForceStrength);
    
    gui->addLabel("OSCILLATION");
    gui->addToggle("OSCILLATE", isOscillating);
    gui->addSlider("AMPLITUDE", 2.0, 200.0, amplitude);
    gui->addSlider("FREQUENCY", 1, 10, frequencyInSeconds);
    gui->addSlider("LENGTH", 0, 200, nModifier);
    
    gui->addLabel("VIDEO");
    gui->addSlider("PLAYBACK", 0, 1, playbackSlider);
    gui->addButton("TAKE SNAPSHOT", false);
    gui->addToggle("RECORD SEQUENCE", isRecording);
    gui->addSpacer();

//    gui->addSpacer();
//    gui->addToggle("FULLSCREEN", false);
    
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
//    gui->loadSettings("guiSettings.xml");
}

void ofApp::guiEvent(ofxUIEventArgs &e){
    
    string name = e.widget->getName();
    int kind = e.widget->getKind();
    
    // CURSOR -------------------------------------------
    if(name == "MODE"){
        ofxUIRadio *radio = (ofxUIRadio *) e.widget;
        selectedMode = radio->getActiveName();
        
    
    // DRAWING ------------------------------------------

    }else if(name == "APPLY SMOOTHING" || name == "RESET SHAPES" || name == "ERASE SHAPES"){

        // "Freeze" the particles update by changing the current mode to draw
        selectedMode = "draw";
        ((ofxUIRadio *)gui->getWidget("MODE"))->activateToggle(selectedMode);
        
        if(name == "APPLY SMOOTHING"){
            ofxUIButton *button = (ofxUIButton *) e.getButton();
            if(button->getValue()){
                for (int i = 0; i < shapes.size(); i++) {
                    shapes[i].applySmoothing();
                }
            }
            
        }else if(name == "RESET SHAPES"){
            ofxUIButton *button = (ofxUIButton *) e.getButton();
            if(button->getValue()){
                    for (int i = 0; i < shapes.size(); i++) {
                    shapes[i].resetSmoothing();
                }
            }
            
        }else if(name == "ERASE SHAPES"){
//            ofxUIButton *button = (ofxUIButton *) e.getButton();
//            if(button->getValue()){
//                eraseShapes();
//            }
        }
        
    // COLOR -----------------------------------------------
    }else if(name == "RED"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightColor.r = slider->getScaledValue();
        light.setDiffuseColor(lightColor);
        cout << "changed red" << endl;
        
    }else if(name == "GREEN"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightColor.g = slider->getScaledValue();
        light.setDiffuseColor(lightColor);
        
    }else if(name == "BLUE"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightColor.b = slider->getScaledValue();
        light.setDiffuseColor(lightColor);
            
        
    
    // 3D -----------------------------------------------
    }else if(name == "THICKNESS"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        thickness = slider->getScaledValue();
        
    }else if(name == "DEPTH"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        zDepth = slider->getScaledValue();
        
    
        
    // PHYSICS -----------------------------------------
    }else if(name == "FORCE RADIUS"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        addForceRadius = slider->getScaledValue();
        
    }else if(name == "FORCE STRENGTH"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        addForceStrength = slider->getScaledValue();

        
    // OSCILLATION -----------------------------------------
    }else if(e.getName() == "OSCILLATE"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        isOscillating = toggle->getValue();
        if(selectedMode == "draw"){
            selectedMode = "camera";
            ((ofxUIRadio *)gui->getWidget("CURSOR MODE"))->activateToggle(selectedMode);
        }

    }else if(name == "AMPLITUDE"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        amplitude = slider->getScaledValue();
        
    }else if(name == "FREQUENCY"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        frequencyInSeconds = slider->getScaledValue();
        
    }else if(e.getName() == "LENGTH"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        nModifier = slider->getScaledValue();

        
    // VIDEO ------------------------------------------
    }else if(name == "PLAYBACK"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        playbackSlider = slider->getScaledValue();
        
    }else if(name == "TAKE SNAPSHOT"){
        ofxUIButton *button = (ofxUIButton *) e.getButton();
        if(button->getValue()){
            isSnapshoting = true;
        }
        
    }else if(name == "RECORD SEQUENCE"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        isRecording = toggle->getValue();
    }
        
//    // FULLSCREEN -----------------------------------------
//    }else if(e.getName() == "FULLSCREEN"){
//        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
//        ofSetFullscreen(toggle->getValue());
//    }
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
//    setCanvas(w, h);
//    cout << "resized" << endl;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
