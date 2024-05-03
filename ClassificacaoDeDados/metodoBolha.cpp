#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
void bolha(int *v, int n) {
   int troca = 0;
   while (troca == 0){
        troca = 1;
        for (int i=0; i < (n-1); i++){
            if (v[i] > v[i+1]){
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troca = 0;
            }
        }
        n--;
   }
}

int main(){
    cout << "\nMetodo da Bolha\n";
    int vetor[17]={26,31,12,37,29,42,17,21,39,31,22,18,14,37,15,28,22};
    cout << "\nVetor Original\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    bolha (vetor,17);
    cout << "\nVetor Classificado\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    getch();
}