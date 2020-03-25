//
//  main.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-03-24.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include <string>
#include "city_info_functions.cpp"
#include "quad_tree_functions.cpp"
#include "node_functions.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    string input = "";
    std::string array_string[2] = {"", ""};
    double array[5] = {0, 0, 0, 0, 0};
    unsigned long semicolon = 0;
    QuadTree tree;
    
    while (!cin.eof()){
        getline(cin, input);
        
        // Defines size of the hash table
        if (input.find("i") == 0) {
            // Example: i Toronto;-79.42;43.66;5213000;2157;3396
            semicolon = input.find(';');
            array_string[0] = input.substr(2, semicolon-2);
            input = input.substr(array_string[0].length()+3, input.length()-1);
            
            for (int i = 0; i < 5; i++) {
                semicolon = input.find(';');
                array[i] = stod(input.substr(0, semicolon));
                input = input.substr(semicolon+1, input.length()-1);
            }
            
            CityInfo city(array_string[0], array[0], array[1], array[2], array[3], array[4]);
            tree.insert(tree.root, city);
            
        } else if (input.find("s") == 0 && input.find(' ') == 1) {
            if (input.substr(1,2) != " ") {
                // Example: s -79.42;43.66
                input = input.substr(2, input.length()-1);
                semicolon = input.find(';');
                
                array[0] = std::stod(input.substr(0, semicolon)); // key value      // x
                array[1] = std::stod(input.substr(semicolon+1, input.length()-1));  // y
                tree.search(tree.root, array[0], array[1]);
                // cout << "x is " << x << " y is " << y << endl;
            }
            
        } else if (input.find("q_max") == 0) {
            if (input.find(' ') == 5 && input.substr(5,6) != " "){
                // Example: q_max -79.42;43.66;NE;p
                input = input.substr(6, input.length()-1);
                //cout << "new input " << input << endl;
                
                for (int i = 0; i < 4; i++) {
                    semicolon = input.find(';');
                    if (i < 2)
                        array[i] = stod(input.substr(0, semicolon));
                    else
                        array_string[i-2] = input.substr(0, semicolon);
                    input = input.substr(semicolon+1, input.length()-1);
                }
                tree.max_min_total_value(tree.root, array[0], array[1], array_string[0], array_string[1], "max");
                
                //cout << array[0] << " " << array[1] << " " << array_string[0] << " " << array_string[1] << endl;
                
            }
        } else if (input.find("q_min") == 0) {
            if (input.find(' ') == 5 && input.substr(5,6) != " "){
                // Example: q_min -79.42;43.66;NE;p
                input = input.substr(6, input.length()-1);
                //cout << "new input " << input << endl;
                
                for (int i = 0; i < 4; i++) {
                    semicolon = input.find(';');
                    if (i < 2)
                        array[i] = stod(input.substr(0, semicolon));
                    else
                        array_string[i-2] = input.substr(0, semicolon);
                    input = input.substr(semicolon+1, input.length()-1);
                }
                
                tree.max_min_total_value(tree.root, array[0], array[1], array_string[0], array_string[1], "min");
                
                // cout << array[0] << " " << array[1] << " " << array_string[0] << " " << array_string[1] << endl;
            }
        } else if (input.find("q_total") == 0) {
            if (input.find(' ') == 7 && input.substr(7,8) != " "){
                // Example: q_total -79.42;43.66;NE;p
                input = input.substr(8, input.length()-1);
                //cout << "new input " << input << endl;
                
                for (int i = 0; i < 4; i++) {
                    semicolon = input.find(';');
                    if (i < 2)
                        array[i] = stod(input.substr(0, semicolon));
                    else
                        array_string[i-2] = input.substr(0, semicolon);
                    input = input.substr(semicolon+1, input.length()-1);
                }
                
                tree.max_min_total_value(tree.root, array[0], array[1], array_string[0], array_string[1], "total");
                
                //cout << array[0] << " " << array[1] << " " << array_string[0] << " " << array_string[1] << endl;
            }
        } else if (input.find("print") == 0) {
            if (tree.get_size() != 0) {
                tree.print(tree.root);
                cout << endl;
            }
            
        } else if (input.find("clear") == 0) {
            tree.clear(tree.root);
            tree.root = nullptr;
            cout << "success" << endl;
            
        } else if (input.find("size") == 0) {
            cout << "tree size " << tree.get_size() << endl;
            
        }
    }
    return 0;
}
