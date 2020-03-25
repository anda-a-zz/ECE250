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
    CityInfo(std::string city_name, double x, double y, int pop, int cost, int salary);
    double get_x();
    double get_y();
    std::string get_city_name();
    int get_population();
    int get_cost();
    int get_salary();
    
private:
    std::string name;
    double longitude;
    double latitude;
    double population;
    double cost_of_living;
    double average_net_salary;
};


#endif /* city_info */
