#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

void shellsort(int *v, int n, int *veth, int incr) {
   for (int h = veth[incr]; h > 0; incr--, h = veth[incr]){
        for (int i = h; i < n; i++){
            int j, chave = v[i];
            for (j = i - veth[incr]; j >= 0 && v[j] > chave; j = j - veth[incr])
                v[j + veth[incr]] = v[j];
            v[j + veth[incr]] = chave;
        }
   }
}

int main(){
    int vetor[17]={26,31,12,37,29,42,17,21,39,30,22,18,14,37,15,28,22};
    cout << "\nClassificacao por Metodo de Shell\n";
    cout << "\nVetor Original\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    int incr, veth[10];
    cout << "\n\nInforme a quantidade de Incrementos: ";
    cin >> incr;
    incr--;
    for(int i = incr; i > 0; i--) {
      cout << "Informe h[" << i << "] = ";
	  cin >> veth[i];
    }
    veth[0] = 1;
    cout << "h[0] gerado automaticamente = " << veth[0] << endl;

    shellsort (vetor,17,veth,incr);
    cout << "\nVetor Classificado\n";
    for (int i=0; i < 17; i++)
        cout << vetor[i] << " - ";
    getch();
}