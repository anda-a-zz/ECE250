//
//  nodal_functions.cpp
//  p2
//
//  Created by Anda Achimescu on 2020-02-11.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include "node.h"

// Default Constructor
Node::Node() {
    vertex_key = -1;
    next_node = nullptr;
    prev_node = nullptr;
}

// Constructor will initialize the Node
Node::Node(int x){
    vertex_key = x;
    next_node = nullptr;
    prev_node = nullptr;
}

int Node::get_key() {
    return vertex_key;
}

// Get the next node
Node *Node::get_next() {
    return next_node;
}

// Get the previous node
Node *Node::get_prev() {
    return prev_node;
}
