//
//  treegraph_functions.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
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
    // clear all vectors
    nodes.clear();
    vertices.clear();
    degree_of_vertices.clear();
    
    // shrink all vectors
    nodes.shrink_to_fit();
    vertices.shrink_to_fit();
    degree_of_vertices.shrink_to_fit();
    
    // set all other values to 0
    edge_count = 0;
    vertex_count = 0;
}

// returns a vector of all vertices in the graph
// updates the vertex count
std::vector<Vertex> TreeGraph::V() {
    std::vector<Vertex> all_vertices;
    for (int i = 0; i < vertex_count; i++) {
        all_vertices.push_back(nodes[i].get_root());
    }
    return all_vertices;
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
    nodes.push_back(EdgeSet(city)); // insert root
    degree_of_vertices.push_back(0); // insert degree = 0
    vertex_count++;
}

// set distance between edge
void TreeGraph::set_distance(string name1, string name2, double distance) {
    // if d is invalid (<=0), or both nodes are identical (name1=name2), error
    if (name1 == name2 || distance <= 0)
        throw IllegalArgument();
    
    int searched1 = search(name1);
    int searched2 = search(name2);
    
    // if 1 or both cities do not exist, error
    if (searched1 == -1 || searched2 == -1) {
        throw IllegalArgument();
    }
    
    if (searched1 <= searched2) {
        Edge e = Edge(vertices[searched1], vertices[searched2], distance);
        nodes[searched1].add_edge(e);
    } else {
        Edge e = Edge(vertices[searched2], vertices[searched1], distance);
        nodes[searched2].add_edge(e);
    }
    degree_of_vertices[searched1]++;
    degree_of_vertices[searched2]++;
   // cout << name2 << " index is " << searched2 << endl;
   // cout << "degree of " << name2 << " is " << degree_of_vertices[searched2] << endl;
    edge_count++;
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

// prints out shortest path
void TreeGraph::print(std::string name1, std::string name2) {
    if (name1 == name2)
        throw IllegalArgument();
    
    int searched = search(name1);
    if (searched == -1)
        throw IllegalArgument();
    
    std::vector<Vertex> all_vertices = V();
    Vertex s = all_vertices[searched];
    
    // initialization of vertices takes linear time
    for (int i = 0; i < all_vertices.size(); i++) {
        all_vertices[i].set_distance(INFINITY);
        all_vertices[i].set_parent("");
    }
    
    s.set_distance(0);
    Vertex minimum;
    
    // initialize priority queue
    PriorityQueue Q;
    Q.init(all_vertices);
    
    while (!Q.is_empty()) {
        minimum = Q.extract_min();
        cout << minimum.get_city() << " ";
        
        int searched = search(minimum.get_city());
        vector<Edge> all_edges = nodes[searched].get_adjacent_vertices();
        for (int i = 0; i < all_edges.size(); i++) {
            relax(minimum, all_edges[i].get_city2());
            Q.modify_key(all_edges[i].get_city2());
        }
    }
    cout << endl;
}

// returns shortest distance between cities
double TreeGraph::dijkstra_alg(string name1, string name2) {
    if (name1 == name2)
        throw IllegalArgument();
    
    int searched = search(name1);
    if (searched == -1)
        throw IllegalArgument();
        
    // initialization of vertices takes linear time
    for (int i = 0; i < vertices.size(); i++) {
        nodes[i].get_root().set_distance(INFINITY);
        nodes[i].get_root().set_parent("");
    }
    
    nodes[searched].get_root().set_distance(0);
    double distance = 0;
    Vertex minimum;
    
    // initialize priority queue
    PriorityQueue Q;
    Q.init(V());
    
    while (!Q.is_empty()) {
        minimum = Q.extract_min();
        cout << distance << endl;
        distance += minimum.get_distance();
        int searched = search(minimum.get_city());
        
        // fails right here
        vector<Edge> all_edges = nodes[searched].get_adjacent_vertices();
        
        for (int i = 0; i < all_edges.size(); i++) {
            Vertex u = all_edges[i].get_city1();
            Vertex v = all_edges[i].get_city2();
            if (relax(u, v)) {
                cout << W(u.get_city(), v.get_city()) << endl;
                if (u.get_distance() == INFINITY){
                    all_edges[i].get_city2().set_distance(W(u.get_city(), v.get_city()));
                    cout << "true" << endl;
                }else
                    all_edges[i].get_city2().set_distance(u.get_distance() + W(u.get_city(), v.get_city()));
                all_edges[i].get_city2().set_parent(u.get_city());
            }
            cout << "new distance " << all_edges[i].get_city1().get_distance() << " " << all_edges[i].get_city2().get_distance()<< endl;
            Q.modify_key(all_edges[i].get_city2());
        }
    }
    
    return distance;
}

// test if the shortest path to v can be improved by going through u
bool TreeGraph::relax(Vertex u, Vertex v) {
    if (u.get_distance() == INFINITY) {
        if (v.get_distance() > W(u.get_city(), v.get_city())) {
            return true;
        }
    }
    else {
        if (v.get_distance() > (u.get_distance() + W(u.get_city(), v.get_city()))) {
            return true;
        }
    }
    return false;
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
        vector<Edge> all_edges = nodes[searched1].get_adjacent_vertices();
        for (int i = 0; all_edges.size(); i++) {
            if (all_edges[i].get_city2().get_city() == u)
                return all_edges[i].get_distance();
        }
    } else {
        vector<Edge> all_edges = nodes[searched2].get_adjacent_vertices();
        for (int i = 0; all_edges.size(); i++) {
            if (all_edges[i].get_city2().get_city() == v)
            return all_edges[i].get_distance();
        }
    }

    return -1;
}
