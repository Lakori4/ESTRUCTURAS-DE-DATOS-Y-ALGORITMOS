// SOLUCION PROPUESTA PARA EL PARCIAL EDA GRUPO A-T1 y A-T2 2023-2024

#include <iostream>
#include <array>
#include "TADNodo.h"
#include "TADPila.h"
#include "TADCola.h"

using namespace std;

const int DIM{10};

// PROTOTIPOS DE FUNCIONES
int menu ();

void solicitarDatosArray (array <int, DIM> &a);
//  mostrarArray

//  totalValoresParesITER
//  totalValoresParesREC

// totalValoresMultiplos5ITER
// totalValoresMultiplos5REC

// buscarElementoPila
// introducirElemPila

// buscarElementoCola
// introducirElemCola


// PROGRAMA PRINCIPAL
int main()
{
    int opcion;
    array<int, DIM> miArray;
    Stack P;
    Cola Q;
    int elem;

    do {
         opcion = menu();

         switch (opcion) {

         case 1:
                 //miArray = solicitarDatosArray();
                 //mostrarArray(miArray);
                 cout << "\n\n\tCALCULO ITERATIVO - El total de valores pares que hay en el array es ";
             //    cout << totalValoresParesITER(miArray);

                 cout << "\n\n\tCALCULO RECURSIVO - El total de valores pares que hay en el array es ";
             //    cout << totalValoresParesREC(miArray, miArray.size()-1);

                 cout << "\n\n\n";
                 break;

         case 2:
                 //miArray = solicitarDatosArray();
                 //mostrarArray(miArray);
                 cout << "\n\n\tCALCULO ITERATIVO - El total de valores multiplos de 5 que hay en el array es ";
             //    cout << totalValoresMultiplos5ITER(miArray);

                 cout << "\n\n\tCALCULO RECURSIVO - El total de valores multiplos de 5  que hay en el array es ";
             //    cout << totalValoresMultiplos5REC(miArray, miArray.size()-1);

                 cout << "\n\n\n";
                 break;

         case 3:
                 cout << "\n\n\tIntroducir numeros enteros en la Pila.";
             //    introducirElemPila(P);

                 if (!P.empty()) {
                       cout << "\n\n\tIndique el elemento que quiere buscar en la Pila: ";
                       cin >> elem;
                       cout << "\n\n\tEl elemento " << elem;
             //          if (buscarElementoPila (P, elem)) {
                           cout << " esta en la Pila";
             //          }
             //          else {
                           cout << " NO esta en la Pila";
             //          }
             //    }
             //    else {
                     cout << "\n\n\tLa pila no tiene datos." << endl;
                 }

                 cout << "\n\n\n";
                 break;
         case 4:
                 cout << "\n\n\tIntroducir numeros enteros en la Cola.";
             //    introducirElemCola(Q);

                 if (!Q.empty()) {
                       cout << "\n\n\tIndique el elemento que quiere buscar en la Cola: ";
                       cin >> elem;
                       cout << "\n\n\tEl elemento " << elem;
             //          if (buscarElementoCola (Q, elem)) {
                           cout << " esta en la Cola";
             //          }
             //          else {
                           cout << " NO esta en la Cola";
             //          }
             //    }
             //    else {
                     cout << "\n\n\tLa cola no tiene datos." << endl;
                 }

                 cout << "\n\n\n";
                 break;
         case 0: cout << "\n\n\tGracias y hasta pronto";
                 break;

         default: cout << "\n\n\tLa opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl << endl;
        }

    } while (opcion != 0);

    cout << "\n\n\t";
    return 0;
}


// Función para escribir el menu en pantalla
int menu ()
{   const int OPCIONES{4}; // Constante para cambiar facilmente el numero de opciones
    int miOpcion;

    do {
        cout << "\n\n\t1. Valores Pares-ITER y REC.";
        cout << "\n\n\t2. Valores Multiplos de 5-ITER y REC.";
        cout << "\n\n\t3. Buscar dato en la Pila.";
        cout << "\n\n\t4. Buscar dato en la Cola.";
        cout << "\n\n\t0. Salir Programa.";
        cout << "\n\n\t   Teclee la opcion: ";
        cin >> miOpcion;
        cin.ignore();   // Limpia el buffer de entrada

        if (miOpcion < 0 || miOpcion > OPCIONES)
            cout << "\n\n\tLa opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl << endl;

    } while (miOpcion < 0 || miOpcion > OPCIONES);

    return miOpcion;
}


// Función para solicitar los valores del vector
void solicitarDatosArray (array <int, DIM> &a) {
    int n = 0;

    for (int i = 0; i < a.size(); i++ ) {
        cout << "\n\nEscribe el número que quieres introducir : ";
        cin >> n;
        a[i] = n;
    }

}


// Función para mostrar el contenido del array
void mostrarArray (const )


// Función para calcular cuántos valores del array son pares de forma iterativa
// totalValoresParesITER


// Función para calcular cuántos valores del array son pares de forma recursiva
// totalValoresParesREC


// Función para calcular cuántos valores del array son multiplos de 5 de forma iterativa
// totalValoresMultiplos5ITER


// Función para calcular cuántos valores del array son multiplos de 5 de forma recursiva
// totalValoresMultiplos5REC


// Función que determina si un determinado valor está en la cola
// buscarElementoCola

// Función que determina si un determinado valor está en la pila
// buscarElementoPila


// Función que incorpora datos en la pila
// introducirElemPila


// Función que incorpora datos en la cola
// introducirElemCola
