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
    city1 = Vertex("");
    city2 = Vertex("");
    distance = -1;
}

// initialize the edge by setting the key values and the distance between 2 cities
Edge::Edge(Vertex city_1, Vertex city_2, double dis) {
    city1 = city_1;
    city2 = city_2;
    distance = dis;
}

// returns the specified city
Vertex Edge::get_city1(){
    return city1;
}

Vertex Edge::get_city2(){
    return city2;
}

// returns the distance between the two
double Edge::get_distance() {
    return distance;
}

void Edge::update_distance(double dis) {
    distance = dis;
}

void Edge::set_city2_dis(double dis) {
    city2.set_distance(dis);
}

void Edge::set_city2_parent(std::string parent) {
    city2.set_parent(parent);
}
