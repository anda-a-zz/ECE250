//
//  node.h
//  p2
//
//  Created by Anda Achimescu on 2020-02-11.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef node_h
#define node_h

#include "edge.h"

class Node {
    friend class LinkedList;
    friend class TreeGraph;
public:
    Node();
    Node(Edge x);
    int get_u_val();
    int get_v_val();
    double get_w();
    Edge get_edge();
    Node *get_next();
    Node *get_prev();
    
private:
    Edge u_v_w;
    Node *next_node;
    Node *prev_node;
};

#endif /* node_h */
