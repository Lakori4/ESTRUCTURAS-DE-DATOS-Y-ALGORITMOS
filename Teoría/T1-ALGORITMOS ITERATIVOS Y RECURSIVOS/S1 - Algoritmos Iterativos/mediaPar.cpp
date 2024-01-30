#include <iostream> 

using namespace std;


int main() {

    int i = 0;
    int num = 0;
    int resp;

    do {

        cout << "Escribe un número positivo: ";
        cin >> resp;

        if (resp < 0) {break;}

        if (resp % 2 == 0) num = num + resp;
        i++;
    } while  (resp >= 0);   

    cout << "La media de la suma de todos los números que has escrito es " << num / i << ".\n";

    return 0;
}