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

BinaryHeap::~BinaryHeap() {
    heap_vertices.clear();
    heap_vertices.shrink_to_fit();
}

// initializes heap with the vertices
void BinaryHeap::initialize(vector<Vertex> vertices) {
    //heap_vertices = vertices;
    for (int i = 0; i < vertices.size(); i++) {
        insert(vertices[i]);
    }
}

// returns the distance of the vertex with the minimum distance value and removes the Vertex from heap
Vertex BinaryHeap::del_min() {
    Vertex minimum = heap_vertices[0];
    heap_vertices[0] = heap_vertices[heap_vertices.size()-1];
    heap_vertices.pop_back();
    
    // if empty, just return the last minimum
    if (heap_vertices.size() == 0)
        return minimum;
    // otherwise, swap root with children
    percolate_down(0);
    return minimum;
}

// Percolate Down:
// Swaps the root with its smallest child less than the root. Process of swapping will
// continue until the node is less than both of its children.
void BinaryHeap::percolate_down(int index) {
    int minimum = index;
    int left_node = 2*index+1;
    int right_node = 2*index+2;
    Vertex temp;
    
    if (left_node < heap_vertices.size() && heap_vertices[left_node].get_distance() < heap_vertices[index].get_distance())
        minimum = left_node;
    if (right_node < heap_vertices.size() && heap_vertices[right_node].get_distance() < heap_vertices[minimum].get_distance())
        minimum = right_node;
    if (minimum != index) {
        temp = heap_vertices[index];
        heap_vertices[index] = heap_vertices[minimum];
        heap_vertices[minimum] = temp;
        percolate_down(minimum);
    }
}

// returns true if the heap is empty
bool BinaryHeap::is_empty() {
    if (heap_vertices.size() == 0)
        return true;
    return false;
}

void BinaryHeap::insert(Vertex v) {
    // insert new vertex into heap
    heap_vertices.push_back(v);
    int index = heap_vertices.size()-1;
    Vertex temp;

    // Fix the min heap property if it is violated
    while (index != 0 && heap_vertices[(index-1)/2].get_distance() > heap_vertices[index].get_distance()) {
        temp = heap_vertices[(index-1)/2];
        heap_vertices[(index-1)/2] = heap_vertices[index];
        heap_vertices[index] = temp;
        index = (index-1)/2;
    }
}

void BinaryHeap::decrease_key_val(Vertex v) {
    // First, find vertex v
    int searched = search(v.get_city());
    // Change distance of vertex in heap
    heap_vertices[searched].set_distance(v.get_distance());
    
    int i = searched;
    Vertex temp;

    // Fix the min heap property if it is violated
    while (i != 0 && heap_vertices[(i-1)/2].get_distance() > heap_vertices[i].get_distance()) {
        temp = heap_vertices[(i-1)/2];
        heap_vertices[(i-1)/2] = heap_vertices[i];
        heap_vertices[i] = temp;
        i = (i-1)/2;
    }
}

int BinaryHeap::search(std::string city_name) {
    for (int i = 0; i < heap_vertices.size(); i++) {
        if (heap_vertices[i].get_city() == city_name) {
            return i;
        }
    }
    return -1;
}

int BinaryHeap::get_size() {
    return heap_vertices.size();
}
