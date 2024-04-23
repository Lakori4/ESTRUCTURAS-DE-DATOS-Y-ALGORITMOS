// Santiago Valderrama


#include <iostream>
#include <memory>
#include "TADArbol.cpp"




using namespace std;

int menu();
void insertarNum(Arbol &A);

int main () {

    Arbol A;

    while (true) {

        switch (menu())
        {
        case 1:
            cout << "\n1. Insertar un num.\n";
            insertarNum(A);
            break;

        case 2:
            cout << "\n2. Recorrer en Inorden.\n";
            A.recorrerInOrden();
            break;
        
        case 3:
            cout << "\n3. Recorrer en Preorden.\n";
            A.recorrerPreOrden();
            break;

        case 4:
            cout << "\n4. Recorrer en Postorden.\n";
            A.recorrerPostOrden();
            break;

        case 5:
            cout << "\n5. Recorrer en Anchura.\n";
            A.recorrerAnchura();
            break;

        case 0:
            return 0;
            break;
        
        default:
            break;
        }
    }
    
}

int menu () {

    int opc;

    cout << "\n\t¡Bienvenido!\n\n¿Que quieres hacer?\n";
    cout << "1. Insertar un número.\n";
    cout << "2. Recorrer en Inorden.\n";
    cout << "3. Recorrer en Preorden.\n";
    cout << "4. Recorrer en Postorden.\n";
    cout << "5. Recorrer en Anchura.\n";

    cout << "\n0. Salir: ";
    cin >> opc;

    system("cls");

    return opc;
}

void insertarNum(Arbol &A) {

    int num;
    char lado;
    shared_ptr <Nodo> nAux = A.getRaiz();


    cout << "\nIntroduce el número: ";
    cin >> num;

    if (nAux == nullptr) { A.setRaiz(make_shared <Nodo> (num)); }

    else
    {
        do
        {            
            cout << "\nPor que lado lo quieres introducir (I/D): ";
            cin >> lado;
            
            switch (toupper(lado))
            {
            case 'I':

                if (nAux->getHizq() == nullptr){ 
                    nAux->setHizq(make_shared<Nodo> (num));
                    num = NULL;
                } 
                nAux = nAux->getHizq(); 

                break;
            
            case 'D':

                if (nAux->getHdch() == nullptr) {
                    nAux->setHdch(make_shared<Nodo> (num));
                    num = NULL;
                }
                nAux = nAux->getHdch(); 
                
                break;
            
            default:
                cout << "\n\n\tERROR: El caracter introducido no se corresponde con ningún lado.";
                break;
            }
        } while (num != NULL);
    }    
}

