#ifndef STUDENTE_H
#define STUDENTE_H

#include <iostream>
#include <string>

class Studente{
    private:
        string name;
        string surname;
        int age;

    public:
        Studente(string name, string surname, int age){
            this->name=name;
            this->surname=surname;
            this->age=age;
        }
};

#endif