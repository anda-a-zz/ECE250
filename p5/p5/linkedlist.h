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
#include "edge.h"

class LinkedList {
    friend class TreeGraph;
public:
    LinkedList();                          // Constructor sets pointers to nullptr
    ~LinkedList();                         // Destructor sets pointers to nullptr and deletes
    void insert_node(Edge x);              // Add element
    void remove_node(int index);           // Removes node with u and v values at index
    int search (int v, std::string type);
    void print();
    void clear();                                           // Clears the content of the list
    size_t get_size();                                      // Return the size of the list
    double get_node_weight(int v);
    void update_node_w(int index, double w);
    
private:
    Node *list_head;
    Node *list_tail;
    size_t list_size;
};

#endif /* linkedlist_h */
