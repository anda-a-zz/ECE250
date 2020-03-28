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
public:
    Vertex(int key);
    std::vector<Vertex> adjacent();
    int key();
    void setKey(int k);
    Vertex parent();
    void setParent(Vertex p);
private:
    int key_value;
};

#endif /* vertex_h */
