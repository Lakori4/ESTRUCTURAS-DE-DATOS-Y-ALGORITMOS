// Santiago Valderrama


#include <iostream>


using namespace std;

class Nodo { 
    private:
    int numero;
    shared_ptr<Nodo> hizq = nullptr; 
    shared_ptr<Nodo> hdch = nullptr;

public:

    Nodo (const int n) : numero {n} {};

    const int &getNum () const {return numero;}
    void setNum (const int &newNum) {numero = newNum;}

    const shared_ptr<Nodo> &getHizq() const {return hizq;}
    void setHizq (const shared_ptr<Nodo> &newHizq) {hizq = newHizq;}

    const shared_ptr<Nodo> &getHdch() const {return hdch;}
    void setHdch(const shared_ptr<Nodo> &newHdch) {hdch = newHdch;}

    void procesarNodo () const {cout << numero;}
};



class Arbol { 
    
    private:
    shared_ptr<Nodo> raiz;

    public:

    Arbol():raiz (nullptr){}; 
    Arbol (int const numero);

    bool empty() const;

    void addHizq (Arbol const &Ni); 
    void addHdch (Arbol const &Nd);

    int const &getNumNodo () const; 
    const shared_ptr<Nodo> &getHiNodo () const; 
    const shared_ptr<Nodo> &getHdNodo () const;

    void construirArbol (Arbol const &Ai, Arbol const &Ad, int const &numero);

    void InOrden (shared_ptr<Nodo> A) const;
};
  
Arbol::Arbol (int const numero) {
    raiz->setNum(numero);
}

bool Arbol::empty() const {
    return (raiz == nullptr);
}

int const & Arbol::getNumNodo () const {
    return raiz->getNum();
}

void Arbol::addHizq(Arbol const &Ai) {
    raiz->setHizq(Ai.raiz);
}

void Arbol::addHdch(Arbol const &Ad) {
    raiz->setHdch(Ad.raiz);
}

const shared_ptr<Nodo> &Arbol::getHiNodo () const {
    return raiz->getHizq();
}

const shared_ptr<Nodo> &Arbol::getHdNodo () const {
    return raiz->getHdch();
}

void Arbol::construirArbol(Arbol const &Ai, Arbol const &Ad, int const &numero) {
    raiz = make_shared<Nodo>(numero);
    raiz->setHizq(Ai.raiz);
    raiz->setHdch(Ad.raiz);
}

void Arbol::InOrden(shared_ptr <Nodo> A) const {

    shared_ptr<Nodo> Ai, Ad;
    int num;

    if (A != nullptr) {

        Ai = A->getHizq();
        Ad = A->getHdch();
        num = A->getNum();

        InOrden(Ai);
        A->procesarNodo();
        InOrden(Ad);
    }
}

int main () {

    Arbol A (9) ;
    A
    return 0;
}

