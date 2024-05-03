#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
/* Busca serial de registros em Arquivo Indexado */

struct indice {
        int codigo;
        int ender;
        };
struct clientes {
       int codigo;
       char nome[30];
       char endereco[35];
       char cidade[25];
       char uf[2];
       };

void leitura_dados (struct clientes cli[], int &cont){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCodigo do Cliente " << (i+1) << ": ";
        cin >> cli[i].codigo;
        if (cli[i].codigo > 0){
            cout << "Nome: ";
            cin >> cli[i].nome;
            cout << "Endereco: ";
            cin >> cli[i].endereco;
            cout << "Cidade: ";
            cin >> cli[i].cidade;
            cout << "Estado: ";
            cin >> cli[i].uf;
        }
        else saida = 0;
    }
    cont = i-1;
}

void leitura_indice (struct indice idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}

void buscaserial (struct indice idx[], struct clientes cli[], int cont, int cod){
    int i = 0;
    for (; i < cont && cod > idx[i].codigo; i++);
    if (cod == idx[i].codigo){
        cout << "\n\n Cliente Encontrado";
        i = idx[i].ender;
        cout << "\nCodigo do Cliente: " << cli[i].codigo;
        cout << "\tNome: " << cli[i].nome;
        cout << "\tEndereco: " << cli[i].endereco;
        cout << "\tCidade: " << cli[i].cidade;
        cout << "\tEstado: " << cli[i].uf;
    }
    else
        cout << "\n\n Cliente nao Encontrado";
    getch();
}

int main(){
    struct indice ind[20];
    struct clientes dados[20];
    int contador;
    cout << "\n\nLeitura da Area de Dados";
    leitura_dados (dados,contador);
    cout << "\n\nLeitura do Indice";
    leitura_indice (ind,contador);
    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Cliente a ser Buscado (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            buscaserial (ind, dados, contador, codpesq);
    }
}