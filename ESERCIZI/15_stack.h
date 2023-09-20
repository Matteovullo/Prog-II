#ifndef STACK_H
#define STACK_H

/* 
   ***************************
   *          PILA           *
   ***************************
*/

#include <iostream>
#include "13_list.h"
#include "13_node.h"

//STACK 
template <typename T>
class Stack : protected List<T>{  //utilizziamo la classe Lista per implementare lo stack
    private: 
     int size = 0;
    public:
     Stack() : List<T>() {}
     
     bool isEmpty() const{
           return size == 0;
     }

     Node<T>* top() const{ 
         if(this->isEmpty()){
          std::cerr << "ERROR, Stack EMPTY!\n\n";   
          return nullptr;
         }
         
         return List<T>::getHead();
     }

     void push(T val){
         List<T>::insertHead(val);
         size++;
     }

     Node<T>* pop(){
          if(this->isEmpty())
           return nullptr;

          Node<T>* ptr = top();
          List<T>::removeHead();
          size--;
          return ptr; 
     }

     friend std::ostream& operator <<(std::ostream& out, const Stack<T>& s){
         //out << (List<T>)s; //cast per chiamare overload di superclasse
         
         if(!s.isEmpty()){
            out << "Stack top = " << s.top() << ", size = " << s.size 
                << " --->" << std::endl;

            Node<T>* ptr = s.getHead();
            while(ptr){   
              out << "\t [ " << *ptr << " ]" << std::endl;
              ptr = ptr->getNext();
            }

         }
         else{
            out << "Stack EMPTY!" << std::endl;
         }

         return out;
     }
}; 

// N.B. Nel contesto ereditario la friendship non viene ereditata, quindi ex:
//      - std::cout << List<T>::getHead()->val; --> ERRORE (attributo val di Node è private)

#endif