#include <iostream> 

using namespace std;


int main() {

    int num = 0;
    int resp;

    do {

        cout << "Escribe un número positivo: ";
        cin >> resp;

        if (resp < 0) {break;}

        num = num + resp;
    } while  (resp >= 0);   

    cout << "La suma de todos los números que has escrito es " << num << ".\n";

    return 0;
}

void suma