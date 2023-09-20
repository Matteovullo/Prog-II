#include <iostream>

using namespace std;

template <class T1, class T2>
class A{
    private:
        T1 var1;
        T2 var2;

    public:
        A(T1 var1, T2 var2){
            this->var1=var1;
            this->var2=var2;
        }
        T1 getVar1(){
            return var1;
        }
        T2 getVar2(){
            return var2;
        }
        void setVar1(T1 var1){
            this->var1=var1;
        }
        void setVar1(T2 var2){
            this->var2=var2;
        }
        void stampa(){
            cout << "var1=" << var1 << ", var2=" << var2 << endl; 
        }
};

int main(){
    A<int, int> obj(5, 7);
    obj.stampa();
}