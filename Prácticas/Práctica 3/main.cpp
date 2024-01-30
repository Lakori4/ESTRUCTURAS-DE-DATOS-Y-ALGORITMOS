//Santiago Valderrama y Gina Ramirez

#include <iostream>
#include <memory>
#include "CCliente.h"
#include "TADCola.h"
#include "TADLista.h"
#include "CBanco.h"

using namespace std;



int main()
{
    Cola miQ;
    CCliente uncliente;
    CBanco elBanco;

    uncliente.setDNI("011111111A");
    uncliente.setOperacion('I');  // 'I' ingreso
    uncliente.setImporte(1200.70);
    miQ.push(uncliente);

    uncliente.setDNI("044444444B");
    uncliente.setOperacion('C');  // 'C' consulta
    uncliente.setImporte(1400.00);
    miQ.push(uncliente);

    uncliente.setDNI("077777777G");
    uncliente.setOperacion('R');  // 'R' reintegro
    uncliente.setImporte(200.00);
    miQ.push(uncliente);

    uncliente.setDNI("022200222B");
    uncliente.setOperacion('I');  // 'I' ingreso
    uncliente.setImporte(900.50);
    miQ.push(uncliente);

    uncliente.setDNI("033300333C");
    uncliente.setOperacion('I');  // 'I' ingreso
    uncliente.setImporte(1250.50);
    miQ.push(uncliente);

    elBanco.setQbanco(miQ);

    miQ.iniciarCola();

    uncliente.setDNI("055500555D");
    uncliente.setOperacion('C');  // 'C' consulta
    uncliente.setImporte(2300.30);
    miQ.push(uncliente);

    uncliente.setDNI("088888888M");
    uncliente.setOperacion('R');  // 'R' reintegro
    uncliente.setImporte(2050.80);
    miQ.push(uncliente);

    uncliente.setDNI("000666666F");
    uncliente.setOperacion('C');  // 'C' consulta
    uncliente.setImporte(1050.60);
    miQ.push(uncliente);

    uncliente.setDNI("101010101Z");
    uncliente.setOperacion('R');  // 'R' reintegro
    uncliente.setImporte(1320.00);
    miQ.push(uncliente);

    elBanco.setQdepend(miQ);

    cout << "\n\n\tCOLA CLIENTES GENERAL:";
    elBanco.getQbanco().mostrarCola();

    cout << "\n\n\tCOLA CLIENTES DEPENDENCIA:";
    elBanco.getQdepend().mostrarCola();

    cout << "\n\t----VENTANILLA GENERAL\n";
    elBanco.AtencionVGeneral();

    cout << "\n\t----VENTANILLA INGRESOS\n";
    elBanco.AtencionVIngresos();

    cout << "\n\t----VENTANILLA GENERAL\n";
    elBanco.AtencionVGeneral();

    cout << "\n\t----VENTANILLA INGRESOS\n";
    elBanco.AtencionVIngresos();

    cout << "\n\n\tCOLA CLIENTES GENERAL:";
    elBanco.getQbanco().mostrarCola();
    cout << "\n\n\tCOLA CLIENTES DEPENDENCIA:";
    elBanco.getQdepend().mostrarCola();
    cout << "\n\n\tLISTA CLIENTES PROCESADOS:";
    elBanco.getLoper().mostrarLista();

    cout << "\n\n\t";
    return 0;
}

