#ifndef TADPILA_H
#define TADPILA_H

#include <iostream>
#include <memory>
#include "TADNodo.h"

using namespace std;

class Stack {
    public:
        Stack():front(nullptr){}
        Stack(Stack const &S);
        ~Stack();

        bool empty() const;
        void push(const TipoDato &dato);
        void pop();
        const TipoDato &top() const;

        void mostrarPila() const;

    private:
        shared_ptr<Nodo> front;
};

#endif // TADPILA_H
