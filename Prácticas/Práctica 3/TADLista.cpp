//Santiago Valderrama y Gina Ramírez

// CLASE Lista

#include <iostream>
#include <memory>
#include "CCliente.h"
#include "CNodo.h"
#include "TADLista.h"

using namespace std;

const shared_ptr<Nodo> &Lista::getPpio() const {
    return ppioL;
}

void Lista::setPpio(const shared_ptr<Nodo> &newPpio) {
    ppioL = newPpio;
}

bool Lista::empty() const {
    return (ppioL == nullptr);
}

// Inserta un elemento al principio de la lista
void Lista::push_ppio(const CCliente& dato) {
    shared_ptr<Nodo> ptr = make_shared<Nodo>(Nodo(dato, nullptr));
    if (empty()) {
        ppioL = ptr;  
    }
    else {
        ptr->setNext(ppioL);
        ppioL = ptr;
    }
}

// Devuelve el dato del primer elemento de la lista
const CCliente & Lista::primeroL() const {
    return ppioL->getDato();
}

// Inserta un elemento en la lista de forma ordenada
void Lista::insertarOrdenLista(CCliente c) {
   
    if (empty()) {
        ppioL = make_shared<Nodo>(Nodo(c, nullptr));
    }

    else {

        shared_ptr <Nodo> ptr = ppioL;

        if (ptr->getNext() == nullptr) {
            ppioL->setNext(ptr);
        }

        while (ptr->getNext() != nullptr) {

            if (c.getDNI() < ptr->getNext()->getDato().getDNI() && c.getDNI() > ptr->getDato().getDNI()) {

                shared_ptr <Nodo> Cp = make_shared <Nodo>(c, ptr->getNext());

                ptr->setNext(Cp);
            }

            else{
                ptr = ptr->getNext();
            }
        }

        if (ptr->getNext() == nullptr) {

            ptr->setNext(make_shared <Nodo>(c, nullptr));
        }
    }
}


// Muestra los datos de la lista
void Lista::mostrarLista() const{
   
   shared_ptr <Nodo> ptr = ppioL;

    while (ptr->getNext()!= nullptr) {

        cout << "\n\n\tDNI: " << ptr->getDato().getDNI();
        cout << "\n\tImporte: " << ptr->getDato().getImporte();
        cout << "\n\n\tOperación: " << ptr->getDato().getOperacion();

        ptr = ptr->getNext();
    }
   
    cout << "\n\n\tDNI: " << ptr->getDato().getDNI();
    cout << "\n\tImporte: " << ptr->getDato().getImporte();
    cout << "\n\n\tOperación: " << ptr->getDato().getOperacion();

   
}