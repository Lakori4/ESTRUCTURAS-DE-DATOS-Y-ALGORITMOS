// Implementación de las funciones básicas miembro necesarias para
// crear un TAD Cola en dinámica

#include <iostream>
#include <memory>
#include "TADNodo.h"
#include "TADCola.h"


using namespace std;

// CLASE Cola

// Inserta un elemento en la posición final de la cola
void Cola::push(const TipoDato& dato) {
    shared_ptr<Nodo> ptraux = make_shared<Nodo>(Nodo(dato, nullptr));

    if (empty()) {
        front = ptraux;
    }
    else  {
        end->setNext(ptraux);
    }
    // El puntero final de la cola debe señalar siempre al elemento incluido
    end = ptraux;
}

// Elimina un elemento de la primera posición de la cola
void Cola::pop()  {
    front = front->getNext();
    if (front == nullptr) {
        end = nullptr;  // La cola queda vacía
    }
}

// Devuelve el elemento de la primera posición de la cola
const TipoDato &Cola::first() const {
    return (front->getDato());
}

// Determina si la cola está vacía o no
bool Cola::empty() const  {
    return (front == nullptr && end == nullptr);
}

// Constructor Copia
Cola::Cola(const Cola &Q){
    if (Q.empty()) {
        front = nullptr;
        end = nullptr;
    }
    else {
        shared_ptr<Nodo> ptrNew = make_shared<Nodo>(Nodo(Q.front->getDato(), nullptr)), pS{Q.front};

        end = ptrNew;
        front = ptrNew;

        // Se avanza en la cola que se quiere copiar
        pS=pS->getNext();

        // Bucle para procesar y copiar los diferente nodos de la pila que se quiere copiar
        while (pS!=nullptr){
            //Se crea un nuevo nodo
            ptrNew=make_shared<Nodo>(Nodo(pS->getDato(), nullptr));
          //  ptrNew->setDato(pS->getDato());
          //  ptrNew->setNext(nullptr);

            // Se enlazan los dos nodos
            end->setNext(ptrNew);
            end=ptrNew;
            pS=pS->getNext();
        }
    }
}

// Muestra los datos de la cola sin destruirla
void Cola::mostrarCola() const{
    shared_ptr<Nodo> paux{front};

    while (paux != nullptr) {
        cout << " " << paux->getDato().num;
        paux = paux->getNext();
    }
}

// Destructor
Cola::~Cola(){
    while (!empty()){
      pop();
    }
}
