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
    this.name = "";
    this.longitude = 0;
    this.latitude = 0;
    this.population = 0;
    this.cost_of_living = 0;
    this.average_net_salary = 0;
}

// Constructor will initialize the Node
CityInfo::CityInfo(std::string name, double longitude, double latitude, double population, double cost_of_living, double average_net_salary) {
    this.name = name;
    this.longitude = longitude;
    this.latitude = latitude;
    this.population = population;
    this.cost_of_living = cost_of_living;
    this.average_net_salary = average_net_salary;
}
