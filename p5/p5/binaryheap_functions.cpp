//
//  binaryheap.cpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-15.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include "binaryheap.h"

// constructor creates empty heap
BinaryHeap::BinaryHeap() {
    Vertex v("");
    heap_vertices.push_back(v);
}

// initializes heap with the vertices
void BinaryHeap::initialize(vector<Vertex> vertices) {
    // add all vertices in O(V) time
    for (int i = 0; i < vertices.size(); i++) {
        heap_vertices.push_back(vertices[i]);
    }
    
    for (int i = vertices.size(); i > 0; i--) {
        percolate_down(i);
    }
}

// returns the distance of the vertex with the minimum distance value and removes the Vertex from heap
Vertex BinaryHeap::del_min() {
    Vertex minimum = heap_vertices[1];
    heap_vertices[1] = heap_vertices[heap_vertices.size()];
    heap_vertices.pop_back();
    percolate_down(1);
    return minimum;
}

// Percolate Down:
// Swaps the root with its smallest child less than the root. Process of swapping will
// continue until the node is less than both of its children.
void BinaryHeap::percolate_down(int index) {
    int minimum = 0;
    Vertex temp;
    while (index * 2 <= heap_vertices.size()) {
        minimum = get_minimum_dis_index(index);
        if (heap_vertices[index].get_distance() > heap_vertices[minimum].get_distance()) {
            temp = heap_vertices[index];
            heap_vertices[index] = heap_vertices[minimum];
            heap_vertices[minimum] = temp;
        }
        index = minimum;
    }
}

int BinaryHeap::get_minimum_dis_index(int index) {
    if (index*2 + 1 > heap_vertices.size())
        return index*2;

    if (heap_vertices[index*2].get_distance() < heap_vertices[index*2 + 1].get_distance())
        return index*2;

    return index*2 + 1;
}

// returns true if the heap is empty
bool BinaryHeap::is_empty() {
    if (heap_vertices.size()-1 == 0)
        return true;
    return false;
}

void BinaryHeap::insert(Vertex v) {
    // First, delete vertex v from vector
    for (int i = 1; i <= heap_vertices.size(); i++) {
        if (heap_vertices[i].get_city() == v.get_city())
            heap_vertices.erase(heap_vertices.begin() + i);
    }
    
    // Second, insert new vertex into vector
    heap_vertices.push_back(v);
    int size = heap_vertices.size() - 1;
    Vertex temp;
    
    while (size / 2 > 0) {
        if (heap_vertices[size].get_distance() < heap_vertices[size/2].get_distance()){
            temp = heap_vertices[size];
            heap_vertices[size] = heap_vertices[size/2];
            heap_vertices[size/2] = temp;
        }
        size = size/2;
    }
}
