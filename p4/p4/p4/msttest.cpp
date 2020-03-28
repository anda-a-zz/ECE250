//
//  main.cpp
//  p4
//
//  Created by Anda Achimescu on 2020-03-24.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include <string>
#include "treegraph_functions.cpp"
#include "disjointset_functions.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    string input = "";
    int array[3] = {0, 0, 0};
    unsigned long semicolon = 0;
    
    while (!cin.eof()){
        getline(cin, input);
        
        // Defines size of the hash table
        if (input.find("n") == 0 && input.find(' ') == 1 && input.substr(1,2) != " ") {
            // Example: n 4
            input = input.substr(2, input.length()-1);
            array[0] = stoi(input);
            if (array[0] < 0) {
                cout << "failure" << endl;
            } else {
                
            }
            //cout << array[0] << endl;
        } else if (input.find("i") == 0 && input.find(' ') == 1 && input.substr(1,2) != " ") {
            // Example: i 0;1;10
            input = input.substr(2, input.length()-1);
            
            for (int i = 0; i < 3; i++) {
                semicolon = input.find(';');
                array[i] = stod(input.substr(0, semicolon));
                input = input.substr(semicolon+1, input.length()-1);
            }
            
            // if the weight is the same or if u=v, print failure
            if (array[2] <= 0 || (array[0] == array[1])) {
                cout << "failure" << endl;
            } else {
                
            }
            
            //cout << array[0] << " " << array[1] << " " << array[2] << endl;
        } else if (input.find("d") == 0 && input.find(' ') == 1 && input.substr(1,2) != " ") {
            // Example: d 1;2
            input = input.substr(2, input.length()-1);
            
            for (int i = 0; i < 2; i++) {
                semicolon = input.find(';');
                array[i] = stod(input.substr(0, semicolon));
                input = input.substr(semicolon+1, input.length()-1);
            }
            cout << array[0] << " " << array[1] << endl;
        
        } else if (input.find("degree") == 0 && input.find(' ') == 6 && input.substr(6,7) != " ") {
            // Example: degree 0
            input = input.substr(6, input.length()-1);
            array[0] = stoi(input);
            cout << array[0] << endl;
            
        } else if (input.find("edge_count") == 0) {
            
        } else if (input.find("clear") == 0) {
            
            cout << "success" << endl;
            
        } else if (input.find("mst") == 0) {
          
        }
    }
    return 0;
}
