#ifndef STATICKSTACK_H
#define STATICKSTACK_H

#include <iostream>

/* 
   ***************************
   *      PILA STATICA       *
   ***************************
*/

template <typename T>
class StaticStack{
   private:
    T* array;
    int top = -1;
    int maxSize;
   public:
    StaticStack(int _maxSize) : maxSize(_maxSize) { 
        array = new T[maxSize];
    }
    
    bool isEmpty() const{
        return top == -1;
    }

    T getTop() const{
         if(this->isEmpty()){
          std::cerr << "ERROR, Stack EMPTY!\n\n";  
          return -1;
         }

         return array[top];
    }

    void push(T val){
         if(top == maxSize-1){ //raggiunta dimensione max
           std::cerr << "ERROR, Stack OVERFLOW!\n\n";
           return;
         }

         array[++top] = val;
    }

    T pop(){
        if(this->isEmpty()){
          std::cerr << "ERROR, Stack EMPTY!\n\n";  
          return -1;
        }

        return array[top--];
    }
    
    friend std::ostream& operator <<(std::ostream& out, const StaticStack<T>& s){
         if(!s.isEmpty()){
            out << "Static Stack: maxSize = " << s.maxSize << ", top = " << s.getTop() 
                << " ----> " << std::endl;
            
            for(int i = s.top; i >= 0; i--)
            out << "\t\t" << s.array[i] << std::endl;
         }
         else{
            out << "Stack EMPTY!" << std::endl;
         }

         return out;   
    }

};

#endif