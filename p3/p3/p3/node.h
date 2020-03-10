//
//  node.hpp
//  p3
//
//  Created by Anda Achimescu on 2020-03-09.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef node_h
#define node_h

class Node {
    friend class CityInfo;
    friend class QuadTree;
public:
    Node();
    Node(CityInfo city);
    Node *get_next(std::string direction);      // get next node
    Node *get_prev();
    double get_x();
    double get_y();
    std::string get_city_name();
    
private:
    CityInfo city;
    Node *next_NE;
    Node *next_NW;
    Node *next_SE;
    Node *next_SW;
    Node *prev_node;
};

#endif /* node_h */
