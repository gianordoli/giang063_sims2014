//
//  VectorField.h
//  07_cl_01_vectorField
//
//  Created by Gabriel Gianordoli on 10/15/14.
//
//

#pragma once
#include "ofMain.h"

class VectorField{
public:
    VectorField();
    virtual ~VectorField();
    
    void setup(int _w, int _h, int _res);
    ofPoint getForce(ofPoint _pos);
    void draw();
    
    vector< vector<ofPoint> > table;
    
    int width, height, res;
    int cols, rows;
};