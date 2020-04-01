//
//  linkedlist.h
//  p2
//
//  Created by Anda Achimescu on 2020-02-11.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include "node.h"
#include "vertex.h"

class LinkedList {
    friend class DisjointSet;
public:
    LinkedList();                   // Constructor sets pointers to nullptr
    ~LinkedList();                  // Destructor sets pointers to nullptr and deletes
    void insert_node(int x);                             // Add element
    void remove_node();                                     // Remove element
    void print();
    void clear();                                           // Clears the content of the list
    size_t get_size();                                      // Return the size of the deque
    int get_parent_key();
    
private:
    Node *list_head;
    Node *list_tail;
    size_t list_size;
};

#endif /* linkedlist_h */
