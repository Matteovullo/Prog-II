#include "Queue.h"
#include "Studenti.h"

using namespace std;

int main(){
    
    Studente("Carlo", "Spata", 19) s1;
    Studente("Alessandro", "Sciacca", 20) s2;
    Studente("Gabriele", "Riggi", 19) s3;
    Studente("Emilio", "Sava", 19) s4;

    Queue<Studente> s;
    s.enqueue(s1);
    s.enqueue(s2);
    s.enqueue(s3);
    s.enqueue(s4);

    cout << s << endl;

}