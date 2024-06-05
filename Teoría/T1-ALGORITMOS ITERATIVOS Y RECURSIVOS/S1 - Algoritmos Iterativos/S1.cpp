#include <iostream> 
#include <array>
#include <vector>

using namespace std;


void menu();
void suma();
void media();
void mediaPar();
void diezValores();
void printNums();
void sumaNums();
void checkNum();



int main() {

    menu();

    int opc;
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
        suma();
        break;
    
    case 2:
        media();
        break;
    
    case 3:
        mediaPar();
        break;
    
    case 4:
        diezValores();
        break;
    
    case 5:
        printNums();
        break;

    default:
        break;
    }
    return 0;
}

void menu () {
    cout << "\n1. Suma";
    cout << "\n2. Media";
    cout << "\n3. MediaPar";
    cout << "\n4. diezValores";
    cout << "\n5. printNums";
}

void suma () {
    
    int num = 0;
    int resp;

    do {

        cout << "Escribe un número positivo: ";
        cin >> resp;

        if (resp < 0) {break;}

        num = num + resp;
    } while  (resp >= 0);   

    cout << "La suma de todos los números que has escrito es " << num << ".\n";
}

void media () {
    
    int i = 0;
    int num = 0;
    int resp;

    do {

        cout << "Escribe un número positivo: ";
        cin >> resp;

        if (resp < 0) {break;}

        num = num + resp;
        i++;
    } while  (resp >= 0);   

    cout << "La media de la suma de todos los números que has escrito es " << num / i << ".\n";
}

void mediaPar ()  {

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
}

void diezValores() {
    
    array <int, 10> aNums;

    for (int i = 0; i < aNums.size(); i++) {
        cout << "Escribe un número: ";
        cin >> aNums[i];
    }

    cout << "\nContenido del array: ";
    for (int n : aNums) {
        cout << n << ", " ;
    }
}

void printNums() {

    int num = 0, resp;

    vector <int> vNums;

    do {

        cout << "Escribe un número positivo: ";
        cin >> resp;

        if (resp < 0) {break;}

        vNums.push_back(resp);
        num = num + resp;

    } while  (resp >= 0);  
}
