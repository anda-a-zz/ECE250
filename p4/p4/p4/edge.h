//
//  vertexSet.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef edge_h
#define edge_h

class Edge {
    friend class TreeGraph;
    friend class LinkedList;
    friend class Node;
    friend bool sort_by_weight(const Edge& lhs, const Edge& rhs);
public:
    Edge();
    Edge(int u, int v, double w);
    double get_w();
    int get_u();
    int get_v();
private:
    int vertex_u;
    int vertex_v;
    double weight;
};

#endif /* edge_h */
