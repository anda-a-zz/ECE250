//
//  treeGraph.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef treeGraph_h
#define treeGraph_h

class treeGraph {
public:
    VertexSet V();
    EdgeSet E();
    int w(Vertex u, Vertex v);      // returns the weight of (u,v)
private:
}

#endif /* treeGraph_h */
