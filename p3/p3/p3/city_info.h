//
//  Node.h
//  p3
//
//  Created by Anda Achimescu on 2020-03-09.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef city_info
#define city_info

class CityInfo {
public:
    CityInfo();
    CityInfo(std::string name, double longitude, double latitude, double population, double cost_of_living, double average_net_salary);
    Node *get_next();
    Node *get_prev();
    
private:
    std::string name;
    double longitude;
    double latitude;
    double population;
    double cost_of_living;
    double average_net_salary;
    Node *next_node;
    Node *prev_node;
};


#endif /* city_info */
