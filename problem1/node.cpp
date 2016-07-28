//
//  node.cpp
//  problem1
//
//  Created by Cristopher Freitas on 7/27/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#include "node.hpp"

Node::Node(int first, int second){
    this->first = first;
    this->second = second;
}

Node::Node(const Node & other){
    Node * n = new Node(other.first, other.second);
    n->setParent(other.prev);
    n->setCost(other.cost);
}

int Node::setParent(Node *prev){
    this->prev = prev;
    return 0;
}

Node * Node::getParent(){
    return this->prev;
}

int Node::getFirst(){
    return this->first;
}

int Node::getSecond(){
    return this->second;
}

void Node::setCost(int cost){
    this->cost = cost;
}

int Node::getCost(){
    return this->cost;
}

int Node::h(){
    return this->cost + this->getFirst() + this->getSecond();
}

string Node::toString(){
    string s =  "(" + to_string(this->first) + "," + to_string(this->second) + ")";
    return s;
}

void Node::visit(){
    this->visited = true;
}

bool Node::isVisited(){
    return this->visited;
}