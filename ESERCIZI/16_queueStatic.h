#ifndef QUEUESTATIC_H
#define QUEUESTATIC_H

#define MAX_SIZE 100
#include <iostream>

/* 
   ***************************
   *  STATIC CIRCULAR QUEUE  *
   ***************************
*/

template <typename T>
class StaticQueue{
     private:
      T* array;
      int size = 0;
      int maxSize = MAX_SIZE;

      int head = 0;
      int tail = -1;
     public:
      StaticQueue(int _maxSize = MAX_SIZE) : maxSize(_maxSize) {
          this->array = new T[maxSize];
      }
      
      bool isEmpty() const{  return size == 0; }

      void enqueue(T val){
          if(size == maxSize){ //raggiunta dimensione max
            std::cerr << "ERROR, Queue IS FULL!\n\n";
            return;
          }
          
          tail = ++tail % maxSize; 
          array[tail] = val;
          size++;
      }

        T dequeue(){
          if(this->isEmpty()){
            std::cerr << "ERROR, EMPTY Queue!" << std::endl << std::endl;
            return 0;
          }
          
          T val = array[head];
          head = (++head % maxSize);
          size--;
          return val;
      }
      
      friend std::ostream& operator <<(std::ostream& out, const StaticQueue<T>& q){
         
         if(!q.isEmpty()){
            out << "Queue head = " << q.head << ", Queue tail = " << q.tail 
                << ", size = " << q.size << " ---->" << std::endl;
            
            for(int i = q.head, count = 0; count < q.size; count++){
              out << "\t\t" << "q[" << i << "] = " << q.array[i] << std::endl;
              i = (i+1) % q.maxSize;
            }
         }
         else{
            out << "Queue EMPTY!" << std::endl;
         }

         return out;
     }
      
};


#endif