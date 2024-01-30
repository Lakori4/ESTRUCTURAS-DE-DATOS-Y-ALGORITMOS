// Santiago Valderrama

#include <iostream>
#include <string>


using namespace std;

void metodoBurbuja (string & f);

int main () {

    string f = "abgnz";
    metodoBurbuja(f);

    return 0;
}


void metodoBurbuja (string & f) {

    char menor;

    for (unsigned int compar{0}; compar< f.size()-1; compar++) {
            
        for (unsigned int i{0}; i < f.size()-1-compar; i++) {

            if (f.at(i) > f.at(i+1)) {
                    
                menor = f.at(i);
                f.at(i) = f.at(i+1);
                
                f.at (i+1)= menor;
            }
        }

        if (menor == -1) {

            break;
        }
    }
}