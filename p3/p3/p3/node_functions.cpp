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

// Constructor will initialize the Node
Node::Node(CityInfo city) {
    this.city = city;
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
