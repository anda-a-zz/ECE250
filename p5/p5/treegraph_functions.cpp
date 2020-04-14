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
    max_vertices = 0;
}

// destructor calls clear function to remove all edges
TreeGraph::~TreeGraph(){
    clear();
    // clear and shrink the 2 vectors
    connected_edges.clear();
    connected_edges.shrink_to_fit();
    degree_of_vertices.clear();
    degree_of_vertices.shrink_to_fit();
    max_vertices = 0;
}

// clear all edges in graph
// clear std::vector<int> degree_of_vertices;
//       std::vector<LinkedList> connected_edges;
void TreeGraph::clear() {
    // clear all linked lists
    for (int i = 0; i < max_vertices; i++) {
        connected_edges[i].clear();
        degree_of_vertices[i] = 0;
    }
    
    // set all other values to 0 except max_vertices
    edge_count = 0;
    vertex_count = 0;
}

// initialize size of graph
// size  std::vector<int> degree_of_vertices;
//       std::vector<LinkedList> connected_edges;
void TreeGraph::size(int n) {
    if (n <= 0)
        throw IllegalArgument();
    
    connected_edges.resize(n);
    degree_of_vertices.resize(n);
    max_vertices = n;
    for(int i = 0; i < max_vertices; i++){
        connected_edges[i] = LinkedList();
        degree_of_vertices[i] = 0;
    }
}

// returns a vector of all vertices in the graph
// updates the vertex count
std::vector<int> TreeGraph::V() {
    std::vector<int> all_vertices;
    all_vertices.resize(max_vertices);
    vertex_count = 0;
    
    for (int i = 0; i < max_vertices; i++) {
        // if the degree is 0, then there is no vertex of that value in the 
        if (degree_of_vertices[i] > 0) {
            all_vertices[i] = i;
            vertex_count++;
        }
        else
            all_vertices[i] = -1;
    }
    return all_vertices;
}

// returns a vector of all sorted edges in tree graph
vector<Edge> TreeGraph::E() {
    std::vector<Edge> all_edges;
    for (int i = 0; i < max_vertices; i++) {
        if (connected_edges[i].list_size > 0) {
            Node *current_node = connected_edges[i].list_head;
            
            while (current_node != nullptr) {
                all_edges.push_back(current_node -> get_edge());
                current_node = current_node -> next_node;
            }
        }
    }
    return all_edges;
}

// add edge into graph
void TreeGraph::add_edge(int u, int v, double w) {
    if (u < 0 || v < 0 || u >= max_vertices || v >= max_vertices || w <= 0 || u == v)
        throw IllegalArgument();
    
    // swap u and v if u > v
    if (u > v) {
        swap(u, v);
    }
    
    // search if edge is currently in linked list
    // if not found, insert node
    int index = connected_edges[u].search(v, "search");
    if (index == -1) {
        Edge x(u, v, w);
        connected_edges[u].insert_node(x);
        degree_of_vertices[u] += 1;
        degree_of_vertices[v] += 1;
        edge_count += 1;
    
    // otherwise, if found, just update the weight
    } else {
        connected_edges[u].update_node_w(index, w);
    }
}

// delete edge in graph
bool TreeGraph::delete_edge(int u, int v) {
    if (u < 0 || v < 0 || u >= max_vertices || v >= max_vertices || u == v)
        throw IllegalArgument();
    
    // swap u and v if u > v
    if (u > v) {
        swap(u, v);
    }
    // search if edge is currently in graph
    int index = connected_edges[u].search(v, "remove");
    
    // if remove_node could not be found, throw an illegal argument;
    if (index == -1) {
        return false;
    } else {
        connected_edges[u].remove_node(index);
        degree_of_vertices[u] -= 1;
        degree_of_vertices[v] -= 1;
        edge_count -= 1;
        return true;
    }
}

// return edge count
int TreeGraph::get_edge_count() {
    return edge_count;
}

// return max num of vertices
int TreeGraph::get_max_vertices() {
    return max_vertices;
}

// return degree of u
int TreeGraph::degree(int u) {
    if (u < 0 || u >= max_vertices)
        throw IllegalArgument();
    return degree_of_vertices[u];
}

// used for debugging purposes
void TreeGraph::print() {
    for (int i = 0; i < max_vertices; i++) {
        connected_edges[i].print();
    }
}
