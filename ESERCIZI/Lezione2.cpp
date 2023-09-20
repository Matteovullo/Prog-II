#include <iostream>
#include <cmath>

#define MAX 100

using namespace std;
/*
void leggiElementi(double v[],int &num){
    num = 0;
    double temp;
    for(int i=0; i<MAX; i++){
        cout<< "Inserire un elemento. Inserire 0 per terminare l' inserimento: ";
        cin>> temp;
        if(temp == 0){
            break;
        }else{
            v[i]=temp;
            num++;
        }
    }
}

void stampaElementi(double v[], int num){
    for(int i=0; i<num; i++){
        cout<< "Elemento "<<i<<"-esimo "<<v[i]<<endl;
    }
}

void numeriprimi_1(int n){
    
    for(int i=2; i<=n; i++){
        bool is_prime = true;
        for(int j=2; j<i/2; j++){
            if (i%j == 0)
                is_prime = false;
                break;
        }
        if(is_prime) 
            cout << i << "is prime" << endl;
    }
}

void numeriprimi_1(int n){
    
    for(int i=2; i<=n; i++){
        bool is_prime = true;
        for(int j=2; j<sqrt(n); j++){
            if (i%j == 0)
                is_prime = false;
                break;
        }
        if(is_prime) 
            cout << i << "is prime" << endl;
    }
}
*/

int* numeriprimi_4(int n){
    
    int* array=new int[n];
    for(int i=2; i<=n; i++){
        bool is_prime = true;
        for(int j=2; j<i/2; j++){
            if (i%j == 0)
                is_prime = false;
                break;
        }
        if(is_prime){
        	if(i!=n)
            array[i]=i;
        }
        else{
        	if(i!=n)
            array[i]=0;
        }
    }
    return array;
}

void numeriprimi_3(int n){
    
    int array[n];
    int c;
    for(int i=2; i<n; i++){
        if(i%2 != 0)
        array[i]=i;
    }

    int* array2=numeriprimi_4(sqrt(n));
    for(int i=0; i<n; i++){
        if(array[i] != 0) 
            c++;
    }

    for(int i=3; i<c; i+=2){
        for(int j=0; j<n; j++){
            if(array[j]%i == 0){
                array[i]=0;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(array[i] != 0){
            cout << i << " è primo" << endl; 
        }
    }
    
}



int main(){
    //double array[MAX];
    //int num;
    //leggiElementi(array, num);
    //stampaElementi(array, num);
    int n=100;
    numeriprimi_3(n);
}