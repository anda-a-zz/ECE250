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
    
    set_size = 0;
}

DisjointSet::~DisjointSet() {
    clear();
}

// Clears the content of the LinkedList and will output success
void DisjointSet::clear(){
    for (int i = 0; i < max_size; i++) {
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
    Vertex extra(-1);
    for(int i = 0; i < n; ++i){
        disjoint_lists[i] = LinkedList();
    }
}


Node * DisjointSet::make_set(Vertex x) {
    disjoint_lists[x.key()].insert_node(x);
    set_size = set_size + 1;
    return disjoint_lists[x.key()].list_head;
}


// if vertex = vector[vertex] then found!
// else, vector[vector[vertex]] (go to the next value inside)
// should be constant time
Node * DisjointSet::find_set(Vertex x) {
    if (disjoint_lists[x.key()].get_parent_key() == x.key()) {
        return disjoint_lists[x.key()].list_head;
    } else {
        return disjoint_lists[disjoint_lists[x.key()].get_parent_key()].list_head;
    }
}

void union_lists(Vertex x, Vertex y) {
    
}
