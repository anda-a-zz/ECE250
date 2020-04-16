//
//  treeGraph.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.

#ifndef treegraph_h
#define treegraph_h

#include <vector>

class TreeGraph {
public:
    TreeGraph();
    ~TreeGraph();
    std::vector<Vertex> V();        // returns a vector of all vertices in the graph
    double W(std::string v, std::string u);   // returns the distance between the edge
    int search(std::string city);    // searches for a city in graph
    int degree(std::string city);    // get degree of city
    int graph_nodes();          // Returns the number of cities
    int graph_edges();          // Returns the number of edges in the graph
    double dijkstra_alg(std::string name1, std::string name2); // returns shortest distance between cities
    void insert_city(std::string city);  // add city into graph
    void set_distance(std::string name1, std::string name2, double distance); // set distance between edge
    bool relax(Vertex u, Vertex v); // test if the shortest path can be improved
    void clear();
    void print(std::string name1, std::string name2); // prints out shortest path
    
private:
    int edge_count;
    int vertex_count;
    std::vector<int> degree_of_vertices;
    std::vector<EdgeSet> nodes;
    std::vector<Vertex> vertices;
};

#endif /* treegraph_h */
