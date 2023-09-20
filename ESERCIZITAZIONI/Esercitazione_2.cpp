/*Dato un file contenente un elenco di utenti nel seguente formato
ID;COGNOME;NOME;POPOLARITA
ID;COGNOME;NOME;POPOLARITA
…
ID;COGNOME;NOME;POPOLARITA
Dove COGNOME e NOME sono stringhe e POPOLARITA è un double, implementare almeno due algoritmi 
di ordinamento tra quelli visti a lezione. Inoltre, sfruttando le librerie standard, valutarne la complessità 
temporale stimando il tempo di esecuzione*/

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>
#define MAX_N 2000

class User {
	private:
		unsigned int id;
		std::string surname;
		std::string name;
		double popularity;
			
		inline int compareTo(const User &other) {
			if(this->popularity > other.popularity)
				return 1;
			else if(this->popularity < other.popularity)
				return -1;
			else return 0;
		}
		
	public:
	
		User(unsigned int _id, std::string _surname, std::string _name, double _popularity) :
			id(_id), surname(_surname), name(_name), popularity(_popularity) {}
		
		User() : User(0, "", "", 0.0) {}
		
		friend std::istream &operator>>(std::istream &input, User &user) {
			std::string id_string, pop_string;
			std::getline(input, id_string, ';');
			std::getline(input, user.surname, ';');
			std::getline(input, user.name, ';');
			std::getline(input, pop_string);
			user.id = std::atoi(id_string.c_str());
			user.popularity = std::atof(pop_string.c_str());
						
			return input;
			
		}
		
		friend std::ostream &operator<<(std::ostream &output, const User &user) {
			output << "ID: " << user.id << ", " << user.surname << " " << user.name << ", Popularity: " << user.popularity;
			return output;
		}
		
		bool operator<(const User &other) {
			return this->compareTo(other) < 0;
		}
		
		bool operator>(const User &other) {
			return this->compareTo(other) > 0;
		}
		
		bool operator==(const User &other) {
			return this->compareTo(other) == 0;
		}
		
};

namespace sorting {
	
	unsigned int n_swaps = 0;
	unsigned int n_comparisons = 0;
	
	template <typename T>
	inline void swap(T &a, T &b) {
		T temp = a;
		a = b;
		b = temp;
		n_swaps++;
	}

	template <typename T>
	inline void selectionSort(T array[], int n) {
		n_swaps = 0;
		n_comparisons = 0;
		int indexMin;

		for(int i=0; i < n; i++) {
			indexMin = i;
			for(int j=i+1; j < n; j++) {
				n_comparisons++;
				if(array[j] < array[indexMin])
					indexMin = j;
			}

			swap(array[i], array[indexMin]);
		}
	}
	
	template <typename T> inline void insertionSort(T *array, int n) {
		n_swaps = 0;
		n_comparisons = 0;
		int j;
		T temp;

		for(int i=1; i < n; i++) {
			temp = array[i];
			for(j=i; j > 0; j--) {
				n_comparisons++;
				if(temp < array[j-1]) {
					n_swaps++;
					array[j] = array[j-1];
				}
				else
					break;
			}
			n_swaps++;
			array[j] = temp;
		}
}

	template <typename T>
	inline void printArray(T array[], int n, char sep='\n') {
		for(int i=0; i < n; i++) {
			std::cout << array[i] << sep;
		}
		std::cout << std::endl;
	}
	
	template <typename T>
	inline void merge(T array[], int p, int q, int r) {
		
		//Ricavo la dimensione delle partizioni di appoggio sinistra e destra
		int n1 = q-p+1;
		int n2 = r-q;
		
		std::cout << "INDICI: " << p << " " << q << " " << r << std::endl;
		
		//alloco lo spazio
		T *L = new T[n1+1];
		T *R = new T[n2+1];
			
		//copio gli elementi dall'array originale in L e R
		for(int i=0; i < n1; i++)
			L[i] = array[p+i];
		
		for(int j=1; j <= n2; j++)
			R[j-1] = array[q+j];
		
		//inserisco un elemento sentinella pari al massimo i
		L[n1] = std::numeric_limits<T>::infinity();
		R[n2] = std::numeric_limits<T>::infinity();
		
		//Decommenta le righe sottostanti per stampare le partizioni
		//printArray(L, n1);
		//printArray(R, n2);
		
		int i = 0, j = 0, k = p;
		
		//seleziona l'elemento minore tra quelli in "cima" ad L e R e spostalo nell'array originale
		for(k=p; k <= r; k++) {
			n_comparisons++;
			if(L[i] < R[j]) {
				array[k] = L[i];
				i++;
			}
			else {
				array[k] = R[j];
				j++;
			}
		}
		
		//dealloco la memoria utilizzata per L e R
		delete [] L;
		delete [] R;
	}

	template <typename T>
	void mergesort(T *array, int p, int r) {
		if(p < r) {
			int q = std::floor((p+r)/2.0);
			mergesort(array, p, q);
			mergesort(array, q+1, r);
			merge(array, p, q, r);
		}
	}
	
	template <typename T>
	inline int partition(T* array, int start, int end) {
		//Scelgo l'ultimo elemento come pivot
		T pivot = array[end];
		//l'indice j rappresenta l'indice di separazione tra gli elementi
		//più piccoli del pivot (a sinistra) e quelli più grandi (a destra)
		int j = start;
		//l'indice i serve a scorrere tutti gli elementi, compreso il pivot
		for(int i=start; i<=end; i++) {
			//se l'elemento che considero è più piccolo del pivot
			//lo metto nella parte destra, incrementando l'indice j
			n_comparisons++;
			if((array[i] < pivot) || (array[i] == pivot)) {
				swap(array[i], array[j]);
				j++;
			}		
		}
		
		//Decommenta la riga successiva per vedere gli indici di partizionamento
		//std::cout << "Partition from " << start << " to " << end << " - PIVOT IN " << j-1 << std::endl;
		
		//dato che abbiamo scambiato anche il pivot, l'indice j segnerà la posizione successiva a quella del pivot
		//e quindi restituiamo j-1
		return j-1;
	}
	
	template <typename T>
	inline void quicksort(T* array, int start, int end) {
		
		if(start >= end)
			return;
		
		int q = partition(array, start, end);
		//nella procedura partition il pivot viene posizionato correttamente in q, quindi dobbiamo
		//effettuare la chiamata ricorsiva sulle partizioni destra e sinistra
		//partizione sinistra da start a q-1
		quicksort(array,start, q-1);
		//partizione destra da q+1 a end
		quicksort(array,q+1, end);
	}
}


int main(int argc, char* argv[]) {
	
	int n;
	std::string alg = "quicksort";
	if(argc == 1)
		n = MAX_N;
	else if(argc == 2)
		n = std::atoi(argv[1]);
	else if(argc == 3) {
		n = std::atoi(argv[1]);
		alg = std::string(argv[2]);
		if(!(alg == "quicksort" || alg == "insertion" || alg == "all")) {
			std::cout << "./sorting [N_ELEM [(quicksort|insertion|all)]]" << std::endl;
			exit(-1);
		}			
	}	
	
	std::ifstream ifs("utenti.txt", std::ifstream::in);
	
	User *users = new User[n];
	unsigned int count = 0;
	while(ifs.good() && count < n) {
		User u;
		ifs >> u; 
		users[count++] = u;		
		std::cout << u << std::endl;
	}
	
	ifs.close();
			
	if(alg == "quicksort" || alg == "all") {
		User* temp = new User[n];
		for(int i=0; i < n; i++)
			temp[i] = users[i];
		n_comparisons = 0;
		n_swaps = 0;
		quicksort(temp, 0, n-1);
		
		/* Decommenta questo blocco per stampare l'array ordinato
		for(int i=0; i < n; i++) {
			std::cout << "\t" << temp[i] << std::endl;
		}
		*/
		
		std::cout << "It took " << sorting::n_swaps << " swaps to sort " << n << " elements of the array using quicksort" << std::endl;
		std::cout << "It took " << sorting::n_comparisons << " comparisons to sort " << n << " elements of the array using quicksort"<< std::endl;
				
		delete [] temp;
		
	}
	if(alg == "insertion" || alg == "all") {
		User* temp = new User[n];
		for(int i=0; i < n; i++)
			temp[i] = users[i];
	
		insertionSort(temp, n);
		
		//Decommenta questo blocco per stampare l'array ordinato
		for(int i=0; i < n; i++) {
			std::cout << "\t" << temp[i] << std::endl;
		}
		
		std::cout << "It took " << sorting::n_swaps << " swaps to sort " << n << " elements of the array using insertionsort" << std::endl;
		std::cout << "It took " << sorting::n_comparisons << " comparisons to sort " << n << " elements of the array using insertionsort" << std::endl;
		
		delete [] temp;
	}	
	
	delete [] users;
}