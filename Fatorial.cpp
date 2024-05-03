#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int fatorial (int);

int main(){
	int a, result;
	cout << "Informe um valor: ";
	cin >> a;
	result = fatorial(a);
	cout << "Fatorial de " << a << " = " << result;
	getch();
}

int fatorial (int x){
	if(x > 0){
		return (x * fatorial (x-1));
	}
	else {
		return (1);
	}
}