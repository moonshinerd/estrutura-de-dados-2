#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *inserir(no *raiz, int chave) {
    if (raiz == NULL) {
        no *novo = malloc(sizeof(no));
        novo->chave = chave;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (chave < raiz->chave) raiz->esq = inserir(raiz->esq, chave);
    else if (chave > raiz->chave) raiz->dir = inserir(raiz->dir, chave);

    return raiz;
}