//
//  vertex_functions.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include "vertex.h"

using namespace std;

// Constructor initializes the Vertex
Vertex::Vertex(int key){
    key_value = key;
}

std::vector<Vertex> Vertex::adjacent() {
    
}

int Vertex::key() {
    return key_value;
}

void Vertex::setKey(int k) {
    key_value = key;
}

Vertex Vertex::parent() {
    
}

void Vertex::setParent(Vertex p) {
    
}
