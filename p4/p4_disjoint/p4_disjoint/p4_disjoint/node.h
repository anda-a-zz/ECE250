//
//  node.h
//  p2
//
//  Created by Anda Achimescu on 2020-02-11.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef node_h
#define node_h

#include "vertex.h"

class Node {
    friend class DisjointSet;
    friend class LinkedList;
public:
    Node();
    Node(int x);
    int get_key();
    Node *get_next();
    Node *get_prev();
    
private:
    int vertex_key;
    Node *next_node;
    Node *prev_node;
};

#endif /* node_h */
