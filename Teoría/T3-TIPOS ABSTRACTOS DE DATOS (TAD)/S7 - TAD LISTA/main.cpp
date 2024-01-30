// Santiago Valderrama


#include <iostream>


using namespace std;

class CDato 
{
private:
    int num;
public:
    CDato (): num(0){}

    int getNum() const;
    void setNum(int newNum);
};

int CDato::getNum()  const{
    return num;
}


int main () {

    cout << "Hello World!" << endl;
    return 0;
}
