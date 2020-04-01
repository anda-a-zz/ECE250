//
//  vertex.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef vertex_h
#define vertex_h

class Vertex {
    friend class Node;
public:
    Vertex();
    Vertex(int key);
    int get_key();
    int get_parent();
    void set_key(int k);
    void set_parent(int p);
private:
    int key_value;
    int parent;
};

#endif /* vertex_h */
