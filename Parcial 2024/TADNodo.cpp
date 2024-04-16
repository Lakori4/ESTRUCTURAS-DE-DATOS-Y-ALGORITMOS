#include <iostream>
#include <memory>
#include "TADNodo.h"

using namespace std;

// CLASE Nodo

void Nodo::setNext(const shared_ptr<Nodo> &newNext) {
    next = newNext;
}

const TipoDato &Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(const TipoDato &newDato) {
    dato = newDato;
}

const shared_ptr<Nodo> &Nodo::getNext() const {
    return next;
}
