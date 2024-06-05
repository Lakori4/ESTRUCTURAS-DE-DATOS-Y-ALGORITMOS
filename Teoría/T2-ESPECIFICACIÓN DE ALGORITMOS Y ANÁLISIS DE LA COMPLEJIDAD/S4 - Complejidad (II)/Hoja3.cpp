#include <iostream>
#include <vector>

using namespace std;

void menu();

int Ej1 (int a, int d, int n);

int main() {

    menu();

    int opc, n;
    cout << "\n\nEscribe tu opción: ";
    cin >> opc;

    #ifdef __linux__
    system("clear");
    #else
    system("cls");
    #endif
       

    switch (opc)
    {
    case 1:
        Ej1(1, 3, 10); 
        break;
    
    case 2:

        break;
    
    case 3:        
        
        break;
    
    case 4:
        
        break;
    
    case 5:
        
        break;

    default:
        break;
    }
    return 0;
}

void menu () {
    cout << "\n1. Hoja 1 Ejercicio 1";
    cout << "\n2. Hoja 1 Ejercicio 2";
    cout << "\n3. Hoja 2 Ejercicio 1";
    cout << "\n4. diezValores";
    cout << "\n5. printNums";
}

int Ej1 (int a, int d, int n) {

    int a1;                         // 0 pasos

    for (int i = 0; i < n; i++)     // 1 + (n + 1) + n  
    {
        a1 = a + d;                 // n * (1 + 1)
        a = a1;                     // n * 1
    }

    return a1;                      // 1
    
}                                   //5n + 2 

