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
void LinkedList::insert_node(Edge x) {
    Node *new_node = new Node(x);
    
    // check if LinkedList is empty
    if (list_head == nullptr && list_tail == nullptr) {
        list_head = new_node;
        list_tail = new_node;
        list_head -> prev_node = nullptr;
        list_tail -> next_node = nullptr;
        
        new_node = nullptr;
        list_size = list_size + 1;
        return;
    }
    
    // else, the LinkedList is not empty
    
    // first check if the node currently exists
    // search where the index is
    long long index = search(x.vertex_v, "insert");
    
    // the new node will point to the head and the next node
    if (index == 0){
        new_node -> next_node = list_head;
        new_node -> prev_node = nullptr;
        list_head -> prev_node = new_node;
        list_head = new_node;
    }
    // the new node will point to the tail and the prev node
    else if (index == list_size){
        new_node -> prev_node = list_tail;
        new_node -> next_node = nullptr;
        list_tail -> next_node = new_node;
        list_tail = new_node;
    }
    // otherwise, place inbetween two existing nodes
    else {
        Node *current_node = list_head;
        int counter = 0;
        
        // stop once current node is less than new node
        while (counter < index) {
            current_node = current_node -> next_node;
            counter++;
        }
        new_node -> next_node = current_node;
        new_node -> prev_node = current_node->prev_node;
        if (current_node->prev_node != nullptr){
            current_node->prev_node->next_node = new_node;
        }
        current_node -> prev_node = new_node;
    }
    
    new_node = nullptr;
    list_size = list_size + 1;
}


// Remove element from the front or back and will output success/failure
void LinkedList::remove_node(int index){
    // check if LinkedList is empty
    if (list_head == nullptr && list_tail == nullptr) {
        return;
    }
    
    // else, the LinkedList is not empty
   
    // the new node will point to the head and the next node
    if (index == 0){
        Node *current_node = list_head;
        list_head = current_node -> next_node;
        if (list_size > 1)
            list_head -> prev_node = nullptr;
        else
            list_tail = nullptr;
        // remember to delete the node
        delete current_node;
        
    }
    // the new node will point to the tail and the prev node
    else if (index == list_size-1){
        Node *current_node = list_tail;
        list_tail = current_node -> prev_node;
        if (list_size > 1)
            list_tail -> next_node = nullptr;
        else
            list_head = nullptr;
        // remember to delete the node
        delete current_node;
        
        // otherwise, remove inbetween two existing nodes
    } else {
        Node *current_node = list_head;
        int counter = 0;
        
        while (counter < index) {
            current_node = current_node -> next_node;
            counter++;
        }
        current_node -> prev_node -> next_node = current_node -> next_node;
        current_node -> next_node -> prev_node = current_node -> prev_node;
        
        // remember to delete the node
        delete current_node;
    }
    
    list_size -= 1;
    //debug
    //cout << "new list size is: "<< list_size << endl;
}

// Clears the content of the LinkedList and will output success
void LinkedList::clear(){
    
    while (list_size > 0) {
        //cout << "deleting node " << list_head -> get_v_val() << endl;
        remove_node(0);
    }
    
    list_head = nullptr;
    list_tail = nullptr;
    list_size = 0;
}

// Return the size of the LinkedList
size_t LinkedList::get_size(){
    return list_size;
}

int LinkedList::search(int v, std::string type) {
    // search from front to back
    Node *current_node = list_head;
    int counter = 0;
    
    // remove / search will both give back the index of the current node
    if (type == "remove" || type == "search") {
        while (current_node != nullptr) {
            if (current_node -> get_v_val() == v) {
                current_node = nullptr;
                return counter;
            }
            current_node = current_node -> next_node;
            counter++;
        }
        return -1;
        
        // otherwise, type must be "insert"
    } else {
        // Node at index value being returned must be less than the num
        while (current_node != nullptr) {
            // at tail
            if (current_node -> next_node == nullptr) {
                if (current_node -> get_v_val() < v)
                    return counter+1;
            }
            // at head
            else if (current_node -> prev_node == nullptr) {
                if (current_node -> get_v_val() > v)
                    return counter;
            } else {
                if (current_node -> prev_node -> get_v_val() < v && current_node -> next_node -> get_v_val() > v)
                    return counter;
            }
            
            current_node = current_node -> next_node;
            counter++;
        }
        return counter;
    }
}

double LinkedList::get_node_weight(int v) {
    // search from front to back
    Node *current_node = list_head;
    double weight = 0;
    
    while (current_node != nullptr) {
        if (current_node -> get_v_val() == v) {
            weight = current_node -> get_w();
            current_node = nullptr;
            return weight;
        }
        current_node = current_node -> next_node;
    }
    return -1;
}

// Print all nodes in Linked list from front to back
void LinkedList::print(){
    cout << "list size is " << list_size << endl;
    if (list_size == 0) {
        return;
    } else {
        // print from front to back
        Node *current_node = list_head;
        
        while (current_node != nullptr) {
            cout << "{" << current_node -> get_u_val() << "," << current_node -> get_v_val() << "," << current_node -> get_w() << "}";
            current_node = current_node -> next_node;
            
            if (current_node != nullptr) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

// finds node then updates weight
void LinkedList::update_node_w(int index, double w){
    if (index == list_size-1) {
        Node *current_node = list_tail;
        current_node -> update_w(w);
    } else {
        Node *current_node = list_head;
        int counter = 0;
        
        // stop once current node is less than new node
        while (counter < index) {
            current_node = current_node -> next_node;
            counter++;
        }
        current_node -> update_w(w);
    }
}
