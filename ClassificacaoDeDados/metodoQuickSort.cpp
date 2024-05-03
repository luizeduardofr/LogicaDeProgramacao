#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

void quicksort (int *v, int piv, int direita) {
	int i = piv + 1;
	int j = direita;
	for (; i <= j;){
		for (; v[j] > v[piv] && i <= j; j--);
		for (; v[i] < v[piv] && i <= j; i++);
		if (i <= j){
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	}
	int aux = v[j];
	v[j] = v[piv];
	v[piv] = aux;
	
	if ((j - 1) - piv >= 1)
		quicksort (v, piv, j - 1);
	if (direita - (j + 1) >= 1)
		quicksort (v, j + 1, direita);
}

int main() {
	int vetor[17]={26,31,12,37,29,42,17,21,39,30,22,18,14,37,15,28,22};
    cout << "\nClassificacao por Metodo de Shell\n";
    cout << "\nVetor Original\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    quicksort (vetor,0,16);
        cout << "\nVetor Classificado\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    getch();
    
}