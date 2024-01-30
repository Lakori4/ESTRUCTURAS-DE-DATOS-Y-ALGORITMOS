//Santiago Valderrama y Gina Ramírez
#ifndef TADABB_H
#define TADABB_H

#include <iostream>
#include <memory>
#include "NodoABB.h"

//---------------Clase Arbol Binario Busqueda
class Arbol {
   private:
      shared_ptr<Nodo> raiz = nullptr;
   public:
      Arbol() {}

      const shared_ptr<Nodo> &getRaiz() const { return raiz; }
      void setRaiz(const shared_ptr<Nodo> &newRaiz) { raiz = newRaiz; };

      bool empty() const;

      void addHizq(Arbol const &Ai);
      void addHdch(Arbol const &Ad);

      void crearABBIter(int dato);

      void crearABBRec(int dato);

      void mostrar() const;

      int contarValorABBRec(int valor);

      int sumarABBIter(); 
};

#endif // TADABB_H