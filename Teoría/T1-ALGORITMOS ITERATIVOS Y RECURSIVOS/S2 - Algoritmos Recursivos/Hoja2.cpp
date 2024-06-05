#include <iostream>
#include <vector>

using namespace std;

void menu();

void H1E1();
void H1E2();
int H2E1Ite(int n);
int H2E1Rec(int n);

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
        //H1E1();s
        break;
    
    case 2:
        //H1E2();
        break;
    
    case 3:
        do
        {
            cout << "Indica el número del término que quieres calcular entre 0 y 25: ";
            cin >> n;
            if (n > -1) {
                cout << "Término calculado de forma iterativa: " << H2E1Ite(n) << "\n";
                cout << "Término calculado de forma recursiva: " << H2E1Rec(n) << "\n";
                }

        } while (n > -1);
        
        
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

int H2E1Ite(int n) {
    
    vector <int> v = {1, 3};

    for (int i = 2; i <= n; i++) {
        v.push_back(v[i-2] - 2*v[i-1]);
    }

    return v[n];
}

int H2E1Rec(int n) {
    if (n == 0) return 1;
    if (n == 1) return 3;
    else
    {
        return H2E1Rec(n-2) - 2* H2E1Rec(n-1);
    }
    
}