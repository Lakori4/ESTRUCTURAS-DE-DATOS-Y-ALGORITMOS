//Santiago Valderrama y Gina Ramírez

#ifndef TADLISTA_H
#define TADLISTA_H

#include <iostream>
#include <memory>
#include "CCliente.h"
#include "CNodo.h"

using namespace std;

class Lista {
    private:
        shared_ptr<Nodo> ppioL;
    public:
        Lista():ppioL(nullptr){};
        
        const shared_ptr<Nodo> &getPpio() const;
        void setPpio(const shared_ptr<Nodo> &newPpio);

        bool empty() const;
        void push_ppio(const CCliente& dato);

        const CCliente &primeroL() const;

        void mostrarLista() const;        

        void insertarOrdenLista(CCliente c);
};


#endif // TADLISTA_H

