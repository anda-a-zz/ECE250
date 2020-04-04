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
    sort(edges.begin(), edges.end(), sort_by_weight);
    
    // for each sorted edge in G...
    for (int i = 0; i < edges.size(); i++) {
        // if in different sets, then add the edge to the tree
        if (S.find_set(edges[i].get_u()) != S.find_set(edges[i].get_v())){
            weight += edges[i].get_w();
            S.union_sets(edges[i].get_u(), edges[i].get_v());
        }
    }
    
    // check for connectivity
    // update all parents
    int parent = S.parent[0];
    for (int i = 1; i < S.max_size; i++) {
        if (S.find_set(i) != parent) {
            return 0;
        }
    }
    
    return weight;
}
