//Santiago Valderrama y Gina Ramírez


#ifndef CBANCO_H
#define CBANCO_H

#include <iostream>
#include "TADLista.h"
#include "TADCola.h"

using namespace std;

class CBanco {
    private:
        Cola Qbanco, Qdepend;
        Lista Loper;
    public:
        CBanco();
        CBanco(Cola const &qB, Cola const &qD, Lista const &lO):Qbanco(qB),Qdepend(qD), Loper(lO){}

        const Cola &getQbanco() const;
        void setQbanco(const Cola &qB);
        const Cola &getQdepend() const;
        void setQdepend(const Cola &qD);
        const Lista &getLoper() const;
        void setLoper( const Lista &lO);

        void AtencionVGeneral();
        void AtencionVIngresos();
};


#endif // CBANCO_H