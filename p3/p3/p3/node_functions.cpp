//
//  node_functions.cpp
//  p3
//
//  Created by Anda Achimescu on 2020-03-09.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include "city_info.h"

// Default Constructor
CityInfo::CityInfo() {
    next_node = nullptr;
    prev_node = nullptr;
}

// Constructor will initialize the Node
CityInfo::CityInfo(std::string name, double longitude, double latitude, double population, double cost_of_living, double average_net_salary) {
    this.name = name;
    this.longitude = longitude;
    this.latitude = latitude;
    this.population = population;
    this.cost_of_living = cost_of_living;
    this.average_net_salary = average_net_salary;
    next_node = nullptr;
    prev_node = nullptr;
}

// Get the next node
Node *Node::get_next() {
    return next_node;
}

// Get the previous node
Node *Node::get_prev() {
    return prev_node;
}
