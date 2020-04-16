//
//  vertex.hpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-14.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef vertex_h
#define vertex_h

#include <vector>
#include <string>
#include "edge.h"

class Vertex {
public:
    Vertex();
    Vertex(std::string city);
    ~Vertex();
    std::string get_city();
    Vertex *get_parent();
    std::vector<Edge> adjacent();
    double get_distance();
    void set_distance(double dis);
    void set_city(std::string city);
    void set_parent(Vertex *p);
    void add_edge(Edge e);
    
private:
    Vertex *parent;
    std::string city_name;
    double distance;
    std::vector<Edge> adjacent_vertices;
};

#endif /* vertex_h */
