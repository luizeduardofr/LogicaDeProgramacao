#include <iostream>
#include <locale.h>
using namespace std;

struct clientes {
	int cod;
	char nome[30];
	char endereco[35];
	char cidade[25];
	char uf[3];
};

void leitura (struct clientes cli[], int tam){
	for (int i=0; i<tam; i++){
		cout << "\nCódigo do cliente " << (i+1) << " :";
		cin >> cli[i].cod;
		cout << "Nome: ";
		cin.ignore();
		cin.getline(cli[i].nome, sizeof(cli[i].nome));
		cout << "Endereço: ";
		cin.getline(cli[i].endereco, sizeof(cli[i].endereco));
		cout << "Cidade: ";
		cin.getline(cli[i].cidade, sizeof(cli[i].cidade));
		cout << "Estado: ";
		cin.getline(cli[i].uf, sizeof(cli[i].uf));
	}
}

void percurso (struct clientes cli[], int tam){
	for(int i=0; i<tam; i++){
		cout << "\nCódigo do cliente" << (i+1) << cli[i].cod;
		cout << "Nome: " << cli[i].nome;
		cout << "Endereço: " << cli[i].endereco;
		cout << "Cidade: " << cli[i].cidade;
		cout << "Estado: " << cli[i].uf;
	}
}

int main() {
	setlocale(LC_ALL,"");
	int const tam = 3;
	struct clientes dados[3];
	leitura(dados, tam);
	percurso(dados, tam);
}