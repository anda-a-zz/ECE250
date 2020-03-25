//
//  disjointSet.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef disjointSet_h
#define disjointSet_h

class disjointSet {
public:
    setID makeSet(vertex x);
    setID findSet(vertex x);
    void union(vertex x, vertex y);
private:
}

#endif /* disjointSet_h */
