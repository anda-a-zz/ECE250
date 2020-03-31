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
void LinkedList::insert_node(Vertex x) {
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
    // search where the index is
    long long index = search(num, "insert");
    
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
void LinkedList::remove_node(unsigned long long num){
    // check if LinkedList is empty
    if (list_head == nullptr && list_tail == nullptr) {
        return;
    }
    
    // else, the LinkedList is not empty
    // search where the index is
    long long index = search(num, "remove");
    
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
    Node *current_node = list_head;
    
    while (current_node != nullptr) {
        //debug
        //cout << "removing " << current_node -> get_number() << endl;
        remove_node(current_node -> get_number());
        current_node = current_node -> next_node;
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

int LinkedList::search(long long num, std::string  type) {
    // search from front to back
    Node *current_node = list_head;
    int counter = 0;
    
    // remove / search will both give back the index of the current node
    if (type == "remove" || type == "search") {
        while (current_node != nullptr) {
            if (current_node -> get_number() == num) {
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
                if (current_node -> get_number() < num)
                    return counter+1;
            }
            // at head
            else if (current_node -> prev_node == nullptr) {
                if (current_node -> get_number() > num)
                    return counter;
            } else {
                if (current_node -> prev_node -> get_number() < num && current_node -> next_node -> get_number() > num)
                    return counter;
            }
            
            //                if (current_node -> get_number() < num && current_node -> next_node -> get_number() > num) {
            //                    current_node = nullptr;
            //                    return counter + 1;
            //                } else if (current_node -> get_number() > num && current_node -> next_node -> get_number() < num){
            //                    current_node = nullptr;
            //                    return counter;
            //                }
            //            } else {
            //                return (num > current_node -> get_number() ? counter + 1 : counter );
            //            }
            current_node = current_node -> next_node;
            counter++;
        }
        return counter;
    }
}

// Print all nodes in Linked list from front to back
void LinkedList::print(){
    if (list_size == 0) {
        return;
    } else {
        // print from front to back
        Node *current_node = list_head;
        
        while (current_node != nullptr) {
            unsigned long long current_num = current_node -> get_number();
            
            int counter = 0;
            while (current_num != 0) {
                current_num = current_num / 10;
                counter += 1;
            }
            
            counter = 10 - counter;
            
            while (counter > 0) {
                cout << "0";
                counter--;
            }
            if (current_node -> get_number() != 0)
                cout << current_node -> get_number();
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
