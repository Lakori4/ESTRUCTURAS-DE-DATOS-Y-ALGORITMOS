#include <iostream>

using namespace std;

int menu (); 

int ite (int suma, int n);

int rec (int res, int suma, int n);

int main () {

    int n;
    int suma;
    while (true) {

        switch (menu()) {

            case 1:

                suma = 1;
                do {
                    cout << "\nEscribe un número natural: ";
                    cin >> n;

                    if (n >= 0) {

                        suma = ite(suma, n);
                    }


                } while (n > 0);

                cout << "\nLa suma de todos los números naturales que has escrito es: " << suma << endl;

                break;
            
            case 2:

                suma = 0;
                do {
                    cout << "\nEscribe un número natural: ";
                    cin >> n;

                    if (n > 0) {

                        suma = rec(0, suma, n);
                    }


                } while (n >= 0);

                cout << "\nLa suma de todos los números naturales que has escrito es: " << suma << endl;

                break;

            case 3: 

                return 0;

                break;

            default:

                system("cls");
                break;
        }
    }    
}


int menu () {

    int n;

    cout << "Escoge una de estas opciones.\n\n\t1. Suma de números naturales iterativa\n\t2. Suma de números naturales recursiva\n\t3. Salir\n";
    cin >> n;

    return n;
}

int ite (int suma, int n) {

    for (int i = 0; i < n; i++) {

        suma++;
    }

    return suma;

}

int rec (int res, int suma, int n) {   

    if (res != suma + n) {

        res = rec (res + 1, suma, n);
    }

    else {

        return res;
    }
}