#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função auxiliar para encontrar o maior elemento da subárvore esquerda
no *encontrar_antecessor(no *r) {
    no *atual = r;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}

// Função de remoção
no *remover(no *r, int x) {
    if (r == NULL) {
        return NULL; // Chave não encontrada
    }

    if (x < r->chave) {
        r->esq = remover(r->esq, x); // Busca na subárvore esquerda
    } else if (x > r->chave) {
        r->dir = remover(r->dir, x); // Busca na subárvore direita
    } else {
        // Caso 1: Nó folha
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            return NULL;
        }
        // Caso 2: Nó com um único filho
        else if (r->esq == NULL) {
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            no *temp = r->esq;
            free(r);
            return temp;
        }
        // Caso 3: Nó com dois filhos
        else {
            no *antecessor = encontrar_antecessor(r->esq);
            r->chave = antecessor->chave;
            r->esq = remover(r->esq, antecessor->chave);
        }
    }
    return r;
}


