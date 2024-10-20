#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <ctype.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *cabeca){
    celula *p = cabeca->prox; // (*cabeca).prox (acessando o campo prox de cabeca a struct)
    for (p ; p != NULL; p = p->prox){
        printf("%d -> ", p->dado);
    }
    printf("NULL\n");
}

void imprime_rec(celula *no) {
    if (no == NULL) {
        printf("NULL\n");
        return;  // Caso base: se o nó for NULL, para a recursão
    }
    
    // Imprime apenas se o dado não for 0
    if (no->dado != 0) {
        printf("%d -> ", no->dado);  // Imprime o valor do nó atual
    } else {
        // Se o dado for 0, podemos não imprimir, mas ainda assim chamar a recursão
        imprime_rec(no->prox);  // Chama a função para o próximo nó
        return; // Adiciona um retorno para não imprimir o 0
    }
    
    imprime_rec(no->prox);  // Chama a função para o próximo nó
}

/*
void imprime_recursivo(celula *no) {
    if (no != NULL) {
        printf("0 -> ");
    }
      // Imprime '0 ->' uma vez antes de tudo
    imprime_recursivo(no);  // Chama a função recursiva para imprimir a lista
}

void inserefim(celula *cabeca, int x){
    celula *novo = (celula *) malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = NULL;
    celula *aux = cabeca;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
}

void main(){
    celula *cabeca = (celula *) malloc(sizeof(celula));
    cabeca->prox = NULL;
    inserefim(cabeca, 10);
    imprime(cabeca);
    imprime_rec(cabeca->prox);
}*/