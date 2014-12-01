//
//  Ribbon.h
//  06_midterm
//
//  Created by Gabriel Gianordoli on 10/5/14.
//
//  Ribbon mesh code adapted from:
//  oF > examples > 3d > cameraRibbonExample, by James George
//
//

#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "Spring.h"

class Ribbon{
public:
    void setup(float _x, float _y);
    void updatePhysics(string _selectedMode, ofPoint _mousePos, float _radius, float _strength);
    void updateOscillation(float _amplitude, int _frequencyInSeconds, int _nModifier);
    void draw(string _selectedMode, float _nVertices, float _thickness, float _zDepth);

    // Drawing
    void addPoint(float _x, float _y);
    void applySmoothing(int _shapeSmoothing);
    void resetSmoothing();

    // Particles and Springs
    void eraseParticles();
    void createParticles();
    void eraseSprings();
    void connectSprings();
    
    
    // ofPolyline is actually ONE line
    // It would be the same as a vector of ofPoint.
    // But it has some special properties, like the smoothing feature
    ofPolyline originalLine;    // this is the original line drawing
    ofPolyline currentLine;     // this is the smoothed line drawing
                                // We always draw the CURRENT line
                                // but we keep the original as an option to reset
    
    // each vertex from our polyLine will respond to physics
    vector<Particle> myParticles;
    vector<Spring> springList;
};