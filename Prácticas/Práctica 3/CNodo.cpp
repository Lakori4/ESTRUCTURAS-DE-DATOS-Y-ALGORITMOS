//Santiago Valderrama y Gina Ramírez

// CLASE Nodo

#include <iostream>
#include <memory>
#include "CCliente.h"
#include "CNodo.h"

void Nodo::setNext(const shared_ptr<Nodo> &newNext) {
    next = newNext;
}

const CCliente &Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(const CCliente &newDato) {
    dato = newDato;
}

shared_ptr<Nodo> Nodo::getNext() const {
    return next;
}
