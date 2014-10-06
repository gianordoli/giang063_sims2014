//
//  Ribbon.h
//  06_midterm
//
//  Created by Gabriel Gianordoli on 10/5/14.
//
//

#pragma once
#include "ofMain.h"

class Ribbon{
public:
    void setup(float _x, float _y);
    void update(int _shapeSmoothing);
    void draw(bool _useCamera);
    void addPoint(float _x, float _y);
    
    ofPolyline line;
    float depthInterval;
};