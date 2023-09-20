#include <iostream>
 
using namespace std;

#include"bst.h"

int main(){
    BST<int> bst;
    bst.insert(5);
    bst.insert(1);
    bst.insert(7);
    bst.insert(10);
    bst.insert(4);
    BSTNode<int>* ptr=bst.search(10);
    cout << *bst.successor(ptr) << endl;
}