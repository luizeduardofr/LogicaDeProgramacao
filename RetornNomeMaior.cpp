//Retornar informação dizendo qual nome é maior

#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

char Maior(char *vet1, char *vet2) {
	return  (strcmp(vet1, vet2));
}

int main() {
	char nome1[20], nome2[20];
	int resultado;
	
	cout << "Informe o primeiro nome: ";
	gets(nome1);
	cout << "Informe o segundo nome: ";
	gets(nome2);
	
	resultado = Maior(nome1, nome2);
	
	if(resultado > 0){
		cout << nome1 << " maior que " << nome2;
	} else {
		if(resultado < 0) {
			cout << nome1 << " menor que " << nome2;
		} else {
			cout << "Nomes iguais." << endl;
		}
    }
	getch();	
}