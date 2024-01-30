//Santiago Valderrama y Gina Ramírez

// CLASE Cola

#include <iostream>
#include <memory>
#include "CCliente.h"
#include "CNodo.h"
#include "TADCola.h"

using namespace std;


// Inserta un elemento en la posicion final de la cola
void Cola::push(const CCliente& dato) {
    // HACER
}

// Elimina un elemento de la primera posicion de la cola
void Cola::pop()  {
    // HACER
}

// Devuelve el elemento de la primera posicion de la cola
const CCliente &Cola::primero() const {
    return (ppio->getDato());
}

// Determina si la cola esa vacia o no
bool Cola::empty() const  {
    return (ppio == nullptr && final == nullptr);
}

void Cola::iniciarCola() {
    ppio = nullptr;
    final = nullptr;
}

// Muestra los datos de la Cola sin destruirla
void Cola::mostrarCola() const  {
  // HACER
}

void Cola::AtenderClienteVG (Lista &Loper) {
  //  HACER
}
