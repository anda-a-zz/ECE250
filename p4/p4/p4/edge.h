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
public:
    Edge(int u, int v, double w);
    int get_weight();
private:
    int vertex_u;
    int vertex_v;
    double weight;
};

#endif /* edge_h */
