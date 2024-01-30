//  PRÁCTICA N.5 EDA
//SANTIAGO VALDERRAMA FLORES Y GINA ANDREA RAMIREZ GUERRERO
#include <iostream>
#include "TADLista.h"
#include "TADGrafo.h"

using namespace std;

int main()
{
    Grafo G;
    Lista L;
    CDato elem;

    //  CREACIÓN DEL GRAFO CON 5 NODOS Y SUS CORRESPONDIENTES NODOS ADYACENTES
    G.incluirVertice(0, "Segovia");
    // Nodos adyacentes al vertice Segovia: 2/562.0 y 3/88.0
    elem.setCDato(3, 88.0);
    L.push_front(elem);
    elem.setCDato(2, 562.0);
    L.push_front(elem);
    G.incluirAdyacentes(0, L);

    G.incluirVertice(1, "Barcelona");
    // Nodos adyacentes al vertice Barcelona: 4/349.0 2/2.0 y 3/626.0
    L.listaVacia();
    elem.setCDato(3, 626.0);
    L.push_front(elem);
    elem.setCDato(4, 349.0);
    L.push_front(elem);
    G.incluirAdyacentes(1, L);

    G.incluirVertice(2, "Sevilla");
    // Nodos adyacentes al vertice Sevilla: 3/534.0 4/655.0 y 0/562.0
    L.listaVacia();
    elem.setCDato(3, 534.0);
    L.push_front(elem);
    elem.setCDato(4, 655.0);
    L.push_front(elem);
    elem.setCDato(0, 562.0);
    L.push_front(elem);
    G.incluirAdyacentes(2, L);

    G.incluirVertice(3, "Madrid");
    // Nodos adyacentes al vertice Madrid: 1/626.0 0/88.0 2/534.0y 4/359.0
    L.listaVacia();
    elem.setCDato(1, 626.0);
    L.push_front(elem);
    elem.setCDato(0, 88.0);
    L.push_front(elem);
    elem.setCDato(2, 534.0);
    L.push_front(elem);
    elem.setCDato(4, 359.0);
    L.push_front(elem);
    G.incluirAdyacentes(3, L);

    G.incluirVertice(4, "Valencia");
    // Nodos adyacentes al vertice Valencia: 2/655.0 1/349.0 y 3/359.0
    L.listaVacia();
    elem.setCDato(2, 655.0);
    L.push_front(elem);
    elem.setCDato(1, 349.0);
    L.push_front(elem);
    elem.setCDato(3, 359.0);
    L.push_front(elem);
    G.incluirAdyacentes(4, L);

    //  MOSTRAR EL CONTENIDO DEL GRAFO
    G.mostrarGrafo();

    //  RECORRIDO DEL GRAFO PARTIENDO DE UN DETERMINADO LUGAR
    cout << "\n\n\tRecorrido desde Madrid: ";
    G.recorrerProfundidad(3);

    //  LUGAR CON MAYOR NÚMERO DE KM DE CONEXIÓN DIRECTA
    cout << "\n\tEl lugar con la mayor cantidad de km de conexion directa es: " << G.getLugarMaxDistanciasAdyac();

    cout << "\n\n\t";
    return 0;
}