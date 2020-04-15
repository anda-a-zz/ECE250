//
//  edge_functions.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "edge.h"

using namespace std;

// Constructor initializes the Edge by setting everything to -1 or empty
Edge::Edge(){
    city_name = "";
    distance = -1;
}

// initialize the edge by setting the key values and the weight
Edge::Edge(std::string city, double dis) {
    city_name = city;
    distance = dis;
}

std::string Edge::get_city_name() {
    return city_name;
}

double Edge::get_distance() {
    return distance;
}

void Edge::update_distance(double dis) {
    distance = dis;
}

