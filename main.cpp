#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int a);
};
Node::Node(int a) {
    this->data = a;
    this->left=this->right= nullptr;
}
class BinaryTree{
public:
    Node* root;
    BinaryTree();
    Node* insert(int data, Node* &node);
    Node* search(int data, Node* node);
    Node* minimum(Node* node);
    Node* maximum(Node* node);
    void InOrder(Node* node);
};
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
    else if (node->data > data) node->left = insert(data, node->left);
    else node->right = insert(data, node->right);
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

int main() {

    BinaryTree mytree = BinaryTree();
    mytree.insert(5,mytree.root);
    mytree.insert(5,mytree.root);
    mytree.insert(4,mytree.root);
    mytree.insert(2,mytree.root);
    mytree.insert(1,mytree.root);
    mytree.insert(6,mytree.root);
    mytree.insert(0,mytree.root);
    mytree.insert(3,mytree.root);
    Node* find = mytree.search(4,mytree.root);
    cout<<find->data<<"\n";
    Node* max = mytree.maximum(mytree.root);
    cout<<max->data<<"\n";
    Node* min = mytree.minimum(mytree.root);
    cout<<min->data<<"\n";
    mytree.InOrder(mytree.root);

    return 0;
}