//
//  vertexSet.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef edge_h
#define edge_h

#include "vertex.h"

class Edge {
public:
    Edge();
    Edge(Vertex city_1, Vertex city_2, double dis);
    Vertex get_city1();
    Vertex get_city2();
    double get_distance();
    void update_distance(double dis);
    void set_city2_dis(double dis);
    void set_city2_parent(std::string parent);
    
private:
    Vertex city1;
    Vertex city2;
    double distance;
};

#endif /* edge_h */
