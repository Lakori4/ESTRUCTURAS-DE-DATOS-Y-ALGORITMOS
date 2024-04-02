// Santiago Valderrama

#include <iostream>
#include <vector>
#include "Hoja 4.h"
#include "Teoría\T3-TIPOS ABSTRACTOS DE DATOS (TAD)\Nodo.h"

using namespace std;

// Inserta un elemento en la cima de la pila
void Stack::push(int num)
{
    shared_ptr<Nodo> elem = make_shared<Nodo>(Nodo(num, nullptr));

    if (front != nullptr)
    {
        elem->setNext(front);
    }
    front = elem; // La pila debe señalar siempre al elemento incluido
}

// Elimina un elemento en la cima de la pila
void Stack::pop()
{
    front = front->getNext();
}

// Devuelve el elemento cima de la pila
shared_ptr<Nodo> Stack::getTop() const
{
    return (front);
}

// Determina si la pila estÃ¡ vacÃ­a o no
bool Stack::empty() const
{
    return (front == nullptr);
}

/*




*/

int main()
{
    bool cont = true;
    Stack s;
    int n, veces = 0;
    shared_ptr<Nodo> ptrAux;

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

            dispEmpty(s);

            if (!s.empty())
            {
                cout << "\n\nLos elementos de la pila son: ";

                ptrAux = s.getTop();

                while (ptrAux != nullptr)
                {
                    cout << ptrAux->getNum() << ", ";
                    ptrAux = ptrAux->getNext();
                }
            }

            break;

        case 3:

            dispEmpty(s);

            if (!s.empty())
            {

                ptrAux = s.getTop();
                n = ptrAux->getNum();

                while (ptrAux != nullptr)
                {
                    if (n < ptrAux->getNum())
                    {
                        n = ptrAux->getNum();
                    }

                    ptrAux = ptrAux->getNext();
                }
                cout << "\n\nEl elemento mayor de la pila es:  " << n;
            }

            break;

        case 4:

            dispEmpty(s);

            if (!s.empty())
            {
                cout << "Indica el número que quieres buscar: ";
                cin >> n;
                ptrAux = s.getTop();

                while (ptrAux != nullptr)
                {
                    if (n == ptrAux->getNum())
                    {
                        veces = true;
                    }

                    ptrAux = ptrAux->getNext();
                }

                if (veces)
                {
                    cout << "\n\nEl número " << n << " está en la pila.";
                } // Si la condición de arriba se ha cumlpido, se ha encontrado el número.
                else
                {
                    cout << "\n\nEl número " << n << " NO está en la pila.";
                }
            }

            veces = false; // Se devuelve al valor anterior

            break;

        case 5:

            dispEmpty(s);

            if (!s.empty())
            {

                cout << "Indica el número que quieres buscar: ";
                cin >> n;

                ptrAux = s.getTop();

                while (ptrAux != nullptr)
                {
                    if (n == ptrAux->getNum())
                    {
                        veces++;
                    }

                    ptrAux = ptrAux->getNext();
                }
                if (veces > 0)
                {
                    cout << "\n\nEl número \"" << n << "\" está " << veces << " veces en la pila";
                }

                else
                {
                    cout << "\n\nEl número " << n << " NO está en la pila.";
                }
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

void dispEmpty(Stack const &s)
{
    if (s.empty())
    {
        cout << "\n\n\tLA PILA ESTÁ VACÍA";
    }
}