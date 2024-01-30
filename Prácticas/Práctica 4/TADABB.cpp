//Santiago Valderrama y Gina Ramírez
#include <iostream>
#include <memory>

#include "NodoABB.h"
#include "TADABB.h"

using namespace std;

//-------------------Clase Arbol

bool Arbol::empty() const {

    if (raiz == nullptr) return true;

    else return false;
}

void Arbol::addHizq(Arbol const& Ai) {
    raiz->hizq = Ai.raiz;
}

void Arbol::addHdch(Arbol const& Ad) {
    raiz->hdch = Ad.raiz;
}



void Arbol::crearABBIter(int dato) {

    shared_ptr<Nodo> nRaiz = raiz;


    if (empty()) {
        raiz = make_shared<Nodo>(dato);
    }

    else {

        while (nRaiz->getHdch() != nullptr || nRaiz->getHizq() != nullptr) {

            while (nRaiz->getHizq() != nullptr && nRaiz->getDato() > dato) {
            
                nRaiz = nRaiz->getHizq();
            }

            while (nRaiz ->getHdch() != nullptr && nRaiz->getDato() <= dato) {
            
                nRaiz = nRaiz->getHdch();
            }

            if (nRaiz->getHizq() == nullptr && nRaiz->getDato() > dato) {
                
                nRaiz->hizq = make_shared<Nodo> (dato);
                
            }

            if (nRaiz->getHdch() == nullptr && nRaiz->getDato() <= dato) {
                
                nRaiz->hdch = make_shared<Nodo> (dato);
                break;
            }

         
        }

        if (nRaiz->dato >= dato) nRaiz->hizq = make_shared<Nodo> (dato);

        if (nRaiz->dato < dato) nRaiz->hdch = make_shared<Nodo> (dato);
    }
}



void Arbol::crearABBRec(int dato) {
    if (dato >= 0) {
        if (this->empty()) {
            shared_ptr<Nodo> newNodo = make_shared<Nodo>(dato);
            this->setRaiz(newNodo);
        }
        else {
            if (dato < this->raiz->dato) {
                Arbol Ai;
                Ai.crearABBRec(dato);
                this->addHizq(Ai);
            }
            else {
                Arbol Ad;
                Ad.crearABBRec(dato);
                this->addHdch(Ad);
            }
        }
    }
}

void mostrarOrden(shared_ptr<Nodo> A) {
    if (A != nullptr) {
        mostrarOrden(A->hizq);
        A->procesarNodo();
        mostrarOrden(A->hdch);
    }
}

void Arbol::mostrar() const {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
    }
    else {
        cout << "Nodos del arbol ordenados:" << endl;
        mostrarOrden(raiz);
    }
}

int contarValorRec(shared_ptr<Nodo> nodo, int valor) {
    if (nodo == nullptr) {
        cout << "El arbol esta vacio" << endl;
        return 0;
    }
    else if (nodo->dato == valor) {
        return 1 + contarValorRec(nodo->hizq, valor) + contarValorRec(nodo->hdch, valor);
    }
    else if (nodo->dato > valor) {
        return contarValorRec(nodo->hizq, valor);
    }
    else {
        return contarValorRec(nodo->hdch, valor);
    }
}

int Arbol::contarValorABBRec(int valor) {
    return contarValorRec(raiz, valor);
}


