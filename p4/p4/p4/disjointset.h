//
//  disjointSet.h
//  p4
//
//  Created by Anda Achimescu on 2020-03-25.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef disjointset_h
#define disjointset_h

#include <vector>

class DisjointSet {
public:
    DisjointSet();
    ~DisjointSet();
    void make_set(int x);
    int find_set(int x);
    void union_sets(int x, int y);
    void size(int n);
    void print();
    
private:
    std::vector<int> rank;
    std::vector<int> parent;
    int max_size;
};

#endif /* disjointset_h */

