//
//  disjointSet.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef disjointset_h
#define disjointset_h

#include "node.h"
#include "linkedlist.h"

class DisjointSet {
public:
    DisjointSet();                      // Constructor sets pointers to nullptr
    ~DisjointSet();                     // Destructor sets pointers to nullptr and deletes
    Node * make_set(Vertex x);
    Node * find_set(Vertex x);
    void union_lists(Vertex x, Vertex y);
    void clear();
    void size(int n);
    
private:
    std::vector<LinkedList> disjoint_lists;
    size_t max_size;
    size_t set_size;
};

#endif /* disjointset_h */

// In my disjoint_lists vector:
// ie: n = 5
// | 0 | 1 | 2 | 3 | 4 |
// union 0 & 4
// | 0 | 1 | 2 | 3 | 0 |
// | 4 |
// find set (vertex = 4)
// if vertex = vector[vertex] then found!
// else, vector[vector[vertex]] (go to the next value inside)
