#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <ctype.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *cabeca, int x){
    celula *novo = (celula *) malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = cabeca->prox;
    cabeca->prox = novo;
}

void insere_antes(celula *cabeca, int x, int y){
    celula *novo = (celula *) malloc(sizeof(celula));
    novo->dado = x;
    celula *p = cabeca;

    // Percorre a lista para encontrar y ou o final da lista
    while (p->prox != NULL && p->prox->dado != y){
        p = p->prox;
    }

    // Se não encontrou y, insere no final da lista
    //Elemento y não encontrado. Inserindo no final da lista.
    

    // Inserir o novo nó
    novo->prox = p->prox;
    p->prox = novo;
}
