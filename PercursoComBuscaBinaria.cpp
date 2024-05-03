#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;

struct clientes {
	int cod;
	char nome[30];
	char endereco[35];
	char cidade[25];
	char uf[3];
};


void leitura (struct clientes cli[]){
	for (int i=0; i<3; i++){
		cout << "\nCodigo do cliente " << (i+1) << " :";
		cin >> cli[i].cod;
		cout << "Nome: ";
		cin >> cli[i].nome;
		cout << "Endereço: ";
		cin >> cli[i].endereco;
		cout << "Cidade: ";
		cin >> cli[i].cidade;
		cout << "Estado: ";
		cin >> cli[i].uf;
	}
}

//void buscaserial (struct clientes cli[], int cod){
//	int i=0;
//	for (; i<3 && cod > cli[i].cod; i++);
//	if (cod == cli[i].cod){
//		cout << "\n\n Cliente Encontrado";
//		cout << "\nCodigo do Cliente: " << cli[i].cod;
//		cout << "\nNome: " << cli[i].nome;
//		cout << "\nEndereco: " << cli[i].endereco;
//		cout << "\nCidade: " << cli[i].cidade;
//		cout << "\nEstado: " << cli[i].uf;
//	} else {
//		cout << "\n\n Cliente nao Encontrado";
//		getch();
//	}
//}

int buscabinaria (struct clientes cli[], int cod){
	int i=0, f=3;
	int m= (i + f) / 2;
	for (i; f > i && cod != cli[m].cod; m = (i + f)/2){
		if (cod > cli[m].cod){
			i = m + 1;
		} else {
			f = m - 1;
		}
	}
	
	if (cod == cli[i].cod){
		cout << "\n\n Cliente Encontrado";
		cout << "\nCodigo do Cliente: " << cli[m].cod;
		cout << "\nNome: " << cli[m].nome;
		cout << "\nEndereço: " << cli[m].endereco;
		cout << "\nCidade: " << cli[m].cidade;
		cout << "\nEstado: " << cli[m].uf;
	} else {
		cout << "\n\n Cliente nao Encontrado";
		getch();
	}
}
	

int main() {
	setlocale(LC_ALL,"");
	struct clientes dados[3];
	int codpesq;
	leitura(dados);
	for (codpesq = 3; codpesq !=0;){
		cout << "\n\n Informe o Codigo do Cliente a ser buscado: ";
		cin >> codpesq;
		if(codpesq !=0){
			buscabinaria(dados, codpesq);
		}
	}
}