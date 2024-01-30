//Santiago Valderrama y Gina Ramírez


// CLASE Cliente

#include <iostream>
#include "CCliente.h"

const string &CCliente::getDNI() const {
   return DNI;
}

void CCliente::setDNI(const string &nDNI){
   DNI = nDNI;
}

char CCliente::getOperacion() const {
   return operacion;
}

void CCliente::setOperacion(char o){
   operacion = o;
}

float CCliente::getImporte() const{
    return importe;
}

void CCliente::setImporte(float i){
   importe = i;
}