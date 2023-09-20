#include <iostream>
#include <cmath>

using namespace std;

int* numeriprimi_1(int n){
    int *array=new int [n];
    for(int i=0; i<n; i++){
    	array[i]=0;
	}
    for(int i=2; i<=n; i++){
        bool is_prime = true;
        for(int j=2; j<n; j++){
            if (i%j == 0)
                is_prime = false;
                break;
        }
        if(is_prime) 
            array[i]=i;
    }
    return array;
}

void crivello(int n){
    int array[n-1];

    for(int i=0; i<n-1; i++){
        array[i]=i+2;
    }

    for(int i=2; i<sqrt(n); i++){
        for(int j=0; j<n-1; j++){
            if(array[j]%i == 0 && array[j] != 0){
                array[j] = 0;
            }
        }
    }
    
    int *array1=new int [n];
	array1=numeriprimi_1(n);
    
    cout<< "2" << endl;
    for(int i=0; i<sqrt(n); i++){
    	if(array1[i] != 0)
    		cout<< array1[i] << endl;
	}
    
	
    for(int i=0; i<n; i++){
        if(array[i] != 0)
            cout << array[i] << endl;
    }
}

int main(){
    
    crivello(100);
}