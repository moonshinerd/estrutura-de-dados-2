#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *maximo(no *raiz) {
    if (raiz == NULL) return NULL;

    while (raiz->dir != NULL) raiz = raiz->dir;

    return raiz;
}