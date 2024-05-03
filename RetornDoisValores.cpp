#include <iostream>
#include <conio.h>
using namespace std;

void funcao (float &x, float &y) {
	float soma = x + y;
	float media = ((x+y)/ 2);
	x = soma;
	y = media;
}

int main() {
	float a, b;
	cout << "Informe o primeiro valor: ";
	cin >> a;
	cout << "Informe o segundo valor: ";
	cin >> b;
	funcao (a,b);
	cout << "A media dos valores = " << b;
	cout << "\nSoma dos valores = " << a;
	getch();
}