//
//  edgeset.hpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-16.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef edgeset_h
#define edgeset_h

#include <stdio.h>


// a class for all adjacent vertices for the root vertex
class EdgeSet {
public:
    EdgeSet();
    EdgeSet(Vertex set_root);
    ~EdgeSet();
    void add_edge(Edge e);
    Vertex get_root();
    vector<Edge> get_adjacent_vertices();
    
private:
    Vertex root;
    vector<Edge> adjacent_vertices;
};

#endif /* edgeset_h */
