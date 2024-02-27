#ifndef HOJA4_H
#define HOJA4_H

#include <iostream>
#include <vector>

//using namespace std;

int menu();

class Stack {
    private:
        int front; // El puntero debe señalar siempre al primer elemento
        std::vector <int> pila;
    
    public:
        Stack() : front(-1) {}

        bool empty() const;
        void push(int num);
        void pop();
        void clear();
        int top() const;
};

#endif