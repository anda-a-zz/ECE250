//
//  vertex.cpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-14.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include "vertex.h"
#include <math.h>

using namespace std;

// constructor initializes city and distance
Vertex::Vertex() {
    city_name = "";
    distance = INFINITY;
    parent = "";
}

Vertex::Vertex(string city) {
    city_name = city;
    distance = INFINITY;
    parent = "";
}

Vertex::Vertex(string city, double dis) {
    city_name = city;
    distance = dis;
    parent = "";
}

// destructor sets everything to 0 or null
Vertex::~Vertex() {
    city_name = "";
    distance = 0;
    parent = "";
}

// return the city name
string Vertex::get_city() {
    return city_name;
}

// set the city name
void Vertex::set_city(string city) {
    city_name = city;
}

// return parent of vertex
std::string Vertex::get_parent() {
    return parent;
}

// set the parent of the vertex
void Vertex::set_parent(std::string p) {
    parent = p;
}

// return distance of city
double Vertex::get_distance() {
    return distance;
}

// set the distance of the city
void Vertex::set_distance(double dis) {
    distance = dis;
}
