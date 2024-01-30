//SANTIAGO VALDERRAMA FLORES Y GINA ANDREA RAMIREZ GUERRERO
#ifndef TADLISTA_H
#define TADLISTA_H

#include <iostream>
#include <memory>

using namespace std;

//---------------Clase CDato
class CDato {
private:
    int vertice;
    float distancia;
public:
    CDato() :vertice(0), distancia(0) {}


    int getVertice() const;
    float getDistancia() const;
    void setVertice(int newV);
    void setDistancia(float newD);
    void setCDato(int v, float d);
};

//---------------Clase Nodo
class Nodo {
private:
    CDato dato;
    shared_ptr<Nodo> next = nullptr;
public:
    Nodo();
    Nodo(CDato const& d) : dato(d) {}

    const CDato& getDato() const;
    void setDato(const CDato& newDato);
    shared_ptr<Nodo> getNext() const;
    void setNext(const shared_ptr<Nodo>& newNext);
};

//---------------Clase Lista
class Lista {
private:
    shared_ptr<Nodo> first;
public:
    Lista() :first(nullptr) {}
    Lista(shared_ptr<Nodo> f) :first(f) {}

    const shared_ptr<Nodo>& getFirst() const;
    void setFirst(const shared_ptr<Nodo>& newFirst);

    bool empty() const;
    void listaVacia();

    void push_front(const CDato&);
    const CDato& front() const;

    void mostrarLista() const;
    float calcularDistancias() const;
};

#endif // TADLISTA_H