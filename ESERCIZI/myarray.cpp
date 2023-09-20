#include <iostream>

using namespace std;


template <typename T> 
class Myarray{
    private:
        int DIM=0;
        T* array;

    public:
        Myarray(int a) : DIM(a) {
            array= new T[DIM];
        }
        T at(int a){
            return array[a];
        }
        void at(int a, T val){
            array[a]=val;
        }
        int size(){
            return DIM;
        }
        T* getPointer(){
            return array[0];
        }
        void copy(Myarray<T> *dst){
            for(int i=0; i<DIM; i++){
                dst.at(i, this->arrai[i]);
            }
        }
};