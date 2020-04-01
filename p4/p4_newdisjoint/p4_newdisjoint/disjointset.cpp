//
//  disjointset.cpp
//  p4_newdisjoint
//
//  Created by Anda Achimescu on 2020-03-31.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include "disjointset.h"
#include <iostream>
#include <vector>

using namespace std;

DisjointSet::DisjointSet() {
    max_size = 0;
}

DisjointSet::~DisjointSet() {
    rank.clear();
    rank.shrink_to_fit();
    parent.clear();
    parent.shrink_to_fit();
    max_size = 0;
}

void DisjointSet::size(int n) {
    rank.resize(n);
    parent.resize(n);
    max_size = n;
    for(int i = 0; i < n; ++i){
        rank[i] = -1;
        parent[i] = -1;
    }
}

void DisjointSet::make_set(int x) {
    parent[x] = x;
    rank[x] = 0;
}

int DisjointSet::find_set(int x) {
    if (x != parent[x]) {
        parent[x] = find_set(x);
    }
    return parent[x];
}

void DisjointSet::union_sets(int x, int y) {
    int new_x = find_set(x);
    int new_y = find_set(y);
    
    if (rank[new_x] > rank[new_y])
        parent[new_y] = parent[new_x];
    else {
        parent[new_x] = parent[new_y];
        if (rank[new_x] == rank[new_y])
            rank[new_y]++;
    }    
}

void DisjointSet::print() {
    cout << "Ranks are: " << endl;
    for(int i = 0; i < max_size; ++i){
        cout << rank[i] << " ";
    }
    
    cout << "Parents are: " << endl;
    for(int i = 0; i < max_size; ++i){
        cout << parent[i] << " ";
    }
}
