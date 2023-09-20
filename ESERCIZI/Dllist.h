#ifndef DLLIST
#define DLLIST

template<typename T>
class DLList {
	DLNode<T> *head;
	DLNode<T> *tail;
	
	public:
	
	DLList() {
		head = nullptr;
		tail = nullptr;
	}
	
	bool isEmpty() {
		return (head == nullptr) && (tail == nullptr);
	}
	
	void insertHead(T val) {
		if(this->isEmpty()) {
			head = new DLNode(val);
			tail = head;
			return;
		}
		
		DLNode<T> *toInsert = new DLNode<T>(val);
		toInsert->next = head;
		head->prev = toInsert;
		head = toInsert;
	}
	
	void insertTail(T val) {
		if(this->isEmpty()) {
			this->insertHead(val);
			return;
		}
		
		DLNode<T> *toInsert = new DLNode<T>(val);
		toInsert->prev = tail;
		tail->next = toInsert;
		tail = toInsert;
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
		
		Node<T> *toInsert = new DLNode<T>(val);
		toInsert->next = ptr->next;
		ptr->next = toInsert;
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
		
		Node<T> *toInsert = new DLNode<T>(val);
		toInsert->next = ptr->next;
		ptr->next = toInsert;
	}
	
	void removeHead() {
		if(this->isEmpty()) {
			std::cout << "Empty list" << std::endl;
			return;
		}
		
		if(head == tail) {
			DLNode<T> *ptr = head;
			head = nullptr;
			tail = nullptr;
			delete ptr;			
		}
		
		DLNode<T> *ptr = head;
		ptr->next->prev = nullptr;
		head = ptr->next; //head->next
		
		delete ptr;
	}

    void removeHead() {
		if(this->isEmpty()) {
			cout << "Empty list!" << endl;
			return;
		}
		
		DLNode<T> *ptr = head;
		ptr->prev = nullptr;
		head = ptr->next; 
		
		delete ptr;
	}
	
	void removeTail() {
		if(this->isEmpty()) {
			std::cout << "Empty list" << std::endl;
			return;
		}
		
		if(head == tail) {
			DLNode<T> *ptr = head;
			head = nullptr;
			tail = nullptr;
			delete ptr;			
		}
		
		DLNode<T> *ptr = tail;
		ptr->prev->next = nullptr;
		tail = ptr->prev; //tail->prev
		
		delete ptr;
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
		
		DLNode<T> *cur = head;
		DLNode<T> *prev = nullptr;
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
	}
};

#endif