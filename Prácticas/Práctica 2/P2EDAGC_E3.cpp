// Santiago Valderrama


#include <iostream>
#include <vector>


using namespace std;

int menorElem (const vector <int> &v);
int main () {

    bool cont = true;


    vector <int> v;

    while (cont) {

        cout << "¿Quieres añadir un número? (0/1)";
        cin >> cont;

        if (!cont) 
            break;
        else {

            int n;

            cout << "Escribe el número que quieres añadir: ";
            cin >> n;


            v.push_back(n);
        }
        


    }


    cout << "Este es tu menor elemento: " << menorElem(v);


    return 0;
}


int menorElem (const vector <int> &v) {

    int min = 2147483647;

    for (int i = 0; i < v.size(); i++) {

        if (v[i] < min)
            min = v[i];
    }
    return min;
}

//Coste temporal: (1 + n comparaciones) * (n comparaciones * min) ) + 1