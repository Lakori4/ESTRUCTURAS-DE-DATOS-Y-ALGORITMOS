#include <iostream>
#include <memory>
#include <vector>

#include "TADArbol.h"

using namespace std;


//------------------Clase CDato
int CDato::getN() const {
    return n;
}

void CDato::setN(int newN) {
    n = newN;
}


//--------------------Clase Nodo
const CDato &Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(const CDato &newDato) {
    dato = newDato;
}

const shared_ptr<Nodo> &Nodo::getHizq() const {
        return hizq;
}

void Nodo::setHizq(const shared_ptr<Nodo> &newHizq) {
    hizq = newHizq;
}

const shared_ptr<Nodo> &Nodo::getHdch() const {
     return hdch;
}

void Nodo::setHdch(const shared_ptr<Nodo> &newHdch) {
    hdch = newHdch;
}

void Nodo::procesarNodo () const {
    cout << "\n\n\tNodo: " << getDato().getN();
}

//-------------------Clase Ãrbol


bool Arbol::empty() const {
    return (raiz == nullptr);
}

const shared_ptr<Nodo> &Arbol::getRaiz() const {
    return raiz;
}

void Arbol::setRaiz(const shared_ptr<Nodo> &newRaiz) {
    raiz = newRaiz;
}

Arbol::Arbol(CDato const &dato) {
    raiz = make_shared<Nodo>(Nodo{dato});
}

void Arbol::addHizq(Arbol const &Ai) {
    raiz->setHizq(Ai.raiz);
}

void Arbol::addHdch(Arbol const &Ad) {
    raiz->setHdch(Ad.raiz);
}


CDato const &Arbol::getDatoNodo () const {
    return raiz->getDato();
}

const shared_ptr<Nodo> &Arbol::getHiNodo() const {
    return raiz->getHizq();
}

const shared_ptr<Nodo> &Arbol::getHdNodo() const {
    return raiz->getHdch();
}

void Arbol::construirArbol (Arbol const &Ai, Arbol const &Ad, CDato const &dato) {
    raiz = make_shared<Nodo>(Nodo{dato});
    raiz->setHizq(Ai.raiz);
    raiz->setHdch(Ad.raiz);
}

// Recorrido InOrden compacto, sin varibles auxiliares
void Arbol::InOrden(shared_ptr<Nodo> A) const {
    if (A != nullptr) {
         InOrden (A->getHizq());	    // I
         A->procesarNodo();             // R
         InOrden (A->getHdch());        // D
    }
}

void Arbol::recorrerInOrden() const {
    if (!empty()) {
        InOrden (raiz);
    }
}


void Arbol::PreOrden(shared_ptr<Nodo> A) const {
    if (A != nullptr) {
        A -> procesarNodo();
        PreOrden(A -> getHizq());
        PreOrden(A -> getHdch());
    }
}

void Arbol::recorrerPreOrden() const {
    if (!empty()) {
        PreOrden (raiz);
    }
}

void Arbol::PostOrden(shared_ptr<Nodo> A) const {
    if (A != nullptr) {
        PostOrden(A -> getHizq());
        PostOrden(A -> getHdch());
        A -> procesarNodo();
    }
}

void Arbol::recorrerPostOrden() const {
    if (!empty()) {
        PostOrden (raiz);
    }
}

void Arbol::recorrerAnchura() const {
    Arbol Bi, Bd, B;
    vector <Arbol> Niveles;
    int num;

    if (!empty()) { Niveles.push_back(*this); } //Se añade la raiz del árbol

    while (!Niveles.empty()) {
        B = Niveles[0];
        Niveles.erase(Niveles.begin());

        num = B.getDatoNodo().getN();
        Bi.setRaiz(B.getHiNodo());
        Bd.setRaiz(B.getHdNodo());
        cout << "\n\tNodo: " << num;

        if (!Bi.empty()) { Niveles.push_back(Bi); }

        if (!Bd.empty()) { Niveles.push_back(Bd); }
    }
    
}

