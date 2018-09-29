#include "bst.h"

int main() {

    BinaryTree mytree = BinaryTree();
    mytree.insert(30,mytree.root);
    mytree.insert(21,mytree.root);
    mytree.insert(60,mytree.root);
    mytree.insert(19,mytree.root);
    mytree.insert(28,mytree.root);
    mytree.insert(54,mytree.root);
    mytree.insert(73,mytree.root);
    mytree.InOrder(mytree.root);
    cout<<"\n";

    for(Iterator it = mytree.begin(); it != nullptr; ++it)
        cout<<*it<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    mytree.delete_node(30);
    for(Iterator it = mytree.begin(); it != nullptr; ++it)
        cout<<*it<<endl;

    return 0;
}