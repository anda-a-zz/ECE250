//
//  linkedlist_functions.cpp
//  p2
//
//  Created by Anda Achimescu on 2020-02-11.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include "linkedlist.h"
#include "node.h"

using namespace std;

// Constructor initializes the LinkedList
LinkedList::LinkedList(){
    list_size = 0;
    list_head = nullptr;
    list_tail = nullptr;
}

// Destructor deallocates the memory by deleting any pointers
LinkedList::~LinkedList() {
    clear();
}

// Add element at the front or to the end and will output success to standard output
void LinkedList::insert_node(int x) {
    Node *new_node = new Node(x);
    
    if (list_size == 0) {
        list_head = new_node;
        list_tail = new_node;
        list_head -> prev_node = nullptr;
        list_tail -> next_node = nullptr;
    } else {
        
    }
    
    
    new_node = nullptr;
    list_size = list_size + 1;
}


// Remove element from the front or back and will output success/failure
void LinkedList::remove_node(){
    // check if LinkedList is empty
    if (list_head == nullptr && list_tail == nullptr) {
        return;
    }
    
    Node *current_node = list_head;
    list_head = current_node -> next_node;
    if (list_size > 1)
        list_head -> prev_node = nullptr;
    else
        list_tail = nullptr;
    // remember to delete the node
    
    delete current_node;
    current_node = nullptr;

    list_size -= 1;
}

// Clears the content of the LinkedList and will output success
void LinkedList::clear(){
    Node *current_node = list_head;
    
    while (list_size > 0) {
        remove_node();
    }
    
    current_node = nullptr;
    list_head = nullptr;
    list_tail = nullptr;
    list_size = 0;
}

// Return the size of the LinkedList
size_t LinkedList::get_size(){
    return list_size;
}

// Print all nodes in Linked list from front to back
void LinkedList::print(){
    if (list_size == 0) {
        return;
    } else {
        // print from front to back
        Node *current_node = list_head;
        
        while (current_node != nullptr) {
            
            if (current_node -> get_key() != -1)
                cout << current_node -> get_key();
            current_node = current_node -> next_node;
            
            if (current_node != nullptr) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Return caller from current node
int LinkedList::get_parent_key(){
    return list_head -> get_key();
}
