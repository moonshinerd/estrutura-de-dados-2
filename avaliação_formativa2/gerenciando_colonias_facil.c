#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_INICIAL 1048576 // 2^20

// Estrutura para o nó de alimento
typedef struct alimento {
    char nome[11];
    struct alimento *prox;
} alimento;

// Estrutura para o nó da colônia
typedef struct colonia {
    int id;
    alimento *alimentos;
    struct colonia *prox;
} colonia;

// Estrutura para a tabela hash
typedef struct {
    colonia **tabela;
    int tamanho;
} tabela_hash;

// Função de hash
int funcao_hash(int x, int tamanho) {
    return x % tamanho;
}

// Cria uma nova tabela hash
 tabela_hash *cria_tabela(int tamanho) {
    tabela_hash *tabela = malloc(sizeof(tabela_hash));
    tabela->tabela = calloc(tamanho, sizeof(colonia *));
    tabela->tamanho = tamanho;
    return tabela;
}

// Libera a memória de uma lista de alimentos
void destroi_alimentos(alimento *lista) {
    while (lista != NULL) {
        alimento *prox = lista->prox;
        free(lista);
        lista = prox;
    }
}

// Libera a memória de uma tabela hash
void destroi_tabela(tabela_hash *tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        colonia *atual = tabela->tabela[i];
        while (atual != NULL) {
            colonia *prox = atual->prox;
            destroi_alimentos(atual->alimentos);
            free(atual);
            atual = prox;
        }
    }
    free(tabela->tabela);
    free(tabela);
}

// Verifica se um alimento já existe na lista
bool alimento_existe(alimento *lista, const char *nome) {
    while (lista != NULL) {
        if (strcmp(lista->nome, nome) == 0) {
            return true;
        }
        lista = lista->prox;
    }
    return false;
}

// Insere um alimento na lista
void insere_alimento(alimento **lista, const char *nome) {
    alimento *novo = malloc(sizeof(alimento));
    strcpy(novo->nome, nome);
    novo->prox = *lista;
    *lista = novo;
}

// Insere uma colônia e verifica duplicações
void insere_colonia(tabela_hash *tabela, int id, const char *nome) {
    int indice = funcao_hash(id, tabela->tamanho);
    colonia *atual = tabela->tabela[indice];

    // Busca pela colônia
    while (atual != NULL) {
        if (atual->id == id) {
            // Colônia encontrada, verifica duplicação de alimento
            if (alimento_existe(atual->alimentos, nome)) {
                printf("%d\n", id);
            } else {
                insere_alimento(&atual->alimentos, nome);
            }
            return;
        }
        atual = atual->prox;
    }

    // Colônia não encontrada, cria nova
    colonia *nova = malloc(sizeof(colonia));
    nova->id = id;
    nova->alimentos = NULL;
    insere_alimento(&nova->alimentos, nome);
    nova->prox = tabela->tabela[indice];
    tabela->tabela[indice] = nova;
}

int main() {
    tabela_hash *tabela = cria_tabela(TAMANHO_INICIAL);
    int id;
    char nome[11];

    // Lê entrada até EOF
    while (scanf("%d %s", &id, nome) != EOF) {
        insere_colonia(tabela, id, nome);
    }

    // Libera memória
    destroi_tabela(tabela);
    return 0;
}
