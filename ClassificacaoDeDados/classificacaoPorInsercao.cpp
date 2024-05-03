#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

void insercao(int *v, int n) {
   for (int i=1; i < n; i++){
        int chave = v[i], j;
        for (j = i-1; (j >= 0 && v[j] > chave); j--)
            v[j+1] = v[j];
        v[j+1] = chave;
   }
}

int main(){
    cout << "\nClassificacao por Insercao\n";
    int vetor[17]={26,31,12,37,29,42,17,21,39,31,22,18,14,37,15,28,22};
    cout << "\nVetor Original\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    insercao (vetor,17);
    cout << "\nVetor Classificado\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    getch();
}