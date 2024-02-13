#include <iostream>
#include <vector>

using namespace std;

void menu();

void Ej1();
void Ej2();

int sumaRec(int res, int suma, int n);
int proRec (int res, int n1, int n2);


int main() {

    menu();

    int opc, n;
    cout << "\n\nEscribe tu opción: ";
    cin >> opc;

    system("cls");
   

    switch (opc)
    {
    case 1:
        Ej1();
        break;
    
    case 2:
        Ej2();
        break;
    
    case 0:
        return 0;
        break;

    default:
        break;
    }
    return 0;
}

void menu () {
    cout << "\n1. Ejercicio 1";
    cout << "\n2. Ejercicio 2";
    cout << "\n0. Salir";
}

void Ej1() {

    int n, suma = 1;
        do
        {
            cout << "\nEscribe un número natural: ";
            cin >> n;

            if (n > 0) for (int i = 0; i < n; i++) suma++;

        } while (n > 0);

        cout << "\nLa suma iterativa de todos los números naturales que has escrito es: " << suma << endl;

        suma = 0;
        do
        {
            cout << "\nEscribe un número natural: ";
            cin >> n;

            if (n > 0) suma = sumaRec(0, suma, n);
            

        } while (n > 0);

        cout << "\nLa suma recursiva de todos los números naturales que has escrito es: " << suma << endl;
}

int sumaRec(int res, int suma, int n) {
    if (res != suma + n) res = sumaRec(res + 1, suma, n);

    else return res;
    
}

void Ej2 () {

    int n1, n2, pro = 0;

    do {
        cout << "\nEscribe un número natural: ";
        cin >> n1;

        if (n1 <= 0) break;
        
        cout << "\nEscribe otro número natural: ";
        cin >> n2;

        if (n1 >= 0 && n2 >= 0)  for (int i = 0; i < n2; i++) pro = pro + n1;
        
    } while (n1 > 0 && n2 > 0);

    cout << "\nEl producto iterativo de los números naturales que has escrito es: " << pro << endl;

    do {

        cout << "\nEscribe un número natural: ";
        cin >> n1;

        if (n1 <= 0) break;

        cout << "\nEscribe otro número natural: ";
        cin >> n2;

        if (n1 >= 0 && n2 >= 0) pro = proRec(0, n1, n2);

    } while (n1 >= 0 && n2 >= 0);

    cout << "\nEl producto recursivo de los números naturales que has escrito es: " << pro << endl;
}

int proRec (int res, int n1, int n2) {   

    if (res != n1 * n2) res = proRec (res + n1, n1, n2);
    
    else return res;
    
}