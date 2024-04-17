#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <memory>

using namespace std;

class Nodo
{
private:
    int num;
    shared_ptr<Nodo> next;

public:
    Nodo() : next(nullptr) {}
    Nodo(int n, shared_ptr<Nodo> ptr) : num(n), next(ptr) {}

    int getNum() { return num; }
    void setNum(int n) { num = n; }
    shared_ptr<Nodo> getNext() { return next; }
    void setNext(const shared_ptr <Nodo> &n) { next = n; } 
};


#endif