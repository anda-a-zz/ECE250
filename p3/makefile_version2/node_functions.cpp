//
//  node.cpp
//  p3
//
//  Created by Anda Achimescu on 2020-03-09.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include "node.h"

// Default Constructor
Node::Node() {
    next_NE = nullptr;
    next_NW = nullptr;
    next_SE = nullptr;
    next_SW = nullptr;
}

Node::~Node() {
    next_NE = nullptr;
    next_NW = nullptr;
    next_SE = nullptr;
    next_SW = nullptr;
}

// Constructor will initialize the Node
Node::Node(CityInfo city_name) {
    city = city_name;
    next_NE = nullptr;
    next_NW = nullptr;
    next_SE = nullptr;
    next_SW = nullptr;
}

// Get the next node
Node *Node::get_next(std::string direction) {
    if (direction == "NE")
        return next_NE;
    else if (direction == "NW")
        return next_NW;
    else if (direction == "SE")
        return next_SE;
    else
        return next_SW;
}

// Get x
double Node::get_x(){
    return city.get_x();
}

// Get y
double Node::get_y(){
    return city.get_y();
}

std::string Node::get_city_name() {
    return city.get_city_name();
}

// Population (p)
int Node::get_population(){
    return city.get_population();
}

// Cost of Living (r)
int Node::get_cost() {
    return city.get_cost();
}

// Average Net Salary (s)
int Node::get_salary() {
    return city.get_salary();
}
