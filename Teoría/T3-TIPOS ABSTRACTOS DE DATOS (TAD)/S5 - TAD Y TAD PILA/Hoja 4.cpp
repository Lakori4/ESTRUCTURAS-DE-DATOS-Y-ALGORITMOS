// Santiago Valderrama

#include <iostream>
#include <vector>
#include "Hoja 4.h"

using namespace std;

/*
CLASE Pila
*/ 

// Inserta un elemento en la cima de la pila
void Stack::push(int num)
{
    pila.push_back(num);

    front++; 
}

// Elimina un elemento en la cima de la pila
void Stack::pop()
{
    pila.pop_back();
    front--;
}

// Devuelve el elemento cima de la pila
int Stack::top() const
{
    if (empty())
    {
        throw -1;
    }

    return (pila.back());
}

// Vacía la pila
void Stack::clear()
{
    front = -1;
    pila.clear();
}

// Determina si la pila está vací­a o no
bool Stack::empty() const
{
    return (front == -1);
}

int main()
{
    bool cont = true;
    Stack s, aux;
    int n, veces = 0;

    do
    {
        switch (menu())
        {
        case 1:
            cout << "\n\nEscribe el número que quieras introducir: ";
            cin >> n;
            s.push(n);
            break;

        case 2:
            cout << "\n\nLos elementos de la pila son: ";

            if (s.empty())
            {
                cout << "\n\n\tLA PILA ESTÁ VACÍA";
                break;
            }

            while (!s.empty())
            {
                cout << s.top() << ", ";
                aux.push(s.top());
                s.pop();
            }

            while (!aux.empty())
            {
                s.push(aux.top());
                aux.pop();
            }

            break;

        case 3:

            n = s.top();

            if (s.empty())
            {
                cout << "\n\n\tLA PILA ESTÁ VACÍA";
                break;
            }

            while (!s.empty())
            {

                if (s.top() > n)
                {
                    n = s.top();
                }

                aux.push(s.top());
                s.pop();
            }

            while (!aux.empty())
            {
                s.push(aux.top());
                aux.pop();
            }

            cout << "\n\nEl elemento mayor de la pila es:  " << n;

            break;

        case 4:

            cout << "Indica el número que quieres buscar: ";
            cin >> n;

            if (s.empty())
            {
                cout << "\n\n\tLA PILA ESTÁ VACÍA";
                break;
            }

            while (!s.empty())
            {

                if (s.top() == n)
                {
                    veces = true; //Se usa esta variable para ahorrar memoria
                }

                aux.push(s.top());
                s.pop();
            }

            if (veces) { cout << "\n\nEl número " << n << " está en la pila."; } //Si la condición de arriba se ha cumlpido, se ha encontrado el número.
            else { cout << "\n\nEl número " << n << " NO está en la pila."; }

            veces = false; //Se devuelve al valor anterior

            while (!aux.empty())
            {
                s.push(aux.top());
                aux.pop();
            }
            break;

        case 5:

            cout << "Indica el número que quieres buscar: ";
            cin >> n;

            if (s.empty())
            {
                cout << "\n\n\tLA PILA ESTÁ VACÍA";
                break;
            }

            while (!s.empty())
            {

                if (s.top() == n)
                {
                    veces++;
                }

                aux.push(s.top());
                s.pop();
            }
            if (veces > 0)
            {
                cout << "\n\nEl número \"" << n << "\" está " << veces << " veces en la pila";
            }

            else
            {
                cout << "\n\nEl número " << n << " NO está en la pila.";
            }

            while (!aux.empty())
            {
                s.push(aux.top());
                aux.pop();
            }
            break;

        case 0:
            cont = false;
            break;

        default:
            cout << "\n\nEL NÚMERO NO SE CORRESPONDE CON NINGUNA OPCIÓN.";
            break;
        }
    } while (cont);

    return 0;
}

int menu()
{

    int opc;
    cout << "\n\n1. Introducir numeros enteros en la Pila";
    cout << "\n2. Mostrar el contenido de la Pila";
    cout << "\n3. Elemento mayor de la Pila";
    cout << "\n4. Buscar un número de la Pila";
    cout << "\n5. Número de veces que aparece un número en la Pila";
    cout << "\n\n0. Salir";
    cout << "\n\n\n Selecciona el número correspondiente a tu opción: ";
    cin >> opc;
    system("cls");
    return opc;
}