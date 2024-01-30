//SANTIAGO VALDERRAMA FLORES Y GINA ANDREA RAMIREZ GUERRERO
#ifndef TADGRAFO_H
#define TADGRAFO_H

#include <iostream>
#include <string>
#include <array>
#include <set>
#include "TADLista.h"

// Número de nodos del Grafo
#define nMax 5

using namespace std;

//---------------Clase VerticeG
class VerticeG {
private:
    string lugar;
    shared_ptr<Nodo> next = nullptr;
public:
    VerticeG() :lugar("") {}
    VerticeG(string const& l) : lugar(l) {}

    const string& getLugar() const;
    void setLugar(const string& newLugar);
    shared_ptr<Nodo> getNext() const;
    void setNext(const shared_ptr<Nodo>& newNext);
};

class Grafo {
private:
    array<VerticeG, nMax> cArcos;
public:
    Grafo();

    void incluirVertice(int v, string const& l);
    void incluirAdyacentes(int v, Lista const& ady);

    void mostrarGrafo() const;

    void profundidadRec(set<int>& visitados, int V);
    void recorrerProfundidad(int V);

    string getLugarMaxDistanciasAdyac() const;


};

#endif // TADGRAFO_H