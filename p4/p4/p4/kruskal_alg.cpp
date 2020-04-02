//
//  mst.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-04-02.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool sort_by_weight(Edge &lhs, Edge &rhs) {
    return lhs.get_weight() < rhs.get_weight();
}

TreeGraph kruskal_alg(TreeGraph G) {
    TreeGraph A;                // initialize MST A
    DisjointSet S;              // initialize disjoint set S
    S.size(G.get_max_vertices());     // to be of size of the num of vertices in graph G
    
    // for each vertex in G, make a set in S
    vector<int> vertices = G.V();
    for (int i = 0; i < G.get_max_vertices(); i++) {
        S.make_set(vertices[i]);
    }
    
    // sort the edges of G in increasing order
    vector<Edge> edges = G.E();
    sort(edges.begin(), edges.end(), sort_by_weight);
    
    // for each sorted edge in G...
    for (int i = 0; i < G.get_edge_count(); i++) {
        // if in different sets, then add the edge to the tree
        if (S.find_set(edges[i].get_u()) != S.find_set(edges[i].get_v())){
            A.add_edge(edges[i].get_u(), edges[i].get_v(), edges[i].get_weight());
            S.union_sets(edges[i].get_u(), edges[i].get_v());
        }
    }
    
    return A;
}
