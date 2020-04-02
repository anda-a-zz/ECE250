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

// Constructor initializes the Edge
Edge::Edge(){
    vertex_u = -1;
    vertex_v = -1;
    weight = -1;
}

Edge::Edge(int u, int v, int w){
    vertex_u = u;
    vertex_v = v;
    weight = w;
}

int Edge::get_weight(){
    return weight;
}

int Edge::get_u() {
    return vertex_u;
}

int Edge::get_v() {
    return vertex_v;
}
