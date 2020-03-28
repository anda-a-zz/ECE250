//
//  treeGraph.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef treeGraph_h
#define treeGraph_h

class TreeGraph {
public:
    TreeGraph();
    ~TreeGraph();
    std::vector<Vertex> V();        // returns a vector of all vertices in the graph
    std::vector<Edge> E();          // returns a vector of all sorted edges in tree graph
    int w(Vertex u, Vertex v);      // returns the weight of (u,v)
    int get_edge_count();
private:
    int edge_count;
}

#endif /* treeGraph_h */
