#include "15_stack.h"
#include "16_queue.h"
#include <iostream>


using namespace std;

class OperazioneAritmetica{
    protected:
        double opSinistro;
        double opDestro;

    public:
        OperazioneAritmetica(double a, double b){
            this->opSinistro=a;
            this->opDestro=b;
        }
        virtual double eseguiCalcolo() = 0;
        virtual ostream& put(ostream& out) = 0;
};

ostream& operator << (ostream& out, OperazioneAritmetica& obj){
    return obj.put(out);
}

class Addizione : public OperazioneAritmetica{
    private:
        double risultato;
    public:
        Addizione(double a, double b) : OperazioneAritmetica(a, b){
        }
        double eseguiRisultato(){
            risultato = opSinistro + opDestro;
            return risultato;
        }
        double getRisultato(){
            return risultato;
        }
        ostream& put(ostream& out){
            out << "Addizone, risutlato: " << risultato;
            return out;
        }
};

class Sottrazione : OperazioneAritmetica{
    private:
        double risultato;
    public:
        Sottrazione(double a, double b) : OperazioneAritmetica(a, b){
        }
        double eseguiRisultato(){
            risultato = opSinistro - opDestro;
            return risultato;
        }
        double getRisultato(){
            return risultato;
        }
        ostream& put(ostream& out){
            out << "Sottrazione, risutlato: " << risultato;
            return out;
        }
};

class Moltiplicazione : OperazioneAritmetica{
    private:
        double risultato;
    public:
        Moltiplicazione(double a, double b) : OperazioneAritmetica(a, b){
        }
        double eseguiRisultato(){
            risultato = opSinistro * opDestro;
            return risultato;
        }
        double getRisultato(){
            return risultato;
        }
        ostream& put(ostream& out){
            out << "Moltiplicazione, risutlato: " << risultato;
            return out;
        }
};

class Divisione : OperazioneAritmetica{
    private:
        double risultato;
    public:
        Divisione(double a, double b) : OperazioneAritmetica(a, b){
        }
        double eseguiRisultato(){
            if(opDestro != 0.0){
                risultato = opSinistro / opDestro;
                return risultato;
            }
            return -1;
        }
        double getRisultato(){
            return risultato;
        }
        ostream& put(ostream& out){
            out << "Divisone, risutlato: " << risultato;
            return out;
        }
};

int main(){
    //1
    int n;
    cout << "Inserire un numero" ;
    cin >> n;


    //2
    Stack<OperazioneAritmetica*> s;

    for(int i=0; i<n; i++){
        int r=rand()%(4-1+1)+1;
        OperazioneAritmetica* obj;
        if(r==1){
            obj = new Addizione();
        }
        if(r==1){
            obj = new Sottrazione();
        }
        if(r==1){
            obj = new Moltiplicazione();
        }
        if(r==1){
            obj = new Divisione();
        }
        s.push(obj)
    }

    //3
    Queue<double> q;
    for(int i=0; i<2*n; i++){
        q.enqueue(rand()/(rand_max)*DOUBLE_MAX);
    }

    //4
    cout << s << endl;
    cout << q << endl;

    //5
    for(int i=0; i<n; i++){
        if(typeid(s.top()) == Addizione){
            DLnode<double> *ptr1=q.dequeue();
            DLnode<double> *ptr2=q.dequeue();
            cout << "Risutlato: " << *ptr1 + *ptr2;
            s.pop();
        }
        if(typeid(s.top()) == Sottrazione){
            DLnode<double> *ptr1=q.dequeue();
            DLnode<double> *ptr2=q.dequeue();
            cout << "Risutlato: " << *ptr1 - *ptr2;
            s.pop();
        }
        if(typeid(s.top()) == Moltiplicazione){
            DLnode<double> *ptr1=q.dequeue();
            DLnode<double> *ptr2=q.dequeue();
            cout << "Risutlato: " << (*ptr1) * (*ptr2);
            s.pop();
        }
        if(typeid(s.top()) == Divisione){
            DLnode<double> *ptr1=q.dequeue();
            DLnode<double> *ptr2=q.dequeue();
            if(*ptr2 != 0){
                cout << "Risutlato: " << *ptr1 / ptr2;
                s.pop();
            }
        }
    }

    return 0;
}