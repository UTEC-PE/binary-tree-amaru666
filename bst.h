//
// Created by jaox on 9/27/18.
//

#ifndef ARBOLES_BST_H
#define ARBOLES_BST_H

#include "iterator.h"

class BinaryTree{
public:
    Node* root;
    BinaryTree();
    // No debería necesitar el root en el insert
    // Tu inserta acepta repetidos, no está mal pero hay elementos que no está insertando
    Node* insert(int data, Node* &node);
    Node* search(int data, Node* node);
    Node* minimum(Node* node);
    Node* maximum(Node* node);
    void InOrder(Node* node);
    int successor(int value);
    void Transplant(Node *u, Node *v);
    void delete_node(int value);
    Iterator begin() {
        return Iterator(minimum(root));
    }
    Iterator end() {
        return Iterator(maximum(root));
    }

    //Falta el destructor
};
void BinaryTree::delete_node(int value) {
    Node * node_ = search(value,this->root);
    if(node_){
        if(node_->left == nullptr) Transplant(node_,node_->right);
        else if(node_->right == nullptr) Transplant(node_, node_->left);
        else {
            Node * y = minimum(node_->right);
            if(y->parent != node_){
                Transplant(y,y->right);
                y->right = node_->right;
                y->right->parent = y;
            }
            Transplant(node_,y);
            y->left = node_->left;
            y->left->parent = y;
        }
    } else {
        cout<<"value not found in our tree";
    }
}
void BinaryTree::Transplant(Node *u, Node *v) {
    if(u->parent == nullptr) this->root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    if (v != nullptr) v->parent = u->parent;
}
int BinaryTree::successor(int value) {
    Node * tmp = search(value,root);
    if(tmp == nullptr) return -1;
    else {
        if (tmp->right != nullptr) {
            return minimum(tmp->right)->data;
        }
        Node *y = tmp->parent;
        while(y!= nullptr && tmp == y->right) {
            tmp = y;
            y = y->parent;
        }
        return y->data;
    }
}
void BinaryTree::InOrder(Node *node) {
    if (node != nullptr) {
        InOrder(node->left);
        cout<<node->data<<" ";
        InOrder(node->right);
    }
}
BinaryTree::BinaryTree() {
    root= nullptr;
}
Node* BinaryTree::insert(int data, Node *&node) {
    if (node == nullptr) node = new Node(data);
    else if (node->data > data){
        node->left = insert(data, node->left);
        node->left->parent = node;
    } else {
        node->right = insert(data, node->right);
        node->right->parent = node;
    }
    return node;
}
Node* BinaryTree::search(int data, Node *node) {
    if(node == nullptr || data == node->data) return node;
    if(data<node->data) return search(data,node->left);
    else return search(data,node->right);
}
Node* BinaryTree::maximum(Node *node) {
    while (node->right != nullptr) node=node->right;
    return node;
}
Node* BinaryTree::minimum(Node *node) {
    while (node->left != nullptr) node=node->left;
    return node;
}


#endif //ARBOLES_BST_H
