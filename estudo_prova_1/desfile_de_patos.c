#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int vezes_que_apareceu;
    int x; // posição e/ou código
    struct no *prox;
} no;

typedef struct {
    no **tabela; // Ponteiro para ponteiros de nós
    int M, n;    // M = tamanho da tabela; n = elementos inseridos até o momento
} th;

// Criação da hash table
th *cria_hash(int M) {
    th *hash = malloc(sizeof(th));
    hash->tabela = calloc(M, sizeof(no *));
    hash->M = M;
    hash->n = 0;
    return hash;
}

// Função hash
int funcao_hash(int x, int M) {
    return abs(x) % M; // Retorna o índice
}

// Busca se o elemento existe na hash
int busca(th *hash, int x) {
    int i = funcao_hash(x, hash->M);
    no *elem = hash->tabela[i];
    while (elem != NULL) {
        if (elem->x == x) return 1;
        elem = elem->prox;
    }
    return 0;
}

// Busca o endereço do nó
no *busca_endereco(th *hash, int x) {
    int i = funcao_hash(x, hash->M);
    no *elem = hash->tabela[i];
    while (elem != NULL) {
        if (elem->x == x) return elem;
        elem = elem->prox;
    }
    return NULL;
}

// Insere um elemento na hash
void insere_hash(th *hash, int x) {
    int indice = funcao_hash(x, hash->M);
    no *novo = malloc(sizeof(no));
    novo->x = x;
    novo->vezes_que_apareceu = 1; // Primeiro registro
    novo->prox = hash->tabela[indice];
    hash->tabela[indice] = novo;
    hash->n++;
}

// Incrementa o contador de um elemento
void incrementa_vezes(th *hash, int x) {
    no *item = busca_endereco(hash, x);
    if (item != NULL) {
        item->vezes_que_apareceu++;
    }
}

// Retorna o código do elemento que mais apareceu
int codigo_do_que_mais_apareceu(th *hash) {
    int max_vezes = 0;
    int codigo_max = -1;

    for (int i = 0; i < hash->M; i++) {
        no *item = hash->tabela[i];
        while (item != NULL) {
            if (item->vezes_que_apareceu > max_vezes) {
                max_vezes = item->vezes_que_apareceu;
                codigo_max = item->x;
            }
            item = item->prox;
        }
    }

    return codigo_max;
}

// Libera a memória da hash
void destroi_hash(th *hash) {
    for (int i = 0; i < hash->M; i++) {
        no *atual = hash->tabela[i];
        while (atual != NULL) {
            no *prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }
    free(hash->tabela);
    free(hash);
}

// Função principal
int main() {
    int numero_de_patos;
    do {
        scanf("%d", &numero_de_patos);

        if (numero_de_patos == 0) break; // Encerra o programa se for 0

        th *hash = cria_hash(9997);

        for (int i = 0; i < numero_de_patos; i++) {
            int leitor;
            scanf("%d", &leitor);
            if (busca(hash, leitor)) {
                incrementa_vezes(hash, leitor);
            } else {
                insere_hash(hash, leitor);
            }
        }

        printf("%d\n", codigo_do_que_mais_apareceu(hash));
        destroi_hash(hash); // Libera a memória usada pela hash
    } while (numero_de_patos != 0);

    return 0;
}
