#ifndef HOJA4_H
#define HOJA4_H

#include <iostream>
#include <memory>
#include "Teoría/T3-TIPOS ABSTRACTOS DE DATOS (TAD)/Nodo.h"

using namespace std;



class Queue
{
private:
    shared_ptr<Nodo> first, end;
public:
    Queue(): first(nullptr), end(nullptr){}
    Queue(const Queue &q);
    
    bool empty() const;
    void push (int n);
    void pop(); //NO HAY USOS
    shared_ptr <Nodo> getFirst () const;
    int size() const; //NO HAY USOS
};


int menu();
void dispEmpty(Queue const &s);

#endif