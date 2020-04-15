//
//  vertexSet.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef edge_h
#define edge_h

class Edge {
public:
    Edge();
    Edge(std::string city, double dis);
    std::string get_city_name();
    double get_distance();
    void update_distance(double dis);
    
private:
    std::string city_name;
    double distance;
};

#endif /* edge_h */
