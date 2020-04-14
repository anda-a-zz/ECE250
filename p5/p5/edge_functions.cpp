//
//  edge_functions.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include "edge.h"

using namespace std;

// Constructor initializes the Edge by setting everything to -1
Edge::Edge(){
    vertex_u = -1;
    vertex_v = -1;
    weight = -1;
}

// initialize the edge by setting the key values and the weight
Edge::Edge(int u, int v, double w){
    vertex_u = u;
    vertex_v = v;
    weight = w;
}

// get the weight
double Edge::get_w(){
    return weight;
}

// get the u key value
int Edge::get_u() {
    return vertex_u;
}

// get the v key value
int Edge::get_v() {
    return vertex_v;
}

// update the weight
void Edge::update_w(double w) {
    weight = w;
}
