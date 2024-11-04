#include <iostream>
#include "BST.h"

int main(){
    BinarySearchTree<int> bst;
    bst.insert(9);
    bst.insert(6);
    bst.insert(12);
    bst.insert(2);
    bst.insert(7);
    bst.insert(13);
    bst.insert(20);
    bst.insert(1);

    bst.printTree();

    std::cout<<"Tree after removing 1:"<<std::endl;
    bst.remove(1);
    bst.printTree();

    std::cout<<"Tree after removing 6:"<<std::endl;
    bst.remove(6);
    bst.printTree();

    std::cout<<"Tree after removing 12:"<<std::endl;
    bst.remove(12);
    bst.printTree();

    std::cout<<std::endl;
    bst.insert(12);
    bst.insert(11);
    bst.printTree();
    std::cout<<"Tree after removing 9:"<<std::endl;
    bst.remove(9);
    bst.printTree();

    std::cout<<"Tree after removing 12:"<<std::endl;
    bst.remove(12);
    bst.printTree();

    return 0;
}