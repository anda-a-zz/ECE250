//
//  vertex.hpp
//  p5
//
//  Created by Anda Achimescu on 2020-04-14.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef vertex_h
#define vertex_h

#include <stdio.h>
#include <vector>

using namespace std;

class Vertex {
public:
    int get_keyd();
    void set_keyd(int k);
    Vertex *get_parent();
    void set_parent(Vertex p);
    vector<Vertex> adjacent();
private:
    Vertex *parent;
};

#endif /* vertex_h */
