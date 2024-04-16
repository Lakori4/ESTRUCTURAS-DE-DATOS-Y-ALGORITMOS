#ifndef TADNODO_H
#define TADNODO_H

#include <iostream>
#include <memory>

using namespace std;

struct TipoDato {
    int num;
};

class Nodo {
    private:
        TipoDato dato;
        shared_ptr<Nodo> next;
    public:
        Nodo():next(nullptr){}
        Nodo(TipoDato const &d, shared_ptr<Nodo> ptr):dato(d),next(ptr){}
        ~Nodo(){}

        const TipoDato &getDato() const;
        void setDato(const TipoDato &newDato);
        const shared_ptr<Nodo> &getNext() const;
        void setNext(const shared_ptr<Nodo> &newNext);
};

#endif // TADNODO_H
