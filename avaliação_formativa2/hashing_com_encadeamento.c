#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

typedef struct {
  celula *tb; // tabela hash
  int M;      // tamanho da tabela hash
  int N;      // total de chaves presentes na tabela
} TH;



void THinsere(TH *h, int ch){
    int i = ch % h->M; // obtem o indice da tabela
    celula *p = h->tb[i].prox; // ponteiro para a lista encadeada
    while (p != NULL && p->dado != ch) p = p->prox; //
    if (p == NULL){
        celula *nova = malloc(sizeof(celula));
        nova->dado = ch;
        nova->prox = h->tb[i].prox;
        h->tb[i].prox = nova;
        h->N++;
    }
}

int THremove(TH *h, int ch){
    int i = ch % h->M;
    celula *p = &h->tb[i];
    while (p->prox != NULL && p->prox->dado != ch) p = p->prox;
    if (p->prox == NULL) return -1;
    celula *lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);
    h->N--;
    return 0;
}

int THbusca(TH *h, int ch){
    int i = ch % h->M;
    celula *p = h->tb[i].prox;
    while (p != NULL && p->dado != ch) p = p->prox;
    if (p == NULL) return 0;
    return 1;
}