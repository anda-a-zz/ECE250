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
    Edge(std::string city_name, double dis, double city_dis);
    std::string get_city_name();
    double get_distance();
    double get_city_dis();
    void update_distance(double dis);
    
private:
    std::string city;
    double city_distance;
    double distance;
};

#endif /* edge_h */
