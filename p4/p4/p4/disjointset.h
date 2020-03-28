//
//  disjointSet.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef disjointset_h
#define disjointset_h

#include "node.H"

class DisjointSet {
public:
    DisjointSet();                      // Constructor sets pointers to nullptr
    ~DisjointSet();                     // Destructor sets pointers to nullptr and deletes
    string make_set(Vertex x);
    string find_set(Vertex x);
    void union_lists(Vertex x, Vertex y);
    void clear();
    
    
private:
    Node *set_head;
    Node *set_tail;
    string setID;
    void remove_node();
    
};

#endif /* disjointset_h */
