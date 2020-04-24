//
//  binaryheap.hpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-15.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef binaryheap_h
#define binaryheap_h

#include <stdio.h>

class BinaryHeap {
public:
    BinaryHeap();           // constructor creates empty heap
    ~BinaryHeap();
    int get_minimum_dis_index(int index);
    void insert(Vertex v);  // in order to modify key value
    Vertex del_min();       // returns the vertex with the minimum distance                                              value and removes Vertex from heap
    void percolate_down(int index);
    bool is_empty();        // returns true if the heap is empty
    void initialize(vector<Vertex> vertices);   // initializes heap with the vertices
    int search(std::string city_name);
    int get_size();
    void decrease_key_val(Vertex v);
    
private:
    vector<Vertex> heap_vertices;
};

#endif /* binaryheap_h */
