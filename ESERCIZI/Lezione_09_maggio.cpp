#include <iostream>

using namespace std;

template<class T>
class Nodo{
    private:
        T val;
        Nodo<T>* next;

        template<Typename U>
        friend class List;
    
    public:
        Nodo(T val){
            this->val=val;
            next=nullptr;
        }

        Nodo<T> *getHead() const {
            return head;
        }

        Nodo<T>* getNext() const {
            return this->next;
        }

        friend ostrema& oprator<<(ostream& out, Node<T> &node){
            out << "node val="<<node.val<<"-next="<<node.next;
            return out;
        }
};

template<class T>
class List{
    private:
        Nodo* head;

    public:
        List(){}

        isEmpty(){
            return head == nullptr;
        }

        void insert(T val){
            if(this->isEmpty()){
                head = new Node<T>(val);
            }
        }

        void insertHead(T val){
            if(this->isEmpty()){
                this->insert(val);
                return;
            }

            Node<T>* temp=new Nodo<T>(val);
            temp->next=head;
            this->head=temp;
        }

        void insertTall(T val){
            if(this->isEmpty()){
                this->insertHead(val);
                return;
            }
            Node<T>* ptr=head;
            while(ptr->getNext != nullptr){
                ptr=ptr->getNext();
            }
            Node<T>* temp=new Node<T>(val);
            ptr->ptr
        }

        friend ostrema& oprator<<(ostream& out, Node<T> &node){
            out << "List head="<<node.val<<endl;
            Node<T> *ptr=head;
            while(ptr != nullptr){
                out << "\t" <<*ptr<<endl;
                ptr=ptr->getNext();
            }
            return out;
        }

        void remove(T val){
            if(this->isEmpty()){
                this->insertHead(val);
                return;
            }
            Node<T>* ptr=head;
            while(ptr->getNext != nullptr){
                
            }
        }

};

int main(){

    List<int>lista;
    lista.insertHead(10);
    lista.insertHead(4);
    lista.insertHead(-19);

}