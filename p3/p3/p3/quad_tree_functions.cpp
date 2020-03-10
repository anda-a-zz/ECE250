//
//  quad_tree_functions.cpp
//  p3
//
//  Created by Anda Achimescu on 2020-03-09.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include "quad_tree.h"
#include "city_info.h"
#include "node.h"

using namespace std;

// Default Constructor
QuadTree::QuadTree() {
    
}

// Destructor
QuadTree::~QuadTree() {
    
}

void QuadTree::insert(QuadTree tree, CityInfo city_info) {
    // if tree size is 0, then (x,y) could not be found
    if (tree == NULL) {
        // set this equal to the root
        if (root == nullptr) {
            Node *new_node = new Node(num, caller);
            root = new_node;
            list_tail = new_node;
            list_head -> prev_node = nullptr;
            list_tail -> next_node = nullptr;
            
            new_node = nullptr;
            
        // otherwise, attach the new node to the end of another node
        } else {
            Node *new_node = new Node(city_info);
            new_node -> next_node = list_head;
            new_node -> prev_node = nullptr;
            list_head -> prev_node = new_node;
            list_head = new_node;
        }
        tree_size = tree_size + 1;
        cout << "success" << endl;
        return;
    }
    
    // found (x,y) and must return tree
    if ((tree == tree.x) && (tree == tree.y)) {
        cout << "failure" << endl;
        return;
    }
    if ((x <= tree.x) && (y < tree.y))
        return insert(tree.get(), city_info);
    else if ((x < tree.x) && (y >= tree.y))
        return insert(tree.NW(), x, y);
    else if ((x > tree.x) && (y <= tree.y))
        return insert(tree.SE(), x, y);
    else if ((x >= tree.x) && (y > tree.y))
        return insert(tree.NE(), x, y);
}

int QuadTree::search(QuadTree tree, double x, double y) {
    // if tree size is 0, then (x,y) could not be found
    if (tree.get_size() == 0)
        return -1;
    // found (x,y) and return tree
    if ((tree == tree.x) && (tree == tree.y))
        return tree;
    
    // recursion
    if ((x < tree.x) && (y < tree.y))
        return search(tree.SE, x, y);
    else if ((x < tree.x) && (y > tree.y))
        return search(tree.NE, x, y);
    else if ((x > tree.x) && (y < tree.y))
        return search(tree.SW, x, y);
    else if ((x > tree.x) && (y > tree.y))
        return search(tree.NW, x, y);
}

size_t QuadTree::get_size() {
    return tree_size;
}


