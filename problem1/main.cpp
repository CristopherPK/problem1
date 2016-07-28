//
//  main.cpp
//  problem1
//
//  Created by Cristopher Freitas on 7/27/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#include <iostream>
#include <vector>

#include "node.hpp"

using namespace std;

Node * travel(vector<Node * > nodes, int direction){
    vector<Node *>::iterator itn = nodes.begin();
    Node * node = NULL;
    
    while(itn != nodes.end()){
        int c1,c2, m1,m2;
        
        if(direction == 0){
            c2 = (*itn)->getFirst();
            m2 = (*itn)->getSecond();
            c1 = (*itn)->getParent()->getFirst();
            m1 = (*itn)->getParent()->getSecond();
        } else {
            c1 = (*itn)->getFirst();
            m1 = (*itn)->getSecond();
            c2 = (*itn)->getParent()->getFirst();
            m2 = (*itn)->getParent()->getSecond();
        }
        
        // c1 >= c2
        if(c1 >= c2){
            // m1 >= m2
            if(m1 >= m2){
                // 1<= (c1 + m1) - (c2 + m2) <= 2
                int cond = (c1 + m1) - (c2 + m2);
                if(cond == 1 || cond == 2){
                    if(node == NULL){
                        node = *itn;
                    } else if(node->h() >= (*itn)->h()){
                        if(!(*itn)->isVisited()){
                            node = *itn;
                            node->visit();
                        }
                    }
                }
            }
        }
        
        itn++;
    }
    
    return node;
}

bool isValid(Node * node){
    
    bool result = false;
    
    if(node->getFirst() >= 0 && node->getFirst() <= 3){
        if(node->getSecond() >= 0 && node->getSecond() <= 3){
            if((node->getFirst() == node->getSecond()) ||
               node->getSecond() == 0 || node->getSecond() == 3){
                result = true;
            }
        }
    }
    
    return result;
}

bool isResult(Node * node){
    if(node->getFirst() == 0 && node->getSecond() == 0){
        return true;
    } else {
        return false;
    }
}

vector<Node *> getBack(Node * node, int cost){
    vector<Node *> childs;
    
    int c = node->getFirst();
    int m = node->getSecond();
    
    int operation = 3;
    
    Node * n = NULL;
    while(operation > 0){
        switch(operation){
            case 1:
                n = new Node(c,m+1);
                break;
            case 2:
                n = new Node(c+1,m);
                break;
            case 3:
                n = new Node(c+1,m+1);
                break;
        }
        if(isValid(n)){
            n->setParent(node);
            n->setCost(cost+1);
            childs.push_back(n);
            n = NULL;
        } else {
            n = NULL;
        }
        operation--;
    }
    
    return childs;
}

vector<Node *> getNext(Node * node, int cost){
    vector<Node *> childs;
    
    int c = node->getFirst();
    int m = node->getSecond();
    
    int operation = 5;
    
    Node * n = NULL;
    while(operation > 0){
        switch(operation){
            case 1:
                n = new Node(c,m-1);
                break;
            case 2:
                n = new Node(c-1,m);
                break;
            case 3:
                n = new Node(c-2,m);
                break;
            case 4:
                n = new Node(c,m-2);
                break;
            case 5:
                n = new Node(c-1,m-1);
                break;
        }
        if(isValid(n)){
            n->setParent(node);
            n->setCost(cost+1);
            childs.push_back(n);
            n = NULL;
        } else {
            n = NULL;
        }
        operation--;
    }
    
    return childs;
}

int main(int argc, const char * argv[]) {
    
    // start the root with left side
    Node * root = new Node(3,3);
    root->setParent(NULL);
    root->setCost(0);
    
    cout << root->toString() << endl;
    
    vector<Node *> nodes;
    while(true){
        // Forward step
        nodes = getNext(root, root->getCost());
        root = travel(nodes,0);
        if(root == NULL){
            cout << "Solution not found." << endl;
            break;
        }
        cout << root->toString() << endl;
        
        if(isResult(root)) break;
        
        // Backward step
        nodes = getBack(root, root->getCost());
        root = travel(nodes,1);
        if(root == NULL){
            cout << "Solution not found." << endl;
            break;
        }
        
        cout << root->toString() << endl;
        if(isResult(root)) break;
    }
    
    // cout << root << endl;
    // create the tree
    
    return 0;
}
