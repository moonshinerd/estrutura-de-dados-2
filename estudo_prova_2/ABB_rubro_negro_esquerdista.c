#include <stdio.h>
#include <stdlib.h>

typedef enum {VERMELHO, PRETO} cor;

typedef struct no{
    int chave;
    struct no *esq, *dir;
    cor cor;
} no;

int ehVermelho(no *r){
    if (r != NULL) return r->cor == VERMELHO; // retorna 1 se o nó for vermelho ou 0 se for preto
    return 0; // retorna 0 se o nó for NULL
}

int ehPreto(no *r){ // 1 = true; 0 = false
    if (r != NULL) return r->cor == PRETO; // retorna 1 se o nó for preto ou 0 se for vermelho
    return 0; // retorna 0 se o nó for NULL
}

no *insere(no *r, int x){ // r = raiz da árvore, x = valor a ser inserido
    if (r != NULL) {
        if (x < r->chave) r->esq = insere(r->esq, x); // Se a chave a ser inserida é menor que a chave do nó atual, insere na subárvore esquerda
        else if (x > r->chave) r->dir = insere(r->dir, x); // Se a chave a ser inserida é maior que a chave do nó atual, insere na subárvore direita
        r = corrige(r); // Corrige a árvore após a inserção para manter as propriedades da árvore rubro-negra
        return r;
    } else { // Ao chegar em um nó NULL, cria um novo nó e retorna para ser corrigido na chamada anterior
        no *novo = malloc(sizeof(no)); // Se o nó atual é NULL, cria um novo nó
        novo->chave = x;
        novo->esq = novo->dir = NULL;
        novo->cor = VERMELHO; // Todo novo nó é inserido vermelho para preservar a altura negra e depois é corrigido
        return novo;
    }
}

no *corrige(no *r){ 
    if (ehPreto(r->esq) && ehVermelho(r->dir)) // Se o nó esquerdo é preto e o nó direito é vermelho, faz uma rotação à esquerda
        r = rotacao_a_esq(r);
    if (ehVermelho(r->esq) && ehVermelho(r->esq->esq))// Se o nó esquerdo e o filho esquerdo do nó esquerdo são vermelhos, faz uma rotação à direita
        r = rotacao_a_dir(r);
    if (ehVermelho(r->esq) && ehVermelho(r->dir)) // Se ambos os filhos são vermelhos, sobe a cor do nó atual e dos filhos
        sobe_cor(r);
    return r; // Retorna o nó corrigido
}

no *rotacao_a_esq(no *r){
    no *x = r->dir; // x é o filho direito de r
    r->dir = x->esq; // O filho esquerdo de x passa a ser o filho direito de r
    x->esq = r; // r passa a ser o filho esquerdo de x
    x->cor = r->cor; // A cor de x passa a ser a cor de r
    r->cor = VERMELHO; // A cor de r passa a ser vermelho
    return x; // Retorna o novo nó que está no lugar de r
}

no *rotacao_a_dir(no *r){
    no *x = r->esq; // x é o filho esquerdo de r
    r->esq = x->dir; // O filho direito de x passa a ser o filho esquerdo de r
    x->dir = r; // r passa a ser o filho direito de x
    x->cor = r->cor; // A cor de x passa a ser a cor de r
    r->cor = VERMELHO; // A cor de r passa a ser vermelho
    return x; // Retorna o novo nó que está no lugar de r
}

void sobe_cor(no *r){
    r->esq->cor = PRETO; // O filho esquerdo de r passa a ser preto
    r->dir->cor = PRETO; // O filho direito de r passa a ser preto
    r->cor = VERMELHO; // O nó r passa a ser vermelho
}

