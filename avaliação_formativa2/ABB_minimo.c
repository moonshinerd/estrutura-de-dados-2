#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *minimo(no *raiz) {
    if (raiz == NULL) return NULL;

    while (raiz->esq != NULL) raiz = raiz->esq;

    return raiz;
}