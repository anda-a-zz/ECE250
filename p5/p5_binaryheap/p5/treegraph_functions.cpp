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
    int searched2 = search(name2);
    if (searched == -1 || searched2 == -1)
        throw IllegalArgument();
        
    // initialization of vertices takes linear time
    for (int i = 0; i < vertices.size(); i++) {
        nodes[i].set_root(INFINITY);
        nodes[i].set_root_parent("");
    }
    
    // vector of all cities
    vector<Vertex> printed;
    
    nodes[searched].set_root(0);
    double distance = 0;
    Vertex minimum;
    
    // initialize priority queue
    PriorityQueue Q(V());
    
    while (!Q.is_empty()) {
        minimum = Q.extract_min();
        distance += minimum.get_distance();
        cout << minimum.get_city() << " ";
        if (minimum.get_city() == name2)
            break;
        int searched = search(minimum.get_city());
        
        vector<Edge> all_edges = nodes[searched].get_adjacent_vertices();
        Vertex u = nodes[searched].get_root();
        
        for (int i = 0; i < all_edges.size(); i++) {
            if (Q.search(all_edges[i].get_city2().get_city())) {
                int searched_v = search(all_edges[i].get_city2().get_city());
                Vertex v = nodes[searched_v].get_root();
                if (relax(u, v)) {
                    if (u.get_distance() == INFINITY){
                        nodes[searched_v].set_root(W(u.get_city(), v.get_city()));
                        cout << "true" << endl;
                    }else {
                        nodes[searched_v].set_root(u.get_distance() + W(u.get_city(), v.get_city()));
                        printed.push_back(u.get_city());
                    }
                        
                    nodes[searched_v].set_root_parent(u.get_city());
                }
                Q.modify_key(nodes[searched_v].get_root());
            }
        }
    }
    
    cout << endl;
    
    // print out all visited cities
    for (int i = 0; i < printed.size(); i++){
        if (i > printed.size()-1)
            cout << printed[i].get_city() << endl;
        else
            cout << printed[i].get_city() << " ";
    }
}

// returns shortest distance between cities
double TreeGraph::dijkstra_alg(string name1, string name2) {
    if (name1 == name2)
        throw IllegalArgument();
    
    int searched = search(name1);
    int searched2 = search(name2);
    if (searched == -1 || searched2 == -1)
        throw IllegalArgument();
        
    // initialization of vertices takes linear time
    for (int i = 0; i < vertices.size(); i++) {
        nodes[i].set_root(INFINITY);
        nodes[i].set_root_parent("");
    }
    
    nodes[searched].set_root(0);
    double distance = 0;
    Vertex minimum;
    
    // initialize priority queue
    PriorityQueue Q(V());
    
    while (!Q.is_empty()) {
        minimum = Q.extract_min();
       // distance += minimum.get_distance();
       // cout << "current distance is " << distance << endl;
        if (minimum.get_city() == name2)
            break;
        int searched = search(minimum.get_city());
        
        vector<Edge> all_edges = nodes[searched].get_adjacent_vertices();
        Vertex u = nodes[searched].get_root();
        
        for (int i = 0; i < all_edges.size(); i++) {
            int searched_v = search(all_edges[i].get_city2().get_city());
            Vertex v = nodes[searched_v].get_root();
            if (relax(u, v)) {
                if (u.get_distance() == INFINITY){
                    nodes[searched_v].set_root(W(u.get_city(), v.get_city()));
                    cout << "true" << endl;
                }else
                    nodes[searched_v].set_root(u.get_distance() + W(u.get_city(), v.get_city()));
                nodes[searched_v].set_root_parent(u.get_city());
            }
           // cout << "new distance " << nodes[searched].get_root().get_distance() << " " << nodes[searched_v].get_root().get_distance()<< endl;
            Q.modify_key(nodes[searched_v].get_root());
        }
    }
    
    return nodes[searched2].get_root().get_distance();
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
