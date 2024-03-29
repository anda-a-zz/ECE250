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
Node::Node() : u_v_w() {
    next_node = nullptr;
    prev_node = nullptr;
}

// Constructor will initialize the Node
Node::Node(Edge x) {
    u_v_w = x;
    next_node = nullptr;
    prev_node = nullptr;
}

// get the u vertex value
int Node::get_u_val() {
    return u_v_w.vertex_u;
}

// get the v vertex value
int Node::get_v_val() {
    return u_v_w.vertex_v;
}

// get the weight between the vertices
double Node::get_w() {
    return u_v_w.weight;
}

// return the edge stored
Edge Node::get_edge() {
    return u_v_w;
}

// Get the next node
Node *Node::get_next() {
    return next_node;
}

// Get the previous node
Node *Node::get_prev() {
    return prev_node;
}

// update the weight of the edge
void Node::update_w(double w) {
    u_v_w.update_w(w);
}
