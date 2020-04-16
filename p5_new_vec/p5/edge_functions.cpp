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
    city = "";
    distance = -1;
    city_distance = -1;
}

// initialize the edge by setting the key values and the weight
Edge::Edge(string city_name, double dis, double city_dis) {
    city = city_name;
    distance = dis;
    city_distance = city_dis;
}

std::string Edge::get_city_name() {
    return city;
}

double Edge::get_distance() {
    return distance;
}

void Edge::update_distance(double dis) {
    distance = dis;
}

double Edge::get_city_dis() {
    return city_distance;
}
