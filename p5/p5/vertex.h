//
//  vertex.hpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-14.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef vertex_h
#define vertex_h

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Vertex {
public:
    Vertex();
    Vertex(string city);
    ~Vertex();
    string get_city();
    Vertex *get_parent();
    vector<Edge> adjacent();
    double get_distance();
    void set_distance(double dis);
    void set_city(string city);
    void set_parent(Vertex *p);
    void add_edge(Edge e);
    
private:
    Vertex *parent;
    string city_name;
    double distance;
    vector<Edge> adjacent_vertices;
};

#endif /* vertex_h */
