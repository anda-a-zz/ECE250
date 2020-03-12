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
    void max_min_total_value(Node *current_node, double x, double y, std::string d, std::string attr, std::string type); // the type will be the deciding factor on max/min/sum
    void max_min_total_find(Node *current_node, std::string attr, int &value, std::string type);
    void print(Node *current_node);
    void clear(Node *current_node);
    size_t get_size();
    Node *get_root();
    
private:
    Node *root;
    size_t tree_size;
};

#endif /* quad_tree_h */
