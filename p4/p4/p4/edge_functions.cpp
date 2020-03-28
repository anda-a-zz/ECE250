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
Edge::Edge(Vertex u, Vertex v, int weight){
    this.u = u;
    this.v = v;
    this.weight = weight;
}

int Edge::get_weight(){
    return this.weight;
}
