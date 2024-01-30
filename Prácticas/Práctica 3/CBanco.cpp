//Santiago Valderrama y Gina Ramírez

// CLASE BANCO

#include <iostream>
#include <memory>
#include "TADCola.h"
#include "TADLista.h"
#include "CBanco.h"

using namespace std;

CBanco::CBanco() {
    Cola Qbanco();
    Cola Qdepend();
    Lista Loper();
}



const Cola &CBanco::getQbanco() const {
   return Qbanco;
}
void CBanco::setQbanco(const Cola &qB) {
   Qbanco = qB;
}
const Cola &CBanco::getQdepend() const {
    return Qdepend;
}
void CBanco::setQdepend(const Cola &qD) {
    Qdepend = qD;
}
const Lista &CBanco::getLoper() const {
    return Loper;
}
void CBanco::setLoper( const Lista &lO) {
    Loper = lO;
}

void CBanco::AtencionVGeneral() {
  // HACER
}

void CBanco::AtencionVIngresos() {
  // HACER
}
