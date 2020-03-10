//
//  QuadTree.h
//  p3
//
//  Created by Anda Achimescu on 2020-03-04.
//  Copyright © 2020 Anda Achimescu. All rights reserved.
//

#ifndef quad_tree_h
#define quad_tree_h

class QuadTree {
public:
    QuadTree();
    ~QuadTree();
    void insert(QuadTree tree, CityInfo city_info);
    void search(double x, double y);
    void max_value();
    void min_value();
    void total();
    void print();
    void clear();
    void get_size();
    
private:
    Node *root;
    size_t tree_size;
};

#endif /* quad_tree_h */
