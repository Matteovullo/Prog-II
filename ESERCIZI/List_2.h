#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
class List {
	Node<T>* head;
    int dimensione=0;
    T *tail;
	
	public:
	
	List() {
		head = nullptr;
        dimesione++;
	}
	
	bool isEmpty() {
		return head == nullptr;
	}
	
	Node<T> *getHead() const { return head; }
	
	void insert(T val) {
		if(this->isEmpty()) {
			head = new Node<T>(val);
			return;
		}
        dimensione++;
	}
	
	void insertHead(T val) {	//O(1)
		Node<T> *temp = new Node<T>(val);   //(O)1
		temp->next = head;      //(O)1
		this->head = temp;      //(O)1
        dimesione++;            //(O)1
	}                           //tot (O)5
	
	void insertTail(T val) {    //O(1)+MAX(O(B1), O(B2))=O(3)
		if(this->isEmpty()) {
			this->insertHead(val);  //(O)1
			return;     //  (O)1
		}                       //TOT O(3)
		
		Node<T> * ptr = head;
		while(ptr->getNext() != nullptr) {
			ptr = ptr->getNext();
		}
		
		Node<T> * temp = new Node<T>(val);
		ptr->next = temp;
        tail = temp;	
        dimensione++;	
	}
	
	void insertInOrderC(T val) {
		
		if(this->isEmpty()) {
			this->insertHead(val);
			return;
		}
		if(val <= head->val) {
			this->insertHead(val);
			return;
		}
		
		Node<T> *ptr = head;
		while(ptr->getNext() && (val >= ptr->val)) {
			
			if(val <= ptr->next->val)
				break;
			
			ptr = ptr->getNext();
		}
		
		if(!(ptr->next)) {
			this->insertTail(val);
			return;
		}
		
		Node<T> *toInsert = new Node<T>(val);
		toInsert->next = ptr->next;
		ptr->next = toInsert;
		dimensione++;
	}

    void insertInOrderD(T val) {
		
		if(this->isEmpty()) {
			this->insertHead(val);
			return;
		}
		if(val >= head->val) {
			this->insertHead(val);
			return;
		}
		
		Node<T> *ptr = head;
		while(ptr->getNext() && (val >= ptr->val)) {
			
			if(val >= ptr->next->val)
				break;
			
			ptr = ptr->getNext();
		}
		
		if(!(ptr->next)) {
			this->insertTail(val);
			return;
		}
		
		Node<T> *toInsert = new Node<T>(val);
		toInsert->next = ptr->next;
		ptr->next = toInsert;
		dimensione++;
	}
	
	void removeHead() {
		if(this->isEmpty()) {
			cout << "Empty list!" << endl;
			return;
		}
		
		Node<T> *temp = head;
		head = head->next;
		
		delete temp;
        dimensione--;
	}
	
	void removeTail() {
		if(this->isEmpty()) {
			cout << "Empty list!" << endl;
			return;
		}
		
		Node<T> *cur = head;
		Node<T> *prev = nullptr;
		while(cur->next) {
			prev = cur;
			cur = cur->next;			
		}
		
		prev->next = nullptr;
		delete cur;
        while(!ptr->next()){
            tail = ptr->next;
        }        
        dimensione--;
	}
	
	void remove(T val) {
		
		if(this->isEmpty()) {
			cout << "Empty list!" << endl;
			return;
		}
		
		if(head->val == val) {
			this->removeHead();
			return;
		}
		
		Node<T> *cur = head;
		Node<T> *prev = nullptr;
		while(cur->next && cur->val != val) {
			prev = cur;
			cur = cur->next;
		}
		
		if(!(cur->next) && cur->val != val) {
			cout << "Element with value " << val << "not found" << endl;
			return;
		}
		
		prev->next = cur->next;
		delete cur;
        dimensione--;
	}
	
	friend ostream& operator<<(ostream& out, const List<T> &list) {
		out << "List head=" << list.head << endl;
		Node<T> *ptr = list.head;
		while(ptr != nullptr) {
			out << "\t" << *ptr << endl;
			ptr = ptr->getNext();
		}
		
		return out;
		
	}

    T &operator[](short indice){
        for(int i=0; i<dimensione; i++){
            Node<T> *ptr=list.head
            if(i == indice && ptr!=nullptr){
                return *ptr->getNext();
            }
        }
        return;
    }
};

#endif