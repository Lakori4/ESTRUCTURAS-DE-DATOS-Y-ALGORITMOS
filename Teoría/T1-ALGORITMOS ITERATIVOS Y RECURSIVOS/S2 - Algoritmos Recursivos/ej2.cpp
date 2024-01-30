#include <iostream>

using namespace std;

int menu (); 

int ite (int n1, int n2);

int rec (int res, int n1, int n2);

int main () {

    int n1, n2;
    int pro;
    while (true) {

        switch (menu()) {

            case 1:

                do {
                    cout << "\nEscribe un número natural: ";
                    cin >> n1;

                    cout << "\nEscribe otro número natural: ";
                    cin >> n2;

                    if (n1 >= 0 && n2 >= 0) {

                        pro = ite(n1, n2);
                    }

                    cout << "\nEl producto de los números naturales que has escrito es: " << pro << endl;
                    
                } while (n1 >= 0 && n2 >= 0);

                

                break;
            
            case 2:

                do {
                    cout << "\nEscribe un número natural: ";
                    cin >> n1;

                    cout << "\nEscribe otro número natural: ";
                    cin >> n2;

                    if (n1 >= 0 && n2 >= 0) {

                        pro = rec(0, n1, n2);
                    }

                    cout << "\nEl producto de los números naturales que has escrito es: " << pro << endl;

                } while (n1 >= 0 && n2 >= 0);



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

    cout << "Escoge una de estas opciones.\n\n\t1. Producto de números naturales iterativa\n\t2. Producto de números naturales recursiva\n\t3. Salir\n";
    cin >> n;

    return n;
}

int ite (int n1, int n2) {

    int pro = 0;
    for (int i = 0; i < n2; i++) {

        pro = pro + n1;
    }

    return pro;

}

int rec (int res, int n1, int n2) {   

    if (res != n1 * n2) {

        res = rec (res + n1, n1, n2);
    }

    else {

        return res;
    }
}