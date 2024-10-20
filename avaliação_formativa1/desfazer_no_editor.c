#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct Lista {
    char texto[100];
    struct Lista *prox;
};

typedef struct Lista Item;

void inicializa(Item *cabeca) {
    cabeca->prox = NULL;
}

void inserefim(Item *cabeca, char *texto) {
    Item *novo = (Item *) malloc(sizeof(Item));
    Item *aux = cabeca;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    novo->prox = NULL;
    strcpy(novo->texto, texto);
    aux->prox = novo;
}

void deletaritemposicao(Item *cabeca, int posicao) {
    Item *aux = cabeca;
    int i = 0;
    while (aux->prox != NULL) {
        if (i == posicao) {
            Item *aux2 = aux->prox;
            aux->prox = aux->prox->prox;
            free(aux2);
            return;
        }
        i++;
        aux = aux->prox;
    }
    printf("Posicao invalida\n");
}

void deletarultimaposicao(Item *cabeca) {
    Item *aux = cabeca;
    while (aux->prox->prox != NULL) {
        aux = aux->prox;
    }
    Item *aux2 = aux->prox;
    aux->prox = NULL;
    free(aux2);
}

void salvarUltimoEmOutraLista(Item *listaOrigem, Item *listaDestino) {
    if (listaOrigem->prox != NULL) {  // Verifica se a lista não está vazia
        // Pega o último item
        Item *aux = listaOrigem;
        while (aux->prox->prox != NULL) {
            aux = aux->prox;
        }

        // Salva o texto do último item na lista de destino
        inserefim(listaDestino, aux->prox->texto);

        // Deleta o último item da lista original
        deletarultimaposicao(listaOrigem);
    } else {
        // Se a lista original está vazia, insere uma string vazia na lista de destino
        inserefim(listaDestino, "NULL"); // Ou use "" para uma string vazia
    }
}

void imprimirlista(Item *cabeca) {
    Item *aux = cabeca;
    while (aux->prox != NULL) {
        printf("%s\n", aux->prox->texto);
        aux = aux->prox;
    }
}

int main() {
    char inserir[] = "inserir";
    char desfazer[] = "desfazer";
    char prompt[107];
    Item cabecalista1;
    Item cabecalista2;
    inicializa(&cabecalista1);
    inicializa(&cabecalista2);

    while (scanf("%[^\n]", prompt) != EOF) {
        char primeiros7[8]; // Deve ter espaço para o terminador nulo
        strncpy(primeiros7, prompt, 7);
        primeiros7[7] = '\0'; // Adiciona o terminador nulo

        char primeiros8[9]; // Deve ter espaço para o terminador nulo
        strncpy(primeiros8, prompt, 8);
        primeiros8[8] = '\0'; // Adiciona o terminador nulo

        if (strcmp(primeiros7, inserir) == 0) {
            inserefim(&cabecalista1, prompt + 8);
        } else if (strcmp(primeiros8, desfazer) == 0) {
            salvarUltimoEmOutraLista(&cabecalista1, &cabecalista2);
        }

        // Limpar buffer de entrada
        while (getchar() != '\n');
    }
    imprimirlista(&cabecalista2);

    return 0;
}
