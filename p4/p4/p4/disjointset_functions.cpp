//
//  disjointset_functions.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include <vector>
#include "disjointset.h"

using namespace std;

// constructor intializes max size of disjoint set to 0
DisjointSet::DisjointSet() {
    max_size = 0;
}

// deconstructor clears everything in vectors
DisjointSet::~DisjointSet() {
    rank.clear();
    rank.shrink_to_fit();
    parent.clear();
    parent.shrink_to_fit();
    max_size = 0;
}

// this function sizes the vectors in the disjoint sets and initializes them to -1 values
void DisjointSet::size(int n) {
    rank.resize(n);
    parent.resize(n);
    max_size = n;
    for(int i = 0; i < n; ++i){
        rank[i] = -1;
        parent[i] = -1;
    }
}

// makes a new set with the vertex as its own parent
void DisjointSet::make_set(int x) {
    parent[x] = x;
    rank[x] = 0;
}

// searches recursively to find the parent of x
int DisjointSet::find_set(int x) {
    if (x != parent[x]) {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}

// unions the two sets
void DisjointSet::union_sets(int x, int y) {
    int new_x = find_set(x);
    int new_y = find_set(y);
    
    // already in same set
    if (new_x == new_y)
        return;
    
    if (rank[new_x] < rank[new_y])
        parent[new_x] = new_y;
    else if (rank[new_x] > rank[new_y]){
        parent[new_y] = new_x;
    } else {
        parent[new_y] = new_x;
        rank[new_x]++;
    }
}

// used for debugging purposes
void DisjointSet::print() {
    cout << "Ranks are: ";
    for(int i = 0; i < max_size; ++i){
        cout << rank[i] << " ";
    }
    
    cout << endl << "Parents are: ";
    for(int i = 0; i < max_size; ++i){
        cout << parent[i] << " ";
    }
    cout << endl;
}
