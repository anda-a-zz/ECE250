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
#include "linkedlist_functions.cpp"
#include "node_functions.cpp"
#include "kruskal_alg.cpp"
#include "edge_functions.cpp"
#include "illegal_argument.h"

using namespace std;

int main() {
    string input = "";
    int array[2] = {0, 0};
    double weight = 0;
    unsigned long semicolon = 0;
    TreeGraph G;
    
    while (!cin.eof()){
        getline(cin, input);
        try {
            // Defines number of vertices in graph and the range 
            if (input.find("n") == 0 && input.find(' ') == 1 && input.substr(1,2) != " ") {
                // Example: n 4
                input = input.substr(2, input.length()-1);
                array[0] = stoi(input);
                G.size(array[0]);
                cout << "success" << endl;

            } else if (input.find("i") == 0 && input.find(' ') == 1 && input.substr(1,2) != " ") {
                // Example: i 0;1;10
                input = input.substr(2, input.length()-1);
                
                for (int i = 0; i < 3; i++) {
                    semicolon = input.find(';');
                    if (i < 2)
                        array[i] = stoi(input.substr(0, semicolon));
                    else
                        weight = stod(input.substr(0, semicolon));
                    input = input.substr(semicolon+1, input.length()-1);
                }
                G.add_edge(array[0], array[1], weight);
                cout << "success" << endl;
                
                //cout << array[0] << " " << array[1] << " " << array[2] << endl;
            } else if (input.find("d") == 0 && input.find(' ') == 1 && input.substr(1,2) != " ") {
                // Example: d 1;2
                input = input.substr(2, input.length()-1);
                
                for (int i = 0; i < 2; i++) {
                    semicolon = input.find(';');
                    array[i] = stod(input.substr(0, semicolon));
                    input = input.substr(semicolon+1, input.length()-1);
                }
                if (G.delete_edge(array[0], array[1]))
                    cout << "success" << endl;
                else
                    cout << "failure" << endl;
                //cout << array[0] << " " << array[1] << endl;
            
            } else if (input.find("degree") == 0 && input.find(' ') == 6 && input.substr(6,7) != " ") {
                // Example: degree 0
                input = input.substr(6, input.length()-1);
                array[0] = stoi(input);
                array[1] = G.degree(array[0]);
                
                cout << "degree of " << array[0] << " is " << array[1] << endl;
                
            } else if (input.find("edge_count") == 0) {
                cout << "edge count is " << G.get_edge_count() << endl;
                
            } else if (input.find("clear") == 0) {
                G.clear();
                cout << "success" << endl;
                
            } else if (input.find("mst") == 0) {
                weight = G.kruskal_alg();
                if (weight == 0)
                    cout << "not connected" << endl;
                else
                    cout << "mst " << weight << endl;
                
            } else if (input.find("print") == 0) {
                G.print();
            }
        } catch (IllegalArgument) {
            cout << "failure" << endl;
        }
        
    }
    return 0;
}
