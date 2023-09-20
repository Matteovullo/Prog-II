#ifndef BST_H
#define BST_H

#include <iostream>
#include "18_BSTNode.h"

template<typename T>
class BST{
     protected:
      BSTNode<T>* root;
     public:
      BST() : root(nullptr) { }

      bool isEmpty(){ return root == nullptr; }
      
      // procedura di inserimento ricorsiva con due parametri:
      // - radice di sottoalbero;
      // - valore (key).
      void insert(BSTNode<T>* ptr,T key){
         if(key <= ptr->key){
           if(!ptr->left){ // se ptr non ha figli sinistri (caso base)
              ptr->left = new BSTNode<T>(key); // aggiungi nodo come figlio sinistro 
              return;
           }

           insert(ptr->left,key); // passo ricorsivo
         }
         else{
           if(!ptr->right){
              ptr->right = new BSTNode<T>(key); 
              return;
           }

           insert(ptr->right,key);
         }

         if(ptr->left == nullptr && key <= left){
           
         }
      }

      void insert(T key){
          if(this->isEmpty()){
              root = new BSTNode<T>(key);
              return;
          }

          insert(root,key);
      }
      
      void visit(BSTNode<T>* node){ // stampa
          std::cout << *node <<std::endl;
      }
     
      void inOrder(BSTNode<T>* ptr){ 
          if(ptr == nullptr){
            return;
          }
        
          inOrder(ptr->left);
          visit(ptr);
          inOrder(ptr->right);
      }

      // VISIT IN ORDER 
      void inOrder(){ 
          inOrder(this->root);
      }
};

#endif