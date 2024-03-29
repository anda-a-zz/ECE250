//
//  main.cpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-14.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include <iostream>
#include <string>
#include "illegal_argument.h"
#include "vertex_functions.cpp"
#include "edge_functions.cpp"
#include "edgeset_functions.cpp"
#include "priorityqueue_functions.cpp"
#include "binaryheap_functions.cpp"
#include "treegraph_functions.cpp"

using namespace std;

int main() {
    string input = "";
    string city[2] = {"", ""};
    int degree_val = 0;
    double distance = 0;
    unsigned long semicolon = 0;
    TreeGraph G;

    while (!cin.eof()){
        getline(cin, input);
        try {
            // Defines number of vertices in graph and the range
            if (input.find("i") == 0 && input.find(' ') == 1 && input.substr(1,2) != " ") {
                // Example: i city0
                input = input.substr(2, input.length()-1);
                G.insert_city(input);
                //cout << input << endl;
                cout << "success" << endl;

            } else if (input.find("setd") == 0 && input.find(' ') == 4 && input.substr(4,5) != " ") {
                // Example: setd Oshawa;Belleville;131.0
                input = input.substr(5, input.length()-1);
                
                for (int i = 0; i < 3; i++) {
                    semicolon = input.find(';');
                    if (i < 2)
                        city[i] = input.substr(0, semicolon);
                    else
                        distance = stod(input.substr(0, semicolon));
                    input = input.substr(semicolon+1, input.length()-1);
                }
                G.set_distance(city[0], city[1], distance);
                cout << "success" << endl;
                //cout << city[0] << " " << city[1] << " " << distance << endl;
                
            } else if (input.find("s") == 0 && input.find(' ') == 1 && input.substr(1,2) != " ") {
                // Example: s city0
                input = input.substr(2, input.length()-1);
                //cout << input << endl;
                degree_val = G.search(input);
                
                if (degree_val == -1)
                    cout << "not found" << endl;
                else
                    cout << "found " << input << endl;

            } else if (input.find("degree") == 0 && input.find(' ') == 6 && input.substr(6,7) != " ") {
                // Example: degree city0
                input = input.substr(7, input.length()-1);
                degree_val = G.degree(input);
                cout << "degree of " << input << " is " << degree_val << endl;
                
            } else if (input.find("graph_nodes") == 0) {
                degree_val = G.graph_nodes();
                cout << "number of nodes " << degree_val << endl;
                
            } else if (input.find("graph_edges") == 0) {
                degree_val = G.graph_edges();
                cout << "number of edges " << degree_val << endl;
                
            } else if (input.find("d") == 0 && input.find(' ') == 1 && input.substr(1,2) != " ") {
                // Example: d city0;city1
                input = input.substr(2, input.length()-1);
                
                for (int i = 0; i < 2; i++) {
                    semicolon = input.find(';');
                    city[i] = input.substr(0, semicolon);
                    input = input.substr(semicolon+1, input.length()-1);
                }
                degree_val = G.W(city[0], city[1]);
                
                if (degree_val != -1)
                    cout << "direct distance " << city[0] << " to " << city[1] << " " << degree_val << endl;
                else
                    cout << "failure" << endl;
                //cout << city[0] << " " << city[1] << endl;
                
            } else if (input.find("shortest_d") == 0 && input.find(' ') == 10 && input.substr(10,11) != " ") {
                // Example: shortest_d city0;city4
                input = input.substr(11, input.length()-1);
                
                for (int i = 0; i < 2; i++) {
                    semicolon = input.find(';');
                    city[i] = input.substr(0, semicolon);
                    input = input.substr(semicolon+1, input.length()-1);
                }
                degree_val = G.dijkstra_alg(city[0], city[1]);
                cout << "shortest distance " << city[0] << " to " << city[1] << " " << degree_val << endl;
                //cout << city[0] << " " << city[1] << endl;
                
            } else if (input.find("print_path") == 0 && input.find(' ') == 10 && input.substr(10,11) != " ") {
                // Example: print_path Toronto;Montreal
                input = input.substr(11, input.length()-1);
                
                for (int i = 0; i < 2; i++) {
                    semicolon = input.find(';');
                    city[i] = input.substr(0, semicolon);
                    input = input.substr(semicolon+1, input.length()-1);
                }
                G.print(city[0], city[1]);
                //cout << city[0] << " " << city[1] << endl;
                
            } else if (input.find("clear") == 0) {
                G.clear();
                cout << "success" << endl;
                
            }
            
        } catch (IllegalArgument) {
            cout << "failure" << endl;
        }
        
    }
    return 0;
}
