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

class Vertex {
public:
    Vertex();
    Vertex(std::string city);
    Vertex(std::string city, double dis);
    ~Vertex();
    std::string get_city();             // return city name
    std::string get_parent();               // return parent of vertex
    double get_distance();              // return distance of city
    void set_distance(double dis);      // set distance
    void set_city(std::string city);    // set city
    void set_parent(std::string p);         // set parent
    
private:
    std::string parent;
    double distance;
    std::string city_name;
};

#endif /* vertex_h */
