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
#include "illegal_argument.h"

using namespace std;

// Constructor initializes the Graph
TreeGraph::TreeGraph() {
    edge_count = 0;
    vertex_count = 0;
}

// destructor calls clear function to remove all edges
TreeGraph::~TreeGraph(){
    clear();
    // clear and shrink the vector
    degree_of_vertices.clear();
    degree_of_vertices.shrink_to_fit();
}

// clear all edges in graph
// clear std::vector<int> degree_of_vertices;
//       std::vector<LinkedList> connected_edges;
void TreeGraph::clear() {
    // clear all linked lists
    for (int i = 0; i < vertex_count; i++) {
        degree_of_vertices[i] = 0;
    }
    vertices.clear();
    // set all other values to 0
    edge_count = 0;
    vertex_count = 0;
}

// returns a vector of all vertices in the graph
// updates the vertex count
std::vector<Vertex> TreeGraph::V() {
    return vertices;
}

// returns the index of the city in the graph
int TreeGraph::search(string city) {
    for (int i = 0; i < vertex_count; i++) {
        // if found city, return index
        if (vertices[i].get_city() == city)
            return i;
    }
    return -1;
}

// add city into graph
void TreeGraph::insert_city(string city) {
    if (search(city) != -1)
        throw IllegalArgument();
    
    // if not found, insert node
    vertices.push_back(city);
    vertex_count++;
}

// set distance between edge
void TreeGraph::set_distance(string name1, string name2, double distance) {
    // if d is invalid (<=0), or both nodes are identical (name1=name2), error
    if (name1 == name2 || distance <= 0)
        throw IllegalArgument();
    
    int searched1 = search(name1);
    int searched2 = search(name1);
    
    // if 1 or both cities do not exist, error
    if (searched1 == -1 || searched2 == -1) {
        throw IllegalArgument();
    }
    
    if (searched1 <= searched2) {
        Edge e(name2, distance, vertices[searched2].get_distance());
        vertices[searched1].add_edge(e);
    } else {
        Edge e(name1, distance, vertices[searched1].get_distance());
        vertices[searched2].add_edge(e);
    }
}

// get edge count
int TreeGraph::graph_edges() {
    return edge_count;
}

int TreeGraph::graph_nodes() {
    return vertex_count;
}

// return degree of the city node
int TreeGraph::degree(string city) {
    int searched = search(city);
    if (searched == -1)
        throw IllegalArgument();
    return degree_of_vertices[searched];
}


void TreeGraph::print() {
    
}

// returns shortest distance between cities
double TreeGraph::dijkstra_alg(string name1, string name2) {
    int searched = search(name1);
    if (searched == -1)
        throw IllegalArgument();
    
    std::vector<Vertex> all_vertices = V();
    Vertex s = all_vertices[searched];
    
    // initialization of vertices takes linear time
    for (int i = 0; i < all_vertices.size(); i++) {
        all_vertices[i].set_distance(-1);
        all_vertices[i].set_parent(nullptr);
    }
    
    s.set_distance(0);
    double distance = 0;
    Vertex minimum;
    
    // initialize priority queue
    PriorityQueue Q;
    Q.init(all_vertices);
    
    while (!Q.is_empty()) {
        minimum = Q.extract_min();
        distance += minimum.get_distance();
        vector<Edge> all_edges = minimum.adjacent();
        for (int i = 0; i < all_edges.size(); i++) {
            relax(all_edges[i].get_vertex(), minimum);
            Q.modify_key(all_edges[i].get_vertex());
        }
    }
    
    return distance;
}

// test if the shortest path to v can be improved by going through u
void TreeGraph::relax(Vertex v, Vertex u) {
    if (v.get_distance() > u.get_distance() + W(u.get_city(), v.get_city())) {
        v.set_distance(u.get_distance() + W(u.get_city(), v.get_city()));
        Vertex *parent = &u;
        v.set_parent(parent);
    }
}

// returns the distance between the edge
double TreeGraph::W(string v, string u) {
    int searched1 = search(v);
    int searched2 = search(u);
    
    // if 1 or both cities do not exist, error
    if (searched1 == -1 || searched2 == -1) {
        throw IllegalArgument();
    }
    
    if (searched1 <= searched2) {
        vector<Edge> all_edges = vertices[searched1].adjacent();
        for (int i = 0; all_edges.size(); i++) {
            if (all_edges[i].get_city_name() == u)
                return all_edges[i].get_distance();
        }
    } else {
        vector<Edge> all_edges = vertices[searched2].adjacent();
        for (int i = 0; all_edges.size(); i++) {
            if (all_edges[i].get_city_name() == v)
                return all_edges[i].get_distance();
        }
    }

    return -1;
}
