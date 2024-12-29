#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

int altura(no *raiz) {
    if (raiz == NULL) {
        return 0; // Corrige a altura de uma árvore vazia para 0
    } else {
        int he = altura(raiz->esq);
        int hd = altura(raiz->dir);
        return (he > hd ? he : hd) + 1; // Retorna o maior entre as alturas das subárvores
    }
}
