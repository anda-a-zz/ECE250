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
Vertex::Vertex(){
    key_value = -1;
    parent = -1;
}

Vertex::Vertex(int key){
    key_value = key;
    parent = key;
}

int Vertex::get_key() {
    return key_value;
}

int Vertex::get_parent() {
    return parent;
}

void Vertex::set_key(int k) {
    key_value = k;
}

void Vertex::set_parent(int p) {
    parent = p;
}
