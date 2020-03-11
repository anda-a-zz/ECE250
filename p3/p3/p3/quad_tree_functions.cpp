//
//  quad_tree_functions.cpp
//  p3
//
//  Created by Anda Achimescu on 2020-03-09.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include "quad_tree.h"
#include "city_info.h"
#include "node.h"

using namespace std;

// Default Constructor
QuadTree::QuadTree() {
    root = nullptr;
    tree_size = 0;
}

// Destructor
QuadTree::~QuadTree() {
    clear();
}

void QuadTree::insert(Node *current_node, CityInfo city) {
    // if tree size is 0, then (x,y) could not be found
    if (current_node == nullptr) {
        Node *new_node = new Node(city);
        // set this equal to the root
        root = new_node;
        root -> next_NE = nullptr;
        root -> next_NW = nullptr;
        root -> next_SE = nullptr;
        root -> next_SW = nullptr;
        root -> prev_node = nullptr;
        new_node = nullptr;
        tree_size = tree_size + 1;
        cout << "success" << endl;
        return;
    }
    
    // found (x,y) and must return tree
    if ((city.get_x() == current_node->get_x()) && (city.get_y() == current_node->get_y())) {
        cout << "failure" << endl;
        return;
    }
    if ((city.get_x() <= current_node->get_x()) && (city.get_y() < current_node->get_y())){
        if (current_node->get_next("SW") == nullptr) {
            Node *new_node = new Node(city);
            new_node -> next_NE = nullptr;
            new_node -> next_NW = nullptr;
            new_node -> next_SE = nullptr;
            new_node -> next_SW = nullptr;
            current_node -> next_SW = new_node;
            tree_size = tree_size + 1;
            cout << "success" << endl;
            return;
        }
        
        return insert(current_node->get_next("SW"), city);
    }else if ((city.get_x() < current_node->get_x()) && (city.get_y() >= current_node->get_y())){
        if (current_node->get_next("NW") == nullptr) {
            Node *new_node = new Node(city);
            new_node -> next_NE = nullptr;
            new_node -> next_NW = nullptr;
            new_node -> next_SE = nullptr;
            new_node -> next_SW = nullptr;
            current_node -> next_NW = new_node;
            tree_size = tree_size + 1;
            cout << "success" << endl;
            return;
        }
        
        return insert(current_node->get_next("NW"), city);
    }else if ((city.get_x() > current_node->get_x()) && (city.get_y() <= current_node->get_y())){
        if (current_node->get_next("SE") == nullptr) {
            Node *new_node = new Node(city);
            new_node -> next_NE = nullptr;
            new_node -> next_NW = nullptr;
            new_node -> next_SE = nullptr;
            new_node -> next_SW = nullptr;
            current_node -> next_SE = new_node;
            tree_size = tree_size + 1;
            cout << "success" << endl;
            return;
        }
        
        return insert(current_node->get_next("SE"), city);
    }else if ((city.get_x() >= current_node->get_x()) && (city.get_y() > current_node->get_y())){
        if (current_node->get_next("NE") == nullptr) {
            Node *new_node = new Node(city);
            new_node -> next_NE = nullptr;
            new_node -> next_NW = nullptr;
            new_node -> next_SE = nullptr;
            new_node -> next_SW = nullptr;
            current_node -> next_NE = new_node;
            tree_size = tree_size + 1;
            cout << "success" << endl;
            return;
        }
        
        return insert(current_node->get_next("NE"), city);
    }
}

bool QuadTree::search(Node *current_node, double x, double y) {
    // if tree size is 0, then (x,y) could not be found
    if (current_node == nullptr) {
        cout << "not found" << endl;
        return 0;
    }
    // found (x,y) and print out found
    if ((x == current_node->get_x()) && (y == current_node->get_y())) {
        cout << "found " << current_node->get_city_name() << endl;
        return 1;
    }
    
    // recursion
    if ((x <= current_node->get_x()) && (y < current_node->get_y()))
        return search(current_node->get_next("SW"), x, y);
    else if ((x < current_node->get_x()) && (y >= current_node->get_y()))
        return search(current_node->get_next("NW"), x, y);
    else if ((x > current_node->get_x()) && (y <= current_node->get_y()))
        return search(current_node->get_next("SE"), x, y);
    //else if ((city.get_x() >= current_node->get_x()) && (city.get_y() > current_node->get_y()))
    else
        return search(current_node->get_next("NE"), x, y);
}

size_t QuadTree::get_size() {
    return tree_size;
}

void QuadTree::clear() {
    
}

Node *QuadTree::get_root() {
    return root;
}

// NE, NW, ROOT, SW, SE
void QuadTree::print(Node *current_node) {
    if (current_node != nullptr) {
        print(current_node->get_next("NE"));
        print(current_node->get_next("NW"));
        cout << current_node->get_city_name() << " ";
        print(current_node->get_next("SW"));
        print(current_node->get_next("SE"));
    }
}
