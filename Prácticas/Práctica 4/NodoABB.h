//Santiago Valderrama y Gina Ramírez
#ifndef NODOABB_H
#define NODOABB_H

#include <iostream>
#include <memory>

using namespace std;

//---------------Clase Nodo

class Nodo {
    public:
        int dato;
        shared_ptr<Nodo> hizq = nullptr;
        shared_ptr<Nodo> hdch = nullptr;
    public:
        Nodo(int d):dato{d} {}

        int getDato() const { return dato; }
        void setDato(int newDato) { dato = newDato; }

        const shared_ptr<Nodo> &getHizq() const { return hizq; }
        void setHizq(const shared_ptr<Nodo> &newHizq) { hizq = newHizq; }

        const shared_ptr<Nodo> &getHdch() const { return hdch; }
        void setHdch(const shared_ptr<Nodo> &newHdch) { hdch = newHdch; }

        void procesarNodo () const { cout << "\n\n\tNodo: " << getDato(); }
};

#endif // NODOABB_H