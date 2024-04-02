#ifndef HOJA4_H
#define HOJA4_H

#include <iostream>
#include <memory>
#include "Teoría\T3-TIPOS ABSTRACTOS DE DATOS (TAD)\Nodo.h"

using namespace std;



class Stack {
    private:
        shared_ptr <Nodo>  front; // El puntero debe señalar siempre al primer elemento
    
    public:
        Stack() : front(nullptr) {}

        bool empty() const;
        void push(int num);
        void pop(); //NO HAY USOS
        shared_ptr <Nodo> getTop() const;
};

int menu();
void dispEmpty(Stack const &s);

#endif