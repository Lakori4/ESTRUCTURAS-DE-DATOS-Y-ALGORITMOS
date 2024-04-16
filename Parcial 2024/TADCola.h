#ifndef TADCOLA_H
#define TADCOLA_H

#include <iostream>
#include <memory>
#include "TADNodo.h"

using namespace std;

class Cola {
    public:
        Cola():front(nullptr), end(nullptr){}
        Cola(const Cola &Q);
        ~Cola();

        bool empty() const;
        void push(const TipoDato &dato);
        void pop();
        const TipoDato &first() const;

        void mostrarCola() const;

    private:
        shared_ptr<Nodo> front, end;
};

#endif // TADCOLA_H
