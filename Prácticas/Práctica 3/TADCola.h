//Santiago Valderrama y Gina Ramírez


#ifndef TADCOLA_H
#define TADCOLA_H

#include <iostream>
#include <memory>
#include "CCliente.h"
#include "CNodo.h"
#include "TADLista.h"

using namespace std;

class Cola {
    private:
        shared_ptr<Nodo> ppio, final;
    public:
        Cola():ppio(nullptr), final(nullptr){}

        bool empty() const;
        void push(const CCliente &dato);
        void pop();
        const CCliente &primero() const;

        void iniciarCola();

        void mostrarCola() const;
        void AtenderClienteVG (Lista &Loper);
        
};

#endif // TADCOLA_H