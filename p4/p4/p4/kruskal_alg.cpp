//
//  mst.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-04-02.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

#include "edge.h"
#include "treegraph.h"

bool sort_by_weight(const Edge& lhs, const Edge& rhs);

using namespace std;

bool sort_by_weight(const Edge& lhs, const Edge& rhs) {
   return lhs.weight < rhs.weight;
}

double TreeGraph::kruskal_alg() {
    double weight = 0;
    DisjointSet S;              // initialize disjoint set S
    S.size(max_vertices);       // to be of size of the num of vertices in graph G
    
    // if graph is empty, return 0 weight
    if (edge_count == 0)
        return 0;
    
    // for each vertex in G, make a set in S
    vector<int> vertices = V();
    
    // if the number of vertices in the graph is less than the max, return with 0 weight
    if (max_vertices != vertex_count)
        return 0;
    
    for (int i = 0; i < max_vertices; i++) {
        // make sure valid entry
        if (vertices[i] >= 0)
            S.make_set(vertices[i]);
    }
    
    // sort the edges of G in increasing order
    vector<Edge> edges = E();
    
    // check if graph is connected
    // if the graph is not connected, return 0 weight
    if (max_vertices == vertex_count)
    if (!is_connected(edges)) {
        return 0;
    }
 
    sort(edges.begin(), edges.end(), sort_by_weight);

    // for each sorted edge in G...
    for (int i = 0; i < edge_count; i++) {
        // if in different sets, then add the edge to the tree
        if (S.find_set(edges[i].get_u()) != S.find_set(edges[i].get_v())){
            weight += edges[i].get_w();
            S.union_sets(edges[i].get_u(), edges[i].get_v());
        }
    }
    
    return weight;
}

//checks if the graph is currently connected
bool TreeGraph::is_connected(vector<Edge> edges) {
    bool connected = true;
    // initialize vector with all 0s
    vector<bool> vertices (max_vertices, false);
    
    // for the first edge, initialize it into the vertices vector
    vertices[edges[0].get_u()] = true;
    vertices[edges[0].get_v()] = true;
    
    // traverse through the graph
    // the vector edges is currently sorted by the u and v values
    // if the next u OR v values are not stored as true, then the graph is NOT connected
    int u_val = 0;
    int v_val = 0;
    for (int i = 1; i < edges.size(); i++){
        u_val = edges[i].get_u();
        v_val = edges[i].get_v();
        if (vertices[u_val] == true){
            vertices[v_val] = true;
        // otherwise, go through all v values for the u values to see if connected to vertice
        } else if (vertices[v_val] == true) {
            vertices[u_val] = true;
        } else {
            int counter = 1;
            while (counter < edges.size()) {
                v_val = edges[i+counter].get_v();
                if (u_val == edges[i+counter].get_u()) {
                    if (vertices[v_val] == true) {
                        vertices[u_val] = true;
                        break;
                    }
                } else {
                    connected = false;
                    break;
                }
                counter++;
            }
            if (connected == false)
                break;
            else {
                i--;
            }
        }
    }
    
    // check if all vertices are in edges
    if (find(vertices.begin(), vertices.end(), false) != vertices.end())
        return false;
    else
        return connected;
        
}
