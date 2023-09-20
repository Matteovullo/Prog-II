#ifndef STACK_H
#define STACK_H

#include "List.h"
#include <iostream>


template<typename T>
class Stack : protected List<T> {
	
	int size = 0;
	
	public:
	
	Stack() : List<T>() {}
	
	bool isEmpty() {
		return size == 0;
	}

	int getSize(){
		return size;
	}
	
	Node<T> * top() {
		if(isEmpty())
			return nullptr;
		
		return List<T>::getHead();
	}
	
	void push(T val) {
		List<T>::insertHead(val);
		size++;
	}
	
	Node<T>* pop() {
		if(isEmpty())
			return nullptr;
		
		Node<T>* ptr = top();
		List<T>::removeHead();
		size--;
		return ptr;
	}
	
	friend std::ostream& operator<<(std::ostream& out, Stack<T> s) {
    	for(int i=0; i<getSize(); i++){
			out << "Element=" << i << "/t" ;
			out << (List<T>)s; 
		}
		return out;
	}
	
};

#endif