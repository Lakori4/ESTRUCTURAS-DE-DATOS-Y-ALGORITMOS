// Santiago Valderrama

#include <iostream>
#include <memory>
#include "Hoja 5.h"


using namespace std;


Queue::Queue(const Queue &q) {

    if (!q.empty()) {

        shared_ptr<Nodo> ptrAux = make_shared<Nodo>(Nodo(q.first->getNum(), nullptr));

        while (ptrAux != nullptr)
        {
            push(ptrAux->getNum());

            ptrAux = make_shared <Nodo> (Nodo(ptrAux->getNext()->getNum(), nullptr));
        }
    }
}

// Returns boolean value if Queue is empty or not
bool Queue::empty() const
{
    return (first == nullptr) && (end == nullptr);
}

// Enters a number at the end of the Queue
void Queue::push(int n)
{
    shared_ptr<Nodo> ptrAux = make_shared<Nodo>(Nodo(n, nullptr));

    if (!first)
    {
        first = ptrAux;
    }
    else
    {
        end->setNext(ptrAux);
    }
    end = ptrAux;
}

// Deletes the value in front of the Queue
void Queue::pop()
{
    first = first->getNext();
    if (first == nullptr)
    {
        end = nullptr;
    }
}

// Returns the value in front of the Queue
shared_ptr<Nodo> Queue::getFirst() const
{
    return first;
}

int Queue::size() const
{
    int veces = 0;
    shared_ptr <Nodo> ptrAux = first;

    while (ptrAux != nullptr)
    {
        
        veces++;

        ptrAux = ptrAux->getNext();
    }
    return veces;
}
/*




*/

int main()
{
    bool cont = true;
    Queue q;
    int n, veces = 0;
    shared_ptr<Nodo> ptrAux;

    do
    {
        switch (menu())
        {
        case 1:
            cout << "\n\nEscribe el número que quieras introducir: ";
            cin >> n;
            q.push(n);
            break;

        case 2:

            dispEmpty(q);

            if (!q.empty())
            {
                cout << "\n\nLos elementos de la cola son: ";

                ptrAux = q.getFirst();

                while (ptrAux != nullptr)
                {
                    cout << ptrAux->getNum() << ", ";
                    ptrAux = ptrAux->getNext();
                }
            }

            break;

        case 3:

            dispEmpty(q);

            if (!q.empty())
            {

                ptrAux = q.getFirst();
                n = ptrAux->getNum();

                while (ptrAux != nullptr)
                {
                    if (n < ptrAux->getNum())
                    {
                        n = ptrAux->getNum();
                    }

                    ptrAux = ptrAux->getNext();
                }
                cout << "\n\nEl elemento mayor de la cola es:  " << n;
            }

            break;

        case 4:

            dispEmpty(q);

            if (!q.empty())
            {
                cout << "Indica el número que quieres buscar: ";
                cin >> n;
                ptrAux = q.getFirst();

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
                    cout << "\n\nEl número " << n << " está en la cola.";
                } // Si la condición de arriba se ha cumlpido, se ha encontrado el número.
                else
                {
                    cout << "\n\nEl número " << n << " NO está en la cola.";
                }
            }

            veces = false; // Se devuelve al valor anterior

            break;

        case 5:

            dispEmpty(q);

            if (!q.empty())
            {

                cout << "Indica el número que quieres buscar: ";
                cin >> n;

                ptrAux = q.getFirst();

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
                    cout << "\n\nEl número \"" << n << "\" está " << veces << " veces en la cola";
                }

                else
                {
                    cout << "\n\nEl número " << n << " NO está en la cola.";
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
        Queue q2 (q);
    } while (cont);

    

    return 0;
}

int menu()
{

    int opc;
    cout << "\n\n1. Introducir numeros enteros en la Cola";
    cout << "\n2. Mostrar el contenido de la Cola";
    cout << "\n3. Elemento mayor de la Cola";
    cout << "\n4. Buscar un número de la Cola";
    cout << "\n5. Número de veces que aparece un número en la Cola";
    cout << "\n\n0. Salir";
    cout << "\n\n\n Selecciona el número correspondiente a tu opción: ";
    cin >> opc;
    
    #ifdef __linux__
    system("clear");
    #else
    system("cls");
    #endif
    
    return opc;
}

void dispEmpty(Queue const &q)
{
    if (q.empty())
    {
        cout << "\n\n\tLA COLA ESTÁ VACÍA";
    }
}