//
//  edgeset.cpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-16.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include "edgeset.h"

EdgeSet::EdgeSet() {
    root = Vertex("");
}

EdgeSet::EdgeSet(Vertex set_root) {
    root = set_root;
}

EdgeSet::~EdgeSet() {
    adjacent_vertices.clear();
    adjacent_vertices.shrink_to_fit();
}

void EdgeSet::add_edge(Edge e) {
    adjacent_vertices.push_back(e);
}

Vertex EdgeSet::get_root() {
    return root;
}

vector<Edge> EdgeSet::get_adjacent_vertices() {
    return adjacent_vertices;
}

void EdgeSet::set_root(double distance) {
    root.set_distance(distance);
}

void EdgeSet::set_root_parent(std::string parent) {
    root.set_parent(parent);
}

int EdgeSet::search(std::string city_name) {
    for (int i = 0; i < adjacent_vertices.size(); i++) {
        if (adjacent_vertices[i].get_city2().get_city() == city_name)
            return i;
    }
    return -1;
}

void EdgeSet::change_distance(int index, double distance) {
    adjacent_vertices[index].update_distance(distance);
}
