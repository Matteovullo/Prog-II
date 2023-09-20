#include <iostream>

//binarySearch
//supponiamo che l'array sia già ordinato
bool ricercaBinaria(int array[], int n, int key) {
	bool found = false;
	
	//n/2 = (n-0)/2
	//int midpoint = n/2; //floor(n/2)
	int start = 0;
	int end = n;
	
	while(!found && (start != end)) {
			
		int midpoint = start + ((end-start)/2); // (start+end)/2
		
		std::cout << "start = " << start << ", end = " << end << ", midpoint = " << midpoint << std::endl;
		if(array[midpoint] == key) 
			found = true;
		else if(key < array[midpoint]) {
			//considerare la metà inferiore
			//aggiornare end e midpoint
			end = midpoint;
			//midpoint = (end-start)/2;
		}
		else {
			//considerare la metà superiore
			//aggiornare start e midpoint
			start=midpoint+1;
			//midpoint = (end-start)/2;
		}
		
		
	}
	//verificare ad ogni iterazione se key >= array[n/2]
	
	return found;
}

//Versione ricorsiva

int binarySearch(int vet[], int dim, int el)
{
    int startPos;
    int med = dim / 2;
    if (vet[med] == el)
        return med;
    if (med == 0)
        return -1;
    if (el < vet[med])
    {
        return binarySearch(vet, med, el);
    }
    else
    {
        startPos = med + 1;
        return startPos +
               binarySearch(&vet[startPos], dim - startPos, el);
    }
}

//Selection sort & inserction sort

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int array[], int n) {
	int indexMin;
	
	for(int i=0; i < n; i++) {
		indexMin = i;
		for(int j=i+1; j < n; j++) {
			if(array[j] < array[indexMin])
				indexMin = j;
		}
		
		swap(array[i], array[indexMin]);
	}
}

//Selection sort ricorsivo

void selectionSort(int array[], int n) {
	int indexMin;
	
	for(int i=0; i < n; i++) {
		indexMin = i;
		for(int j=i+1; j < n; j++) {
			if(array[j] < array[indexMin])
				indexMin = j;
                //selectionSort(array, n-1);
		}
		
		swap(array[i], array[indexMin]);
	}
}



void insertionSort(int array[], int n) {
	int temp, j;
	
	for(int i=1; i < n; i++) {
		temp = array[i];
		for(j=i; j > 0; j--) {
			if(temp < array[j-1])
				array[j] = array[j-1];
			else 
				break;
		}
		array[j] = temp;
	}
}

void printArray(int array[], int n) {
	
	for(int i=0; i < n; i++) {
		std::cout << array[i] << "\t";
	}
	std::cout << std::endl;
}


//Merge sort


//Quick sort

int main() {
	
	
	
	bool found = ricercaBinaria(array, 10, 4);
	
	std::cout << found << std::endl;

    std::cout << binarySearch(array, 10, 4) <<std::endl;
}