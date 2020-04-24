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
}

// clear all edges in graph
// clear std::vector<int> degree_of_vertices;
//       std::vector<LinkedList> connected_edges;
void TreeGraph::clear() {
    // clear all vectors
    nodes.clear();
    vertices.clear();

    // shrink all vectors
    nodes.shrink_to_fit();
    vertices.shrink_to_fit();
    
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
    
    // first check if it already exists in nodes[searched1]
    vector<Edge> adjacent = nodes[searched1].get_adjacent_vertices();
    int searched1_adj = nodes[searched1].search(name2);
    // if found, change the distance
    if (searched1_adj != -1) {
        nodes[searched1].change_distance(searched1_adj, distance);
        
        // change distance in searched2
        int searched2_adj = nodes[searched2].search(name1);
        nodes[searched2].change_distance(searched2_adj, distance);
    } else {
        // Add edges in both indices in order to be found in adjacent_vertices command
        Edge e = Edge(vertices[searched1], vertices[searched2], distance);
        nodes[searched1].add_edge(e);
        e = Edge(vertices[searched2], vertices[searched1], distance);
        nodes[searched2].add_edge(e);
        
        // add to edge counter
        edge_count++;
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
    return nodes[searched].get_adjacent_vertices().size();
}

// returns shortest distance between cities
double TreeGraph::dijkstra_alg(string name1, string name2, bool print) {
    if (name1 == name2)
        throw IllegalArgument();
    
    int searched = search(name1);
    int searched2 = search(name2);
    if (searched == -1 || searched2 == -1)
        throw IllegalArgument();
    
    // make a new EdgeSet for this algorithm
    vector<EdgeSet> new_nodes = nodes;
    
    // initialization of vertices takes linear time
    for (int i = 0; i < vertices.size(); i++) {
        new_nodes[i].set_root(INFINITY);
        new_nodes[i].set_root_parent("");
    }
    
    new_nodes[searched].set_root(0);
    Vertex minimum;
    
    // initialize priority queue
    PriorityQueue Q(V());
    Q.modify_key(new_nodes[searched].get_root());
    
    while (!Q.is_empty()) {
        minimum = Q.extract_min();
        
        if (minimum.get_city() == name2)
            break;
        int searched = search(minimum.get_city());
        
        vector<Edge> all_edges = new_nodes[searched].get_adjacent_vertices();
        Vertex u = new_nodes[searched].get_root();
        
        for (int i = 0; i < all_edges.size(); i++) {
            // only change the distance if the city exits in the PQ
            if (Q.search(all_edges[i].get_city2().get_city())) {
                int searched_v = search(all_edges[i].get_city2().get_city());
                if (searched_v != -1) {
                    Vertex v = new_nodes[searched_v].get_root();
                    if (relax(u, v)) {
                        new_nodes[searched_v].set_root(u.get_distance() + W(u.get_city(), v.get_city()));
                        new_nodes[searched_v].set_root_parent(u.get_city());
                    }
                    Q.modify_key(new_nodes[searched_v].get_root());
                }
            }
        }
    }
    
    if (new_nodes[searched2].get_root().get_distance()== INFINITY) {
        cout << "equals inf ";
        throw IllegalArgument();
    }

    
    // print out all cities
    if (print) {
        // use recursion to traverse through the nodes
        string printed = printer(searched2, name1, new_nodes);
        cout << printed << name2 << endl;
    }
        
    return new_nodes[searched2].get_root().get_distance();
}

string TreeGraph::printer(int index, string name1, vector<EdgeSet> new_nodes) {
    // if the parent node, then return the final node
    if (new_nodes[index].get_root().get_parent() == name1)
       return new_nodes[index].get_root().get_parent() + " ";
    // else, just recurse through in order to find the first parent
    else {
        string str = new_nodes[index].get_root().get_parent() + " ";
        index = search(new_nodes[index].get_root().get_parent());
        if (index == -1)
            throw IllegalArgument();
        return printer(index, name1, new_nodes) + str;
    }
}

// test if the shortest path to v can be improved by going through u
bool TreeGraph::relax(Vertex u, Vertex v) {
   if (v.get_distance() > (u.get_distance() + W(u.get_city(), v.get_city()))) {
        return true;
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
        for (int i = 0; i < all_edges.size(); i++) {
            if (all_edges[i].get_city2().get_city() == u)
                return all_edges[i].get_distance();
        }
    } else {
        vector<Edge> all_edges = nodes[searched2].get_adjacent_vertices();
        for (int i = 0; i < all_edges.size(); i++) {
            if (all_edges[i].get_city2().get_city() == v)
                return all_edges[i].get_distance();
        }
    }

    return -1;
}
