//
//  vertex.cpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-14.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include "vertex.h"

using namespace std;

Vertex::Vertex() {
    city_name = "";
    parent = nullptr;
}

Vertex::~Vertex() {
    city_name = "";
    parent = nullptr;
    adjacent_vertices.clear();
}

string Vertex::get_city() {
    return city_name;
}

void Vertex::set_city(string city) {
    city_name = city;
}

Vertex *Vertex::get_parent() {
    return parent;
}

void Vertex::set_parent(Vertex *p) {
    parent = p;
}

void Vertex::add_edge(Edge e) {
    adjacent_vertices.push_back(e);
}

vector<Edge> Vertex::adjacent(){
    return adjacent_vertices;
}

double Vertex::get_distance() {
    return distance;
}

void Vertex::set_distance(double dis) {
    distance = dis;
}
