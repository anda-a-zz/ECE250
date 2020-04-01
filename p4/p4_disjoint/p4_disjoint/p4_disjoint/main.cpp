//
//  main.cpp
//  p4_disjoint
//
//  Created by Anda Achimescu on 2020-03-31.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>

#include "disjointset_functions.cpp"
#include "vertex_functions.cpp"
#include "node_functions.cpp"
#include "linkedlist_functions.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    string input = "";
    int array[3] = {0, 0, 0};
    unsigned long semicolon = 0;
    DisjointSet set;
    
    while (!cin.eof()){
        getline(cin, input);
        
        // Defines size of the hash table
        if (input.find("n") == 0 && input.find(' ') == 1 && input.substr(1,2) != " ") {
            // Example: n 4
            input = input.substr(2, input.length()-1);
            array[0] = stoi(input);
            set.size(array[0]);
            
        } else if (input.find("make_set") == 0) {
            input = input.substr(9, input.length()-1);
            array[0] = stoi(input);
            cout << set.make_set(array[0]) << endl;
            
        } else if (input.find("find_set") == 0) {
            input = input.substr(9, input.length()-1);
            array[0] = stoi(input);
            cout << set.find_set(array[0]) << endl;
            
        } else if (input.find("union") == 0) {
            input = input.substr(6, input.length()-1);
            for (int i = 0; i < 2; i++) {
                semicolon = input.find(';');
                array[i] = stod(input.substr(0, semicolon));
                input = input.substr(semicolon+1, input.length()-1);
            }
            set.union_lists(array[0],array[1]);
            set.print();
            
        } else if (input.find("clear") == 0) {
            set.clear();
        }
    }
    return 0;
}
