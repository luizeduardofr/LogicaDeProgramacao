#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int fibonacci (int);

int main() {
	int n, result;
	cout << "Digite a quantidade de numeros da sequencia de Fibonacci: ";
	cin >> n;
	cout << "\nSequencia Fibonnaci: " << n << " elementos: " << endl;
	for (int i=0; i<n; i++){
		result = fibonacci(i);
		cout << result << " - ";
	}
	cout << "\n\nFinal da Sequencia!";
	getch();
}

int fibonacci (int num) {
	if (num==0 || num==1){
		return num;
	} else {
		return fibonacci(num-1) + fibonacci(num-2);
	}	
}