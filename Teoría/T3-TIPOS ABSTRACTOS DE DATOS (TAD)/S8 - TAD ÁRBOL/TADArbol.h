#ifndef TADARBOL_H
#define TADARBOL_H

#include <iostream>
#include <memory>


using namespace std;

//---------------Clase CDato
class CDato {
    private:
        int n;
    public:
        CDato():n(0){};
        CDato(int d):n(d){};

        int getN() const;
        void setN(int newN);
};


//---------------Clase Nodo
class Nodo {
    private:
        CDato dato;
        shared_ptr<Nodo> hizq = nullptr;
        shared_ptr<Nodo> hdch = nullptr;
    public:
        Nodo(const CDato& d):dato{d} {};

        const CDato &getDato() const;
        void setDato(const CDato &newDato);

        const shared_ptr<Nodo> &getHizq() const;
        void setHizq(const shared_ptr<Nodo> &newHizq);

        const shared_ptr<Nodo> &getHdch() const;
        void setHdch(const shared_ptr<Nodo> &newHdch);

        void procesarNodo () const;
};

//---------------Clase Árbol Binario
class Arbol {
    private:
        shared_ptr<Nodo> raiz;
    public:
        Arbol():raiz(nullptr){};
        Arbol(CDato const &dato);

        bool empty() const;

        void addHizq(Arbol const &Ai);
        void addHdch(Arbol const &Ad);
        void construirArbol (Arbol const &Ai, Arbol const &Ad, CDato const &dato);

        CDato const &getDatoNodo () const;
        const shared_ptr<Nodo> &getHiNodo() const;
        const shared_ptr<Nodo> &getHdNodo() const;
        const shared_ptr<Nodo> &getRaiz() const;
        void setRaiz(const shared_ptr<Nodo> &newRaiz);

        void InOrden(shared_ptr<Nodo> A) const;
        void recorrerInOrden() const;

        void PreOrden(shared_ptr<Nodo> A) const;
        void recorrerPreOrden() const;

        void PostOrden(shared_ptr<Nodo> A) const;
        void recorrerPostOrden() const;
};

#endif // TADARBOL_H
