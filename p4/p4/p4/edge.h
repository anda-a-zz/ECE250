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
public:
    Edge(int u, int v, int w);
    int get_weight();
private:
    int vertex_u;
    int vertex_v;
    int weight;
};

#endif /* edge_h */
