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
#include "edge.h"

using namespace std;

// Constructor initializes the Graph
TreeGraph::TreeGraph() {
    edge_count = 0;
    total_weight = 0;
}
TreeGraph::~TreeGraph(){
    clear();
}

// clear std::vector<int> degree_of_vertices;
//       std::vector<LinkedList> connected_edges;
void TreeGraph::clear() {
    for (int i = 0; i < max_vertices; i++) {
        connected_edges[i].clear();
    }
    connected_edges.clear();
    connected_edges.shrink_to_fit();
    degree_of_vertices.clear();
    degree_of_vertices.shrink_to_fit();
    max_vertices = 0;
    edge_count = 0;
    total_weight = 0;
}

// size  std::vector<int> degree_of_vertices;
//       std::vector<LinkedList> connected_edges;
void TreeGraph::size(int n) {
    connected_edges.resize(n);
    degree_of_vertices.resize(n);
    max_vertices = n;
    for(int i = 0; i < max_vertices; i++){
        connected_edges[i] = LinkedList();
    }
}

// returns a vector of all vertices in the graph
std::vector<int> TreeGraph::V() {
    std::vector<int> all_vertices;
    for (int i = 0; i < max_vertices; i++) {
        if (connected_edges[i].list_size > 0)
            all_vertices.push_back(i);
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
    // intialize an edge
    if (u > v) {
        swap(u, v);
    }
    Edge x(u, v, w);
    connected_edges[u].insert_node(x);
    degree_of_vertices[u] += 1;
    degree_of_vertices[v] += 1;
    edge_count += 1;
    total_weight += w;
}

void TreeGraph::delete_edge(int u, int v) {
    // intialize an edge
    if (u > v) {
        swap(u, v);
    }
    total_weight -= connected_edges[u].get_node_weight(v);
    connected_edges[u].remove_node(v);
    degree_of_vertices[u] -= 1;
    degree_of_vertices[v] -= 1;
    edge_count -= 1;
}

// returns the weight of the edge (u,v)
int TreeGraph::W(Edge e){
    return e.get_weight();
}

int TreeGraph::get_edge_count() {
    return edge_count;
}

int TreeGraph::get_max_vertices() {
    return max_vertices;
}

int TreeGraph::degree(int u) {
    return degree_of_vertices[u];
}

double TreeGraph::get_total_weight() {
    return total_weight;
}



