//
//  treeGraph.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
// https://www.techiedelight.com/kruskals-algorithm-for-finding-minimum-spanning-tree/

#ifndef treegraph_h
#define treegraph_h

#include "edge.h"
#include "linkedlist.h"
#include <vector>

class TreeGraph {
public:
    TreeGraph();
    ~TreeGraph();
    std::vector<int> V();        // returns a vector of all vertices in the graph
    std::vector<Edge> E();          // returns a vector of all sorted edges in tree graph
   // int W(Edge e);                  // returns the weight of edge (u,v)
    int get_edge_count();
    int get_max_vertices();
    double get_total_weight();
    int degree(int u);
    void size(int n);
    void clear();
    void add_edge(int u, int v, double w);  // adds edge into connected_edges vector and
                                          // vertices to all_vertices vector
    void delete_edge(int u, int v);
    void print();
private:
    int edge_count;
    int max_vertices;
    double total_weight;
    std::vector<int> degree_of_vertices;
    std::vector<LinkedList> connected_edges;
};

#endif /* treegraph_h */
