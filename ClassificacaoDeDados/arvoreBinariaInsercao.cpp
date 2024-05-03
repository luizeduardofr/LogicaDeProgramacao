#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct _no arvorebin;

struct _no
{
      int info;
      arvorebin *esquerda;
      arvorebin *direita;
};

/* protótipo das funções */
void inclusao_no(arvorebin *root, int k);


int main(){

      //inicializando a raiz vazia
      arvorebin *raiz = NULL; 
      
      //alocando um nó para a raiz
      raiz = (arvorebin*) malloc(sizeof(arvorebin));
      raiz->info = 50;
      raiz->esquerda = NULL;
      raiz->direita = NULL;

      //incluindo os outros nós
      inclusao_no(raiz, 30);
      inclusao_no(raiz, 90);
      inclusao_no(raiz, 20);
      inclusao_no(raiz, 40);
      inclusao_no(raiz, 100);

	return 0;
}

void inclusao_no(arvorebin *root, int k){
      arvorebin *novo,*pai = NULL;

      novo = (arvorebin *) malloc(sizeof(arvorebin));
      novo->esquerda = NULL;
      novo->direita = NULL;
      novo->info = k;

      while(root != NULL)
      {
            pai = root;
            if ( k  <  root->info)
                  root = root->esquerda;
            else
                  root = root->direita;
      }

      if (k < pai->info)
            pai->esquerda = novo;
      else
            pai->direita = novo;
}