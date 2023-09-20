#include <iostream>
using namespace std;

int boo(int& n){
    int a=0;
    for(;n>0;n--)
    a+=n;
    return a;
}

template<typename T>
void fun(const T& x){
    static int count=0;
    cout << "x = " << x << "count = " << count << endl;
    ++count;
    return;
}

int main(){
    /*char str1[]={'C', 'i', 'a', 'o'};
    char str2[]="Ciao";

    cout << sizeof(str1) << endl;
    cout << sizeof(str2) << endl;

    cout << endl;

    double mt[2][3]={1, 2, 3, 4, 5, 6};
    for(int f=0; f<2; f++){
        for(int c=0; c<3; c++){
            cout << *(*(mt+f)+c) << " ";
            cout << "\n";
        }
    }

    cout << endl;

    int n=3;
    int m=boo(n);
    cout << n*m;
    return 0;

    cout << endl;*/

    fun<int>(1);
    cout << endl;
    fun<int>(1);
    cout << endl;
    fun<double>(1.1);
    cout << endl;
}