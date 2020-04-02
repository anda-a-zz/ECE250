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
#include <vector>

class TreeGraph {
public:
    TreeGraph();
    ~TreeGraph();
    std::vector<int> V();        // returns a vector of all vertices in the graph
    std::vector<Edge> E();          // returns a vector of all sorted edges in tree graph
    int w(Edge e);                  // returns the weight of edge (u,v)
    void addEdge(int u, int v, double w);  // adds edge into connected_edges vector and
                                          // vertices to all_vertices vector
    int get_edge_count();
    void clear();
private:
    int edge_count;
    int max_vertices;
    int vertices_count;
    std::vector<LinkedList> connected_edges;
};

#endif /* treegraph_h */
