#ifdef STATIC_QUEUE
#define STATIC_QUEUE

#define MAX_SIZE 1000

#include <iostream>

template<typename T>
class StaticQueue{
    T* array;
    int size=0;
    int maxSize=MAX_SIZE;

    int head=0;
    int tail=-1;

    public:

    StaticQueue(int maxSize = MAX_SIZE) : maxSize(maxSize){
        this->array = new T [maxSize];
    }

    void enqueue(T val){
        if(size == maxSize){
            cout<<"Queue is full"<<endl;
            return ;
        }
        if(head==-1){
            head=0;
        }

        array[tail] = val;
        size++;
    }

    T dequeue(){
        if(size == 0){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        T val=array[head];
        head = (++head % maxSize)
        size--;
        return val;
    }

    friend ostream& operator<<(ostream& out, StaticQueue<T> queue){
        if(queue.size == 0){
            return out<<"Queue is empty"<<endl;
        }
        out<<"Static queue - size="<<queue.size<<", maxSize=" <<queue.maxSize<<endl;
        
        for(int i=queue.head,count =0;cout<queue.size; count++){
            out<<queue.array[i]<<endl;
            i = (i+1) % queue.maxSize;
        }

        return out;        
        }

};

#endif