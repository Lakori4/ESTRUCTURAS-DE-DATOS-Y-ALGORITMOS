//Santiago Valderrama y Gina Ramírez
#include <iostream>
#include <memory>

#include "TADABB.h"
#include "TADABB.cpp"

using namespace std;

int main()
{   int dato;
    Arbol ABBiter, ABBrec;

    do {
        cout << "\n\tIntroduzca un numero (negativo para terminar): ";
        cin >> dato;
        if (dato > 0) {
            ABBrec.crearABBRec(dato);
            ABBiter.crearABBIter(dato);
        }
    } while (dato > 0);

    cout << "\n\n\tMostrar ABBrec\n";
    ABBrec.mostrar();

    cout << "\n\n\tMostrar ABBiter\n";
    ABBiter.mostrar();

    cout << "\n\tIntroduzca el valor que quiere buscar en el arbol: ";
    cin >> dato;
     cout << "\n\tEl valor " << dato << " aparece " << ABBrec.contarValorABBRec(dato) << endl;

    //cout << "\n\tla suma de los datos del arbol ABBiter es " << ABBiter.sumarABBIter() << endl; 

    cout << "\n\n\t";
    return 0;
}