//Santiago Valderrama y Gina Ramírez

#ifndef CCLIENTE_H
#define CCLIENTE_H

#include <iostream>

using namespace std;

class CCliente {
    private:
        string DNI;
        char operacion;
        float importe;
    public:
        CCliente():DNI(""), operacion(' '), importe(0){}
        CCliente(string const &nDNI, char o, float i):DNI(nDNI),operacion(o), importe(i){}

        const string &getDNI() const;
        void setDNI(const string &nDNI);
        char getOperacion() const;
        void setOperacion(char o);
        float getImporte() const;
        void setImporte(float i);
};

#endif // CCLIENTE_H