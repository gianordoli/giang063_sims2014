//
//  VectorField.cpp
//  07_cl_01_vectorField
//
//  Created by Gabriel Gianordoli on 10/15/14.
//
//

#include "VectorField.h"

VectorField::VectorField(){

}

VectorField::~VectorField(){

}

void VectorField::setup(int _w, int _h, int _res){
    width = _w;
    height = _h;
    res = _res;
    
    int cols = width / res;
    int rows = height / res;
    for(int x = 0; x < cols; x++){
        vector<ofPoint> column;
        column.resize(rows);
        table.push_back(column);
        for(int y = 0; y < rows; y++){
            table[x][y] = ofPoint(ofRandom(-10, 10), ofRandom(-10, 10));
        }
    }
}

ofPoint VectorField::getForce(ofPoint _pos){
    _pos /= res;
    int x = ofClamp(int(_pos.x), 0, cols - 1);
    int y = ofClamp(int(_pos.y), 0, rows - 1);
    
    return table[x][y];
}

void VectorField::draw(){
    for(int x = 0; x < table.size(); x++){
        for(int y = 0; y < table[x].size(); y++){
            ofPushMatrix();
            ofTranslate(x*res, y*res);
            ofLine(ofPoint(0, 0), table[x][y]);
            ofPopMatrix();
        }
    }
}