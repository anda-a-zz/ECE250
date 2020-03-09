//
//  main.cpp
//  p3
//
//  Created by Anda Achimescu on 2020-03-04.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string input = "";
    unsigned long long i = 0;
    int x, y;
    std::string city_info = "";
    std::string caller = "";
    unsigned long semicolon = 0;
    
    while (!cin.eof()){
        getline(cin, input);
        
        // Defines size of the hash table
        if (input.find("i") == 0) {
            // Example: i Toronto;-79.42;43.66;5213000;2157;3396
            semicolon = input.find(';');
            city_info = input.substr(2, semicolon-2);
            cout << city_info << endl;
            input = input.substr(city_info.length(), input.length()-1);
            
            
            cout << "success" << endl;
            
        } else if (input.find("s") == 0) {
            if (input.find(' ') == 1 && input.substr(1,2) != " ") {
                input = input.substr(2, input.length()-1);
                semicolon = input.find(';');
                
                x = std::stoi(input.substr(0, semicolon)); // key value
                y = std::stoi(input.substr(semicolon+1, input.length()-1));
            }
            
        } else if (input.find("q_max") == 0) {
            if (input.find(' ') == 1 && (std::stoi(input.substr(2, input.length()-1)) != string::npos)){
                i = std::stoi(input.substr(1, input.length()-1));
               
            }
        } else if (input.find("q_min") == 0) {
            if (input.find(' ') == 1 && (std::stoi(input.substr(2, input.length()-1)) != string::npos)){
                i = std::stoi(input.substr(1, input.length()-1));
            }
        } else if (input.find("q_total") == 0) {
            if (input.find(' ') == 1 && (std::stoi(input.substr(2, input.length()-1)) != string::npos)){
                i = std::stoi(input.substr(1, input.length()-1));
                
            }
        } else if (input.find("print") == 0) {
            if (input.find(' ') == 1 && (std::stoi(input.substr(2, input.length()-1)) != string::npos)){
                i = std::stoi(input.substr(1, input.length()-1));
                
            }
        } else if (input.find("clear") == 0) {
            if (input.find(' ') == 1 && (std::stoi(input.substr(2, input.length()-1)) != string::npos)){
                i = std::stoi(input.substr(1, input.length()-1));
                
            }
        } else if (input.find("size") == 0) {
            if (input.find(' ') == 1 && (std::stoi(input.substr(2, input.length()-1)) != string::npos)){
                i = std::stoi(input.substr(1, input.length()-1));
                
            }
        }
    }
    return 0;
}
