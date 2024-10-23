#include <stdio.h>

// Definição da estrutura de uma célula da lista encadeada
typedef struct celula {
    int dado;              // Dado armazenado na célula
    struct celula *prox;   // Ponteiro para a próxima célula
} celula;

// Função de busca iterativa em uma lista encadeada
celula *busca(celula *le, int x) {
    // Percorre a lista enquanto houver próxima célula
    while (le->prox != NULL) {
        // Se o dado da próxima célula for igual a x, retorna a próxima célula
        if (le->prox->dado == x) {
            return le->prox;
        }
        // Avança para a próxima célula
        le = le->prox;
    }
    // Se não encontrar o valor, retorna NULL
    return NULL;
}

// Função de busca recursiva em uma lista encadeada
celula *busca_rec(celula *le, int x) {
    // Verifica se há próxima célula
    if (le->prox != NULL) {
        // Se o dado da próxima célula for igual a x, retorna a próxima célula
        if (le->prox->dado == x) {
            return le->prox;
        } else {
            // Chama a função recursivamente para a próxima célula
            return busca_rec(le->prox, x);
        }
    } else {
        // Se não encontrar o valor, retorna NULL
        return NULL;
    }
}