// Santiago Valderrama y Gina Ramírez


#include <iostream>
#include <string>


using namespace std;

class CLibro
{
private:
    string titulo;
    int pvp;
public:
    CLibro(): titulo(""), pvp(0) {}
    CLibro(string const &t, int p): titulo(t), pvp(p){}

    const string &getTitulo() const;
    void setTítulo(const string &newTitulo);
    int getPvp() const;
    void setPvp(int newPvp);
};

const string &CLibro::getTitulo() const {

    return titulo;
}

int CLibro::getPvp() const {

    return pvp;
}

void CLibro::setTítulo (const string &newTitulo) {
    titulo = newTitulo;
}

void CLibro::setPvp (int newPvp) {
    pvp = newPvp;
}




class Nodo
{
private:
    CLibro dato;
    shared_ptr<Nodo> next;
public:
    Nodo(): next(nullptr){}
    Nodo(CLibro const &d, shared_ptr<Nodo> const &ptr): dato(d), next (ptr){}

    const CLibro &getDato() const;
    void setDato (const CLibro &newDato);
    shared_ptr<Nodo> getNext() const;
    void setNext (const shared_ptr <Nodo> &newNext);
    
};

const CLibro &Nodo::getDato() const
{
    return dato;
}

shared_ptr <Nodo> Nodo::getNext() const
{
    return next;
}


void Nodo::setDato (const CLibro&newDato) {

    dato = newDato;
}


void Nodo::setNext (const shared_ptr <Nodo> &newNext) {

    next = newNext;
}





class Cola
{
private:
    shared_ptr<Nodo> first, end;
public:
    Cola(): first(nullptr), end(nullptr){}

    bool empty() const;
    void push (const CLibro &dato);
    void pop ();
    const CLibro & front () const;    

    void mostrarCola() const;
};

bool Cola::empty () const {

    if (first == nullptr && end == nullptr) {
        return true;
    }

    else {
        return false;
    }
}



 void Cola::push (const CLibro &dato) {

    shared_ptr <Nodo> newNodo = make_shared <Nodo>(Nodo(dato, nullptr));

    if (end != nullptr)
        end -> setNext(newNodo);
    
    end = newNodo;
    
    if (first == nullptr) {

        first = newNodo;
    }
} 

void Cola::pop () {

    if (first -> getNext() != nullptr)
        first = first -> getNext();
    
    else {
        end = nullptr;
        first = nullptr;
    }
}

const CLibro & Cola::front () const {

    return first -> getDato();
}

void Cola::mostrarCola() const {

    shared_ptr<Nodo> p1 = first;

    while (p1 != nullptr) {
        cout << "\tTítulo: " << p1->getDato().getTitulo() << "\n\tPrecio: " << p1->getDato().getPvp() << "\n\n";
        p1 = p1->getNext();
    }
}




int importe (Cola &c);

int main () {

    cout << "Hello World!" << endl;

    Cola c1;
    
    string t;
    int p;

    while (p != 0) {

        cin >> t;
        cin >> p;

        CLibro l (t,p);

        c1.push(l);

    }


    cout << "Importe: " << importe(c1);


    
    return 0;
}


int importe (Cola &c) {

    Cola Q;

    int suma = 0;

    while (c.empty() != true) {

        Q.push(c.front());
        suma = suma + c.front().getPvp();
        c.pop();
    }

    while (Q.empty() != true) {

        c.push(Q.front());
        Q.pop();
    }


    return suma;
}