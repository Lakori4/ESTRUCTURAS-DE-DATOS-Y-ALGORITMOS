//Santiago Valderrama y Gina Ramírez


#ifndef CNODO_H
#define CNODO_H

#include <iostream>
#include <memory>
#include "CCliente.h"

using namespace std;

class Nodo {
    private:
        CCliente dato;
        shared_ptr<Nodo> next;
    public:
        Nodo():next(nullptr){}
        Nodo(CCliente const &d, shared_ptr<Nodo> const &ptr):dato(d),next(ptr){}

        const CCliente &getDato() const;
        void setDato(const CCliente &newDato);
        shared_ptr<Nodo> getNext() const;
        void setNext(const shared_ptr<Nodo> &newNext);
};

#endif // CNODO_H