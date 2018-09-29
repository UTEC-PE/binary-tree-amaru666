//
// Created by jaox on 9/27/18.
//

#ifndef ARBOLES_ITERATOR_H
#define ARBOLES_ITERATOR_H

#include "node.h"

class Iterator {
private:
    Node* current;
public:

    Node* minimum(Node* node){
        while (node->left != nullptr) node = node->left;
        return node;
    }
    Iterator(){
        current = nullptr;
    }
    Iterator(Node * node){
        current = node;
    }
    Iterator operator= (Iterator node){
        current = node.current;
        return *this;
    }
    bool operator!= (Iterator other){
        return current!=other.current;
    }
    Iterator operator++(){
        if(current->right != nullptr) {
            current = minimum(current->right);
            return *this;
        }
        Node *tmp = current;
        Node *y = tmp->parent;
        while(y!= nullptr && tmp == y->right){
            tmp = y;
            y = y->parent;
        }
        current= y;
        return *this;
    }
    int operator*(){
        return this->current->data;
    }
};


#endif //ARBOLES_ITERATOR_H
