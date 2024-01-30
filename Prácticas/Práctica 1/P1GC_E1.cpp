//PRACTICA 1 EDA
//SANTIAGO VALDERRAMA FLORES Y GINA ANDREA RAMIREZ GUERRERO

#include <iostream>
#include <vector>
using namespace std;

int menu();
int solicitarNumero();
int solicitarExponente();
int potenciaXY(int n, int e);
int solicitarNumero();
int sumaCifrasPares(int n, int suma);
vector <int> solicitarDatosVector();
int totalNumImparesITER(vector <int>& v);
void mostrarVector(vector <int> &v);
int totalNumImparesREC(vector <int> &v, int suma);

int main() {

	int opc{ 0 };
	int n, suma;
	int Exp;
	int potencia;
	int numImp;
	vector <int> v;
	

	do
	{
		int opc = menu();
		switch (opc)
		{

		case 1:
			n = solicitarNumero();
			suma = sumaCifrasPares(n, 0);

			cout << "la suma de las cifras pares de " << n << " es: " << suma << ".\n";

			break;
		case 2: 
			n= solicitarNumero();
			Exp = solicitarExponente();

			if (Exp < 0)
			{
				Exp = Exp * -1;
			}

			potencia = potenciaXY(n, Exp);

			cout << "La potencia es: " << potencia << endl;


			break;
		case 3:
			v = solicitarDatosVector();
			numImp = totalNumImparesITER(v);

			cout << "El vector | ";
			for (int elem : v) {
				cout << elem;
			}
			cout << " |";
			cout << " contiene " << numImp << " numeros impares" << endl;

			break;
		case 4:
			v = solicitarDatosVector();
			mostrarVector(v);

			cout << "\nEl total de numeros impares de tu vector es de: " << totalNumImparesREC(v, 0);

			break;
		case 5:
			cout << endl;
			cout << "Gracias y hasta pronto!";
			cout << endl;
			return 0;
			break;
		default: 
			cout << "La opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl;
			break;
		}

		
	} while (opc > 6 || opc < 1);



	return 0;
}

int menu() {
	
	int opcion;
	cout << endl;
	cout << "SELECCIONE UNA OPCION: " << endl;
	cout << "1. Sumar las cifras pares de un numero entero de forma recursiva" << endl;
	cout << "2. Calcular potencia de x elevado a y de forma recursiva" << endl;
	cout << "3. Calcular total de valores impares de un vector de forma iterativa" << endl;
	cout << "4. Calcular total de valores impares de un vector de forma recursiva" << endl;
	cout << "5. Salir programa" << endl;
	cin >> opcion;

	return opcion;

}

int solicitarNumero() {

	int n;

	do {

		cout << "Escribe un numero entero positivo: ";
		cin >> n;

	} while (n < 0);


	return n;
}

int sumaCifrasPares(int n, int suma) {

	if (n <= 0) {

		return suma;
	}

	else {

		if ((n % 10) % 2 == 0) {

			suma = suma + (n % 10);
			sumaCifrasPares(n / 10, suma);
			//return suma;
		}

		else if ((n % 10) % 2 == 1) {

			sumaCifrasPares(n / 10, suma);
		}
	}

}


int solicitarExponente() {
	int exp;

	cout << "Introduzca el exponente de la potencia a calcular: ";
	cin >> exp;

	return exp;

}

int potenciaXY(int n, int e) {


	if (e == 0)
	{
		return 1;
	}
	
	if (e == 1)
	{
		return n;
	}

	else
	{
		return n * potenciaXY(n, e - 1);
	}

}

vector <int> solicitarDatosVector() {
	int n;
	vector <int> v;

	cout << "Escribe la cantidad de numeros que habra en tu vector: ";
	cin >> n;

	for (int i = 0; i < n; i++) {

		int j;
		cout << "Escribe el " << i + 1 << "º numero entero: ";
		cin >> j;

		v.push_back(j);
	}

	return v;

}

int totalNumImparesITER(vector <int>& v) {

	int contador = 0;

	for (int elem : v) {
		if (elem%2 != 0)
		{
			contador++;
		}
	}

	return contador;
}

void mostrarVector(vector <int> &v) {

	for (int i = 0; i < v.size(); i++) {

		cout << i + 1 << "º posicion: " << v[i] << endl;
	}
}

int totalNumImparesREC(vector <int> &v, int suma) {

	if (v.empty()) {

		return suma;
	}

	else {

		if (v[v.size() - 1] % 2 == 1) {

			suma++;
			v.pop_back();
			suma = totalNumImparesREC(v, suma);
			return suma;
		}

		else if (v[v.size() - 1] % 2 == 0) {

			v.pop_back();
			suma = totalNumImparesREC(v, suma);
			return suma;

		}
	}
}