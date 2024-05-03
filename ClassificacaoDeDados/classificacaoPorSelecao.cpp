#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

void selecao(int *v, int n) {
   for (int i=0; i < (n - 1); i++){
        int posmenor = i;
        for (int j = i+1; j < n; j++){
            if (v[j] < v[posmenor])
                posmenor = j;
        }
        int aux = v[i];
        v[i] = v[posmenor];
        v[posmenor] = aux;
    }
}

int main(){
    cout << "\nClassificacao por Selecao\n";
    int vetor[17]={26,31,12,37,29,42,17,21,39,31,22,18,14,37,15,28,22};
    cout << "\nVetor Original\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    selecao (vetor,17);
    cout << "\nVetor Classificado\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    getch();
}