//SANTIAGO VALDERRAMA FLORES Y GINA ANDREA RAMIREZ GUERRERO
#include <iostream>
#include <memory>
#include "TADLista.h"

using namespace std;

//------------------Clase CDato
int CDato::getVertice() const {
    return vertice;
}

void CDato::setVertice(int newV) {
    vertice = newV;
}

float CDato::getDistancia() const {
    return distancia;
}

void CDato::setDistancia(float newD) {
    distancia = newD;
}

void CDato::setCDato(int v, float d) {
    vertice = v;
    distancia = d;
}

//--------------------Clase Nodo
Nodo::Nodo() {
    dato.setVertice(0);
    dato.setDistancia(0);
}

const CDato& Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(const CDato& newDato) {
    dato = newDato;
}

shared_ptr<Nodo> Nodo::getNext() const {
    return next;
}

void Nodo::setNext(const shared_ptr<Nodo>& newNext) {
    next = newNext;
}

//-------------------Clase Lista
const shared_ptr<Nodo>& Lista::getFirst() const {
    return first;
}

void Lista::setFirst(const shared_ptr<Nodo>& newFirst) {
    first = newFirst;
}


// COMPLETAR
bool Lista::empty() const {

    if (first == nullptr) return true;
    else return false;


}

void Lista::listaVacia() {
    first = nullptr;
}

// COMPLETAR
// Inserta un elemento al principio de la lista
void Lista::push_front(const CDato& dato) {

    shared_ptr <Nodo> new_first = make_shared<Nodo>(Nodo(dato));

    new_first->setNext(first);

    setFirst(new_first);

}

//COMPLETAR
// Devuelve el dato del primer elemento de la lista
const CDato& Lista::front() const {
    return first->getDato();

}

//COMPLETAR
// Muestra el contenido de los nodos de la lista
void Lista::mostrarLista() const {
    shared_ptr <Nodo> new_ptr = first;

    cout << "\n\n\t";

    while (new_ptr->getNext() == nullptr) {

        cout << "\n\nVertice: " << new_ptr->getDato().getVertice();
        cout << "\tDistancia: " << new_ptr->getDato().getDistancia();

        new_ptr = new_ptr->getNext();
    }

}

//COMPLETAR
// Calcula el total de distancias que forman la lista
float Lista::calcularDistancias() const {

    float d = 0;

    shared_ptr <Nodo> new_ptr = first;

    while (new_ptr->getNext() == nullptr) {

        d += new_ptr->getDato().getDistancia();

        new_ptr = new_ptr->getNext();
    }

    d += new_ptr->getDato().getDistancia();

    return d;


}