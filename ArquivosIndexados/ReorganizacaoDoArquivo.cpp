#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
/* ReorganizaÃ§Ã£o de registros em Arquivo Indexado */

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
       int status;
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
            cout << "Status: ";
            cin >> cli[i].status;
            //cli[i].status = 0;
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

void reorganizacao (struct indice idx[], struct indice novoidx[], struct clientes cli[], struct clientes novocli[], int cont) {
    int j = -1;
    for (int k = 0; k < cont; k++){
        int i = idx[k].ender;
        if (cli[i].status == 0){
            j++;
            novocli[j].codigo = cli[i].codigo;
            strcpy (novocli[j].nome , cli[i].nome);
            strcpy (novocli[j].endereco , cli[i].endereco);
            strcpy (novocli[j].cidade , cli[i].cidade);
            strcpy (novocli[j].uf , cli[i].uf);
            novocli[j].status = 0;
            novoidx[j].codigo = novocli[j].codigo;
            novoidx[j].ender = j;
        }
    }
    cont = j + 1;
}

void exaustiva (struct indice idx[], struct clientes cli[], int cont){
    for (int k = 0; k < cont; k++){
        int i = idx[k].ender;
        if (cli[i].status == 0){
            cout << "\nNome: " << cli[i].nome;
            cout << "\tEndereco: " << cli[i].endereco;
            cout << "\tCidade: " << cli[i].cidade;
            cout << "\tEstado: " << cli[i].uf;
        }
    }
}

int main(){
    struct indice ind[20];
    struct clientes dados[20];
    int contador;
    cout << "\n\nLeitura da Area de Dados";
    leitura_dados (dados,contador);

    cout << "\n\nLeitura do Indice";
    leitura_indice (ind,contador);

    system("pause");

    cout << "\n\nReorganizacao dos Arquivos";

}