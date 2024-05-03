#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
/* InclusÃ£o de registros em Arquivo Indexado */

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

void inclusao (struct indice idx[], struct clientes cli[], int &cont, int cod){
    cont++;
    // inclusao do novo registro na area de dados
    cli[cont].codigo = cod;
    cout << "Nome: ";
    cin >> cli[cont].nome;
    cout << "Endereco: ";
    cin >> cli[cont].endereco;
    cout << "Cidade: ";
    cin >> cli[cont].cidade;
    cout << "Estado: ";
    cin >> cli[cont].uf;
    // inclusao na area de indices
    int i;
    for (i = cont - 1; idx[i].codigo > cod; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
    cont++;
}

void buscaaleat (struct indice idx[], struct clientes cli[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo){
        cout << "\n\n Cliente ja Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCodigo do Cliente: " << cli[i].codigo;
        cout << "\tNome: " << cli[i].nome;
        cout << "\tEndereco: " << cli[i].endereco;
        cout << "\tCidade: " << cli[i].cidade;
        cout << "\tEstado: " << cli[i].uf;
    }
    else
        inclusao (idx, cli, cont, cod);
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
        cout << "\n\nInforme o Codigo do Cliente a ser Incluido (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            buscaaleat (ind, dados, contador, codpesq);
    }
}