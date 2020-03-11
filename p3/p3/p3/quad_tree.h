//
//  QuadTree.h
//  p3
//
//  Created by Anda Achimescu on 2020-03-04.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef quad_tree_h
#define quad_tree_h

#include "node.h"

class QuadTree {
public:
    QuadTree();
    ~QuadTree();
    void insert(Node *current_node, CityInfo city);
    bool search(Node *current_node, double x, double y);
    void max_value();
    void min_value();
    void total();
    void print(Node *current_node);
    void clear();
    size_t get_size();
    Node *get_root();
    
private:
    Node *root;
    size_t tree_size;
};

#endif /* quad_tree_h */
