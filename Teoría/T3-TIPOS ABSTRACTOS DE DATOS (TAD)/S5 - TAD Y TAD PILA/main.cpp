// Santiago Valderrama


#include <iostream>


using namespace std;

/* struct TipoDato {
    string elem;
    int aa;
}; */

class Nodo {
    private:
        int num;
        shared_ptr<Nodo> next;
    public:
        Nodo():next(nullptr){}
        Nodo(int n, shared_ptr<Nodo> const &ptr):num(n),next(ptr){}

        int getNum() const;
        void setNum(int newNum);
        shared_ptr<Nodo> getNext() const;
        void setNext(const shared_ptr<Nodo> &newNext);
};

class Stack {
    public:
        Stack():front(nullptr){}

        bool empty() const;
        void push(int num);
        void pop();
        int top() const;

    private:
        shared_ptr<Nodo> front;
};

// CLASE Nodo

void Nodo::setNext(const shared_ptr<Nodo> &newNext) {
    next = newNext;
}

int Nodo::getNum() const {
    return num;
}

void Nodo::setNum(int newDato) {
    num = newDato;
}

shared_ptr<Nodo> Nodo::getNext() const {
    return next;
}

// CLASE Pila

// Inserta un elemento en la cima de la pila
void Stack::push(int num) {
    shared_ptr<Nodo> elem = make_shared<Nodo>(Nodo(num, nullptr));

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
int Stack::top() const {
    return (front->getNum());
}

// Determina si la pila estÃ¡ vacÃ­a o no
bool Stack::empty() const  {
    return (front == nullptr);
}

int main () {

    int n1 = 1;
    int n2 = 2;

  
    
    Stack s;

    s.push(n1);

    s.push(n2);



    return 0;
}
