// Implementación de las funciones básicas miembro necesarias para
// crear un TAD Pila en dinÃ¡mica

#include <iostream>
#include <memory>
#include "TADNodo.h"
#include "TADPila.h"

using namespace std;

// CLASE Pila

// Constructor copia
Stack::Stack(const Stack &S){
   if (S.empty()){
       front = nullptr;
   }
   else{
       // Se declaran 3 punteros.
       // pNew sirve para crear el primer nodo y dejarlo fijo señalando el primer elemento de la Pila
       // pS sirve para recorrer los nodos de la pila que se quiere copiar
       shared_ptr<Nodo> pNew = make_shared<Nodo>(Nodo(S.top(), nullptr)), pAux, pS{S.front};

       // Dejamos la cima de la pila que se está copiando fijada al primer elemento creado a través de pNew
       front = pNew;

       // Se avanza en la pila que se quiere copiar
       pS=pS->getNext();

       // Bucle para procesar y copiar los diferente nodos de la pila que se quiere copiar
       while (pS!=nullptr){
           pAux = pNew;
           //Se crea un nuevo nodo
           pNew=make_shared<Nodo>(Nodo(pS->getDato(), nullptr));
         //  pNew->setDato(pS->getDato());
         //  pNew->setNext(nullptr);

           // Se enlazan los dos nodos
           pAux->setNext(pNew);
           // Se avanza en la pila que se quiere copiar
           pS=pS->getNext();
       }
   }
}

// Inserta un elemento en la cima de la pila
void Stack::push(const TipoDato& dato) {
    shared_ptr<Nodo> elem = make_shared<Nodo>(Nodo(dato, nullptr));

    if (front != nullptr) {
        elem->setNext(front);
    }
    front = elem;  // La pila debe seÃ±alar siempre al elemento incluido
}

// Elimina un elemento en la cima de la pila
void Stack::pop()  {
    front = front->getNext();
}

// Devuelve el elemento cima de la pila
const TipoDato &Stack::top() const {
    return (front->getDato());
}

// Determina si la pila estÃ¡ vacÃ­a o no
bool Stack::empty() const  {
    return (front == nullptr);
}

// Muestra los datos de la pila sin destruirla
void Stack::mostrarPila() const{
    shared_ptr<Nodo> paux{front};

    while (paux != nullptr) {
        cout << " " << paux->getDato().num;
        paux = paux->getNext();
    }
}

// Destructor
Stack::~Stack() {
    while (!empty()){
        pop();
    }
}
