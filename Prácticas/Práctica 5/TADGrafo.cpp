//SANTIAGO VALDERRAMA FLORES Y GINA ANDREA RAMIREZ GUERRERO
#include <iostream>
#include <string>
#include <array>
#include <set>
#include "TADLista.h"
#include "TADGrafo.h"

using namespace std;

//--------------------Clase VerticeG
const string& VerticeG::getLugar() const {
    return lugar;
}

void VerticeG::setLugar(const string& newLugar) {
    lugar = newLugar;
}

shared_ptr<Nodo> VerticeG::getNext() const {
    return next;
}

void VerticeG::setNext(const shared_ptr<Nodo>& newNext) {
    next = newNext;
}

//--------------------Clase Grafo
// COMPLETAR
Grafo::Grafo() {
    for (int i = 0; i < nMax; ++i) {
        cArcos[i] = VerticeG();
    }

}

void Grafo::incluirVertice(int v, string const& l) {
    cArcos.at(v).setLugar(l);
}

// COMPLETAR
void Grafo::incluirAdyacentes(int v, Lista const& ady) {
    shared_ptr<Nodo> currentNodo = ady.getFirst();
    cArcos[v].setNext(currentNodo);

}

//COMPLETAR
// Mostrar los nodos del grafo, cada vértice (nombre del lugar) con sus adyacentes (v�rtice y distancia)
void Grafo::mostrarGrafo() const {
   
    for (int i = 0; i < nMax; i++) {
        // imprimir el lugar del vértice
        cout << "Lugar del vertice " << i << ": " << cArcos[i].getLugar() << endl;

        cout << endl;
        auto ady = cArcos[i].getNext();
        while (ady != nullptr) {
            // imprimir el vértice adyacente y su distancia
            cout << "\n\tAdyacente: " << ady->getDato().getVertice() << ", distancia: " << ady->getDato().getDistancia() << endl;

            ady = ady->getNext();
        }
        cout << endl;
    }
}




//COMPLETAR
// Realiza el recorrido del grafo partiendo de un determinado nodo y muestra en qu� orden se visitan los nodos (lugares)
void Grafo::profundidadRec(set<int>& visitados, int V) {

    
    visitados.insert(V);

    cout << "\n\tEl vertice " << visitados.size() << " visitado es " << cArcos[V].getLugar() << endl;

    shared_ptr<Nodo> actual = cArcos[V].getNext();
    while (actual != nullptr) {
        int ady = actual->getDato().getVertice();

        if (visitados.find(ady) == visitados.end()) {
            profundidadRec(visitados, ady);
        }
        actual = actual->getNext();
    }
}



//COMPLETAR
// Determina el lugar (nodo o vértice) del grafo cuya suma de distancias a sus adyacentes es mayor
string Grafo::getLugarMaxDistanciasAdyac() const {
    string lugarMaxDist;
    float maxDist = 0.0;

    for (int i = 0; i < nMax; i++) {
        shared_ptr<Nodo> actual = cArcos[i].getNext();
        float distancias = 0.0;
        while (actual != nullptr) {
            distancias += actual->getDato().getDistancia();
            actual = actual->getNext();
        }

        if (distancias > maxDist) {
            maxDist = distancias;
            lugarMaxDist = cArcos[i].getLugar();
        }
    }

    return lugarMaxDist;

}

//COMPLETAR
// Método que llama al proceso recursivo para recorrer el grafo
void Grafo::recorrerProfundidad(int V) {
    set<int> visitados; 
    profundidadRec(visitados, V);

}
