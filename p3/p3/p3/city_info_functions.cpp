//
//  node_functions.cpp
//  p3
//
//  Created by Anda Achimescu on 2020-03-09.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include "city_info.h"

// Default Constructor
CityInfo::CityInfo() {
    name = "";
    longitude = 0;
    latitude = 0;
    population = 0;
    cost_of_living = 0;
    average_net_salary = 0;
}

// Constructor will initialize the Node
CityInfo::CityInfo(std::string city_name, double x, double y, double pop, double cost, double salary) {
    name = city_name;
    longitude = x;
    latitude = y;
    population = pop;
    cost_of_living = cost;
    average_net_salary = salary;
}

// Get x
double CityInfo::get_x(){
    return longitude;
}

// Get y
double CityInfo::get_y(){
    return latitude;
}

// Get city name
std::string CityInfo::get_city_name() {
    return name;
}
