//
//  priorityqueue.hpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-15.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef priorityqueue_h
#define priorityqueue_h

#include <stdio.h>
#include <vector>
#include "binaryheap.h"

class PriorityQueue {
public:
    PriorityQueue();                // constructor
    PriorityQueue(vector<Vertex> S);
    void init(vector<Vertex> S);    //runs once in O(V)
    void modify_key(Vertex v);
    Vertex extract_min();
    bool is_empty();
    bool search(std::string city_name);
    
private:
    BinaryHeap heap;
};

#endif /* priorityqueue_h */
