#ifndef QUEUE_H
#define QUEUE_H

#include "Dlist.h"
#include <iostream>

using namespace std;

template<typename T>
class Queue: protected Dlist<T>{
    private:
        int size = 0;

    public:
        Queue() : Dlist<T>() {}

        bool isEmpty() {
		    return size == 0;
	    }

        Dlnode<T>* enqueue(){
            Dlnode<T>* ptr = head;
            Dlist<T>::insertTail();
            size++;
            delete ptr;
		}

        Dlnode<T>* dequeue(){
            if(isEmpty()) {
			    return;
            }

            Dlnode<T>* ptr = Dlist<T>::head;
            Dlist<T>::removeHead();
            size--;
            delete ptr;
        }

        friend std::ostream& operator<<(std::ostream& out, Queue<T> s) {
		    return out << (Dlist<T>)s;
	    }

};

#endif