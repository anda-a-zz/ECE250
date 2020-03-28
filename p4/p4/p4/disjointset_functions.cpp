//
//  disjointset_functions.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include "disjointset.h"

DisjointSet::DisjointSet() {
    set_head = nullptr;
    set_tail = nullptr;
}

DisjointSet::~DisjointSet() {
    clear();
}

// Clears the content of the LinkedList and will output success
void DisjointSet::clear(){
    Node *current_node = set_head;
    
    while (current_node != nullptr) {
        remove_node();
        current_node = current_node -> next_node;
    }
    
    current_node = nullptr;
    set_head = nullptr;
    set_tail = nullptr;
}

// Remove element from the front or back and will output success/failure
void DisjointSet::remove_node(){
    // check if LinkedList is empty
    if (set_head == nullptr && set_tail == nullptr) {
        return;
    }
    
    // delete the last node in the list
    Node *current_node = set_tail;
    set_tail = current_node -> prev_node;
    if (set_tail != set_head)
        set_tail -> next_node = nullptr;
    else
        set_head = nullptr;
    // remember to delete the node
    delete current_node;
}

string DisjointSet::make_set(Vertex x) {
    
}


string DisjointSet::find_set(Vertex x) {
    
}

void union_lists(Vertex x, Vertex y) {
    
}
