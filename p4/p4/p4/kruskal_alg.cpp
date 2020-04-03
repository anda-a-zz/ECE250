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

bool is_connected(vector<Edge> edges, int size);
bool sort_by_weight(const Edge& lhs, const Edge& rhs);
TreeGraph kruskal_alg(TreeGraph G);

using namespace std;

bool sort_by_weight(const Edge& lhs, const Edge& rhs) {
   return lhs.weight < rhs.weight;
}

TreeGraph kruskal_alg(TreeGraph G) {
    TreeGraph A;                // initialize MST A
    DisjointSet S;              // initialize disjoint set S
    int max_vertices = G.get_max_vertices();
    int edge_count = G.get_edge_count();
    S.size(max_vertices);     // to be of size of the num of vertices in graph G
    A.size(max_vertices);
    
    // for each vertex in G, make a set in S
    vector<int> vertices = G.V();
//    cout << "just made a vector of all vertices" << endl;
//    for (int i = 0; i < max_vertices; i++) {
//        cout << vertices[i] << " ";
//    }
    
    for (int i = 0; i < G.get_max_vertices(); i++) {
        S.make_set(vertices[i]);
    }
//    cout << endl << "just made all sets" << endl;
    
    // sort the edges of G in increasing order
    vector<Edge> edges = G.E();
    
    // check if graph is connected
    if (!is_connected(edges, max_vertices)) {
        return A;
    }
    
//    cout << "just made a vector of all edges" << endl;
//    for (int i = 0; i < edge_count; i++) {
//        cout << "{" << edges[i].get_u() << "," << edges[i].get_v() << "," << edges[i].get_w() << "}, ";
//    }
    
    sort(edges.begin(), edges.end(), sort_by_weight);
//    cout << endl << "just sorted through all edges by weight" << endl;
//    for (int i = 0; i < edge_count; i++) {
//        cout << "{" << edges[i].get_u() << "," << edges[i].get_v() << "," << edges[i].get_w() << "}, ";
//    }
//    cout << endl;
    
    // for each sorted edge in G...
    for (int i = 0; i < edge_count; i++) {
        // if in different sets, then add the edge to the tree
       // cout << "edge " << i << " is " << edges[i].get_u() << ", " << edges[i].get_v() << " ";
       // cout << "find set of u " << S.find_set(edges[i].get_u()) << ", ";
       // cout << "find set of v " << S.find_set(edges[i].get_v()) << endl;
       // S.print();
        if (S.find_set(edges[i].get_u()) != S.find_set(edges[i].get_v())){
            A.add_edge(edges[i].get_u(), edges[i].get_v(), edges[i].get_w());
            S.union_sets(edges[i].get_u(), edges[i].get_v());
        }
       // cout << endl;
    }
    
    return A;
}

bool is_connected(vector<Edge> edges, int size) {
    bool connected = true;
    // initialize vector with all 0s
    vector<bool> vertices (size, false);
    
    // for the first edge, initialize it into the vertices vector
    vertices[edges[0].get_u()] = true;
    vertices[edges[0].get_v()] = true;
    
    // traverse through the graph
    // the vector edges is currently sorted by the u and v values
    // if the next u OR v values are not stored as true, then the graph is NOT connected
    for (int i = 1; i < edges.size(); i++){
        if (vertices[edges[i].get_u()] == true || vertices[edges[i].get_v()] == true){
            vertices[edges[i].get_u()] = true;
            vertices[edges[i].get_v()] = true;
        } else {
            connected = false;
            break;
        }
    }
    
    return connected;
}
