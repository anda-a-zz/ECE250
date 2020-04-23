//
//  priorityqueue.cpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-15.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#include "priorityqueue.h"

// constructor
PriorityQueue::PriorityQueue() {
    
}

PriorityQueue::PriorityQueue(vector<Vertex> S) {
    heap.initialize(S);
}

//runs once in O(V)
void PriorityQueue::init(vector<Vertex> S) {
    heap.initialize(S);
}

// modify the existing vertex to have a new distance
void PriorityQueue::modify_key(Vertex v) {
    heap.insert(v);
}

// returns minimum distance and removes from PQ
// in O(lg V) time
Vertex PriorityQueue::extract_min() {
    return heap.del_min();
}

bool PriorityQueue::is_empty() {
    return heap.is_empty();
}

bool PriorityQueue::search(std::string city_name) {
    return heap.search(city_name);
}

// get the size of the priority queue
int PriorityQueue::get_size() {
    return heap.get_size();
}
