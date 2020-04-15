//
//  treeGraph.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
// https://www.techiedelight.com/kruskals-algorithm-for-finding-minimum-spanning-tree/

#ifndef treegraph_h
#define treegraph_h

#include <vector>
#include "edge.h"
#include "vertex.h"

class TreeGraph {
public:
    TreeGraph();
    ~TreeGraph();
    std::vector<Vertex> V();        // returns a vector of all vertices in the graph
    int search(string city);    // searches for a city in graph
    int degree(string city);    // get degree of city
    int graph_nodes();          // Returns the number of cities
    int graph_edges();          // Returns the number of edges in the graph
    double dijkstra_alg(string name1, string name2); // returns shortest distance between cities
    void clear();
    void print();
    void insert_city(string city);  // add city into graph
    void set_distance(string name1, string name2, double distance); // set distance between edge
    
private:
    int edge_count;
    int vertex_count;
    std::vector<int> degree_of_vertices;
    std::vector<Vertex> vertices;
};

#endif /* treegraph_h */
