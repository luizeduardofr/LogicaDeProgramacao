#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string.h>
using namespace std;

struct pessoa {
	char nome[30];
	int idade;
	char endereco[30];
};

void imprimir_pessoa (pessoa p){
	cout << "Nome: " << p.nome << endl;
	cout << "Idade: " << p.idade << endl;
	cout << "Endereço: " << p.endereco << endl;
	cout << endl << endl;
}

void imprimir_todas_pessoas (pessoa pessoas[], int n){
	cout << "Informações de todas as pessoas: " << endl;
	for(int i=0; i<n; i++){
		imprimir_pessoa (pessoas[i]);
	}
}

void atualizar_pessoa (pessoa pessoas[], int n){
	char nomeatualizar[30];
	cout << "Digite o nome da pessoa a ser atualizada: ";
	gets (nomeatualizar);
	for (int i=0; i<n; i++){
		if(strcmp(pessoas[i].nome, nomeatualizar)==0){
			cout << "\nPessoa encontrada: " << pessoas[i].nome;
			cout << "\nInforme a nova idade da pessoa: ";
			cin >> pessoas[i].idade;
			cin.ignore();
			cout << "\nInforme o novo endereço da pessoa: ";
			gets(pessoas[i].endereco);
			cout << "\n\nInformações atualizadas da pessoa: " << endl;
			imprimir_pessoa(pessoas[i]);
			return;
		}
	}
	cout << "Não foi possível encontrar a pessoa informada." << endl;
}

int main(){
	setlocale(LC_ALL,"");
	const int tamanho = 10;
	pessoa pessoas[tamanho];
	cout << "Digite as informações de até " << tamanho << " pessoas." << endl;
	for (int i=0; i<tamanho; i++){
		cout << "Pessoa " << i+1 << ":" << endl;
		cout << "Informe o nome da pessoa: ";
		gets(pessoas[i].nome);
		cout << "Informe a idade da pessoa: ";
		cin >> pessoas[i].idade;
		cin.ignore();  //ignorando o \n deixado pelo cin
		cout << "Informe o endereco da pessoa: ";
		gets(pessoas[i].endereco);
		cout << endl;
	}
	imprimir_todas_pessoas (pessoas, tamanho);
	atualizar_pessoa (pessoas, tamanho);
}