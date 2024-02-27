// Santiago Valderrama

#include <iostream>
#include <string>

using namespace std;

string metodoBurbuja(string &f);

int main()
{

    string f = "zqpona";
    cout << metodoBurbuja(f);

    return 0;
}

string metodoBurbuja(string &f)
{

    char menor;
    bool ordenado;

    for (unsigned int compar{0}; compar < f.length() - 1; compar++)
    {

        for (unsigned int i{0}; i < f.length() - 1 - compar; i++)
        {

            ordenado = true;

            if (f[i] > f[i + 1])
            {

                ordenado = false;
                menor = f[i];
                f[i] = f[i + 1];
                f[i + 1] = menor;
            }

            if (ordenado)
            {
                break;
            }
        }

        if (menor == -1)
        {
            break;
        }
    }

    return f;
}