//
//  treeGraph.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef treegraph_h
#define treegraph_h

#include "edge.h"

class TreeGraph {
public:
    TreeGraph();
    ~TreeGraph();
    std::vector<int> V();        // returns a vector of all vertices in the graph
    std::vector<Edge> E();          // returns a vector of all sorted edges in tree graph
    int w(Edge e);                  // returns the weight of edge (u,v)
    void addEdge(int u, int v, int w);
    int get_edge_count();
    void clear();
private:
    int edge_count;
};

#endif /* treegraph_h */
