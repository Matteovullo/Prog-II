/*Si supponga di avere un array interaction I e un array timestamp T, contenenti rispettivamente le 
interazioni ottenute postando un determinato contenuto su un social (+1 per ogni interazione positiva, -
1 per ogni interazione negativa) ed un intero che rappresenta il tempo (in minuti) di pubblicazione dell’iesimo post pubblicato. La popolarità di un utente è determinata da una combinazione lineare della 
frequenza F e di uno score derivato dalle interazioni S, secondo la seguente formula:
𝑃 = 𝛼 ∗ 𝑆 + (1 − 𝛼) ∗ 𝐹
con 𝛼 = 0.66, e S ed F sono calcolati come segue:
𝑆𝑡 =
1
4
∗ 𝐼𝑡−3 +
1
3
∗ 𝐼𝑡−2 +
1
2
∗ 𝐼𝑡−1 + 𝐼𝑡
𝐹𝑡 =
1
𝑛
∑(𝑇𝑡 − 𝑇𝑡−1
)
𝑛
𝑡=1
Scrivere un programma che, dati gli array I e T in input, calcoli la popolarità dell’utente ad ogni istante t, 
e ne individui il periodo di massima popolarità*/

#include <iostream>

using namespace std;

#define alfa 0.66 

double *S(int *I, int n){
    double *s=new double [n];
    for(int i=0; i<n; i++){
        if(i<3)
            s[i]=I[i];
        else
            s[i]=((1/4)*I[i-3])+((1/3)*I[i-2])+((1/2)*I[i-1])+(I[i]);
    }

    return s;
}

double *F(int *T, int n){
    double *f=new double [n];
    int somma=0;
    f[0]=0.0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=i; j++){
        somma+=T[j]-T[j-1]; // f[i]=t[j]-t[j-1];
        }
        f[i]=(1/n)*somma; // f[i] /= n;
    }

    return f;
}

double *P(int n, double *I, double *T){
    double *i=S(I, n);
    double *f=F(T, n);

    double *p=new double[n];
    for(int i=0; i<n; i++){
        p[i]=(alfa*s[i])+(1-alfa)*f[i];
    }

    return p;
}

double SommaMassima3(int S[], int n, int &start, int &end){
	double _max = 0;
	double somma= _max;
	for(int j = 0; j < n; j++) {
		if (somma > 0) {
			 somma = somma + S[j];
		} else {
            //è il punto di inizio del segmento di somma somma massima
            start=j;
			somma = S[j];
		}
		if (somma > _max){
            //è il punto di fine del segmento di somma massima
            end=j;
            _max = somma; 
        }
	}
	return _max;
}


int main(){

}