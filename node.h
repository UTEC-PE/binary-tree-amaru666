//
// Created by jaox on 9/27/18.
//

#ifndef ARBOLES_NODE_H
#define ARBOLES_NODE_H
#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int a);
};
Node::Node(int a) {
    this->data = a;
    this->parent=this->left=this->right= nullptr;
}
#endif //ARBOLES_NODE_H
