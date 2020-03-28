//
//  treegraph_functions.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include <vector>
#include "treegraph.h"
#include "vertex.h"
#include "edge.h"

using namespace std;

// Constructor initializes the Graph
TreeGraph::TreeGraph() {
    edge_count = 0;
}
TreeGraph::~TreeGraph(){
    clear();
    edge_count = 0;
}

void TreeGraph::clear() {
    
}

// returns a vector of all vertices in the graph
std::vector<Vertex> TreeGraph::V() {
    
}

// returns a vector of all sorted edges in tree graph
vector<Edge> TreeGraph::E() {
    Vertex u(1);
    Vertex v(2);
    Edge e(u, v, 3);
    vector<Edge> vec = {e};
    return vec;
}

// add edge into graph
void addEdge(Vertex u, Vertex v, int w) {
    // intialize an edge
    Edge e(u, v, w);
}

// returns the weight of the edge (u,v)
int w(Edge e){
    return e.get_weight();
}

int TreeGraph::get_edge_count() {
    return edge_count;
}


