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
   
}

// initializes heap with the vertices
void BinaryHeap::initialize(vector<Vertex> vertices) {
    heap_vertices = vertices;
    for (int i = heap_vertices.size(); i > 1; i--) {
        percolate_down(i);
    }
}

// returns the distance of the vertex with the minimum distance value and removes the Vertex from heap
Vertex BinaryHeap::del_min() {
    Vertex minimum = heap_vertices[0];
    heap_vertices[0] = heap_vertices[heap_vertices.size()-1];
    heap_vertices.pop_back();
    percolate_down(0);
    return minimum;
}

// Percolate Down:
// Swaps the root with its smallest child less than the root. Process of swapping will
// continue until the node is less than both of its children.
void BinaryHeap::percolate_down(int index) {
    int minimum = 0;
    Vertex temp;
    
    while (index * 2 <= heap_vertices.size()-1) {
        minimum = get_minimum_dis_index(index);
        if (heap_vertices[index].get_distance() > heap_vertices[minimum].get_distance()) {
            temp = heap_vertices[index];
            heap_vertices[index] = heap_vertices[minimum];
            heap_vertices[minimum] = temp;
        }
        if (minimum == 0)
            break;
        index = minimum;
    }
}

int BinaryHeap::get_minimum_dis_index(int index) {
    if (index*2 + 1 > heap_vertices.size()-1)
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
    for (int i = 0; i < heap_vertices.size(); i++) {
        if (heap_vertices[i].get_city() == v.get_city()) {
            heap_vertices.erase(heap_vertices.begin() + i);
            break;
        }
    }
    
    // Second, insert new vertex into vector
    heap_vertices.push_back(v);
    int i = heap_vertices.size()-1;
    Vertex temp;
    
    while (i != 0 && heap_vertices[i/2].get_distance() > heap_vertices[i].get_distance()) {
        temp = heap_vertices[i/2];
        heap_vertices[i/2] = heap_vertices[i];
        heap_vertices[i] = temp;
        i = i/2;
    }
}

bool BinaryHeap::search(std::string city_name) {
    for (int i = 0; i < heap_vertices.size(); i++) {
        if (heap_vertices[i].get_city() == city_name) {
            return true;
        }
    }
    return false;
}

int BinaryHeap::get_size() {
    return heap_vertices.size();
}
