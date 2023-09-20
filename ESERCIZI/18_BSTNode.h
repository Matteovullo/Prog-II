#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

template<typename T>
class BSTNode{
    protected:
     T key;
     BSTNode<T>* left;
     BSTNode<T>* right;
     
     template<typename U>
     friend class BST;
    public:
     BSTNode(T _key) : key(_key), left(nullptr), right(nullptr) { }

     /* //DA RIVEDERE, FORSE NON SERVE ED É INUTILE
     ~BSTNode(){ //rottura albero, devo eliminare i suoi figli
         delete left;
         delete right; 
     }*/ 
     
     void setKey(T key){ 
         this->key = key;
     }

     void setLeft(BSTNode<T>* left){
        this->left = left;
     }  

     void setRight(BSTNode<T>* right){
        this->right = right;
     }
     
     T getKey(){ return key; }

     BSTNode<T>* getLeft(){ return this->left; }

     BSTNode<T>* getRight(){ return this->right; }
     
     friend std::ostream& operator<<(std::ostream& out, const BSTNode<T>& node){
         out << "BSTNode@" << &node << ", key = " << node.key 
             << ", left = " << node.left << ", right = " << node.right;
         
         return out;
     }
};

#endif