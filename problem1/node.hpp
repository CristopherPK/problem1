//
//  node.hpp
//  problem1
//
//  Created by Cristopher Freitas on 7/27/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Node {
    bool visited;
    int first; // first is the n of canibals.
    int second; // second is the n of missionaries.
    int cost; // actual cost to get here.
    Node * prev;
    
public:
    Node(int first, int second);
    Node(const Node & other);
    int setParent(Node * prev);
    Node * getParent();
    int getFirst();
    int getSecond();
    void setCost(int cost);
    int getCost();
    string toString();
    int h();
    void visit();
    bool isVisited();
};

#endif /* node_hpp */
