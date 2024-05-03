#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

void contagem(int *v, int n, int *cont, int *saida) {
   for (int i=0; i < n; i++)
        cont[i] = 0;
   for (int i=0; i < (n - 1); i++){
        for (int j = i+1; j < n; j++){
            if (v[i] > v[j])
                cont[i]++;
            else
                cont[j]++;
        }
    }
    for (int i=0; i < n; i++)
        saida[cont[i]] = v[i];
}

int main(){
    cout << "\nClassificacao por Selecao\n";
    int vetor[17]={26,31,12,37,29,42,17,21,39,31,22,18,14,37,15,28,22};
    int cont[17], saida[17];
    cout << "\nVetor Original\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    contagem (vetor,17,cont,saida);
    cout << "\nVetor Classificado\n";
    for (int i=0; i < 17; i++)
        cout << saida[i] << " - ";
    getch();
}