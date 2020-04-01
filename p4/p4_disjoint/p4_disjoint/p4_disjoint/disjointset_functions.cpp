//
//  disjointset_functions.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include "disjointset.h"

using namespace std;

DisjointSet::DisjointSet() {
    max_size = 0;
    set_size = 0;
}

DisjointSet::~DisjointSet() {
    clear();
    max_size = 0;
    set_size = 0;
}

// Clears the content of the LinkedList and will output success
void DisjointSet::clear(){
    for (int i = 0; i < max_size; i++) {
        cout << "vector place " << i << endl;
        disjoint_lists[i].clear();
    }
    disjoint_lists.clear();
    disjoint_lists.shrink_to_fit();
    
    max_size = 0;
    set_size = 0;
}

void DisjointSet::size(int n) {
    disjoint_lists.resize(n);
    max_size = n;
    for(int i = 0; i < n; ++i){
        disjoint_lists[i] = LinkedList();
    }
}


int DisjointSet::make_set(int x) {
    disjoint_lists[x].insert_node(x);
    set_size = set_size + 1;
    return x;
}

// if vertex = vector[vertex] then found!
// else, vector[vector[vertex]] (go to the next value inside)
// should be constant time
int DisjointSet::find_set(int x) {
    if (disjoint_lists[x].get_parent_key() == x) {
        return disjoint_lists[x].get_parent_key();
    } else {
        return disjoint_lists[disjoint_lists[x].get_parent_key()].get_parent_key();
    }
}

void DisjointSet::union_lists(int x, int y) {
    int x_placement = find_set(x);
    int y_placement = find_set(y);
    if (disjoint_lists[x_placement].get_size() >= disjoint_lists[y_placement].get_size()) {
    
        // Step 1: Add list Y to list X
        // a) make new node be the head of the smaller list
        Node *head_node = disjoint_lists[y_placement].list_head;
        Node *tail_node = disjoint_lists[y_placement].list_tail;
        
       
        // b) make the previous node now be the initial tail of the larger list
        head_node -> prev_node = disjoint_lists[x_placement].list_tail;
        // c) make the next node of the intial tail be the new node
        disjoint_lists[x_placement].list_tail -> next_node = head_node;
        // d) set the new tail to be list Y tail
        disjoint_lists[x_placement].list_tail = tail_node;

        // Step 2: Make original list Y back to cleared
        disjoint_lists[y_placement].clear();
        // b) reinitialize it to have the new node of the current parent of the index
        disjoint_lists[y_placement].insert_node(x);
    }
}

void DisjointSet::print() {
    for (int i = 0; i < max_size; i++) {
        disjoint_lists[i].print();
    }
}
