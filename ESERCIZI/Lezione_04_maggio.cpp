#include <iostream>

using namespace std;

class A{
    public:

    A(){
        cout << "costruttore di A" << endl;
    }
    void stampa(){
        cout << "sono la classe A" << endl;
    }
};

class B: public A{
    public:

    B(){
        cout << "costruttore di B" << endl;
    }
    void stampa(){
        cout << "sono la classe B" << endl;
    }
};

template <typename T> void swap(T var1, T var2){
    T temp=var1;
    var1=var2;
    var2=temp;
}

int main(){
    A a;
    B b;

    a.stampa();
    b.stampa();

    A& ra=a;
    A& rb=b;

    ra.stampa();
    rb.stampa();

    A *pa=&a;
    A *pb=&b;

    pa->stampa();
    pb->stampa();
    
    int a=1, b=2;
    swap(a, b);
}