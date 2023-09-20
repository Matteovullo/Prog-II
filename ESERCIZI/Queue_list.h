#ifndef QUEUE_LIST.H
#define QUEUE_LIST.H

template<class T>
class Queue : protected List{
    private:
        int size = 0;

    public:
        Queue() : List<T>() {}

        bool isEmpty() {
		    return size == 0;
	    }

        Node<T>* enqueue(){
            Node<T>* ptr = head;
            List<T>::insertTail();
            size++;
            delete ptr;
		}

        Node<T>* dequeue(){
            if(isEmpty()) {
			    return;
            }

            Nnode<T>* ptr = Dlist<T>::head;
            List<T>::removeHead();
            size--;
            delete ptr;
        }

        friend std::ostream& operator<<(std::ostream& out, Queue<T> s) {
		    return out << (List<T>)s;
	    }
};

#endif