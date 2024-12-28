#include <stdio.h>
#include <stdlib.h>

// tabela hash ou tabela de dispersao

typedef struct no {
    int x;
    struct no *prox;
} no;

typedef struct {
    no **tabela; // Ponteiro para ponteiros de nós
    int M, n;    // M = tamanho da tabela; n = elementos inseridos até o momento
} th;

th *cria_hash(int M) {
    th *hash = malloc(sizeof(th));            // Aloca espaço para a estrutura `th`
    hash->tabela = calloc(M, sizeof(no *));   // Inicializa a tabela hash com espaço para `M` entradas
    hash->M = M;                              // Define o tamanho da tabela como `M`
    hash->n = 0; // o vetor inicializa com 0 elementos
    return hash;                              // Retorna a estrutura criada
}

int funcao_hash(int x, int M) {
    return x % M; // Retorna o índice da tabela hash para o valor `x`
}

int busca(th *hash, int x) {
    int i = funcao_hash(x, hash->M); // Calcula o índice na tabela hash para o valor `x`
    no *elem = hash->tabela[i];      // Acessa a lista encadeada no índice `i`
    while (elem != NULL) {           // Percorre a lista encadeada
        if (elem->x == x) return 1;  // Se encontrar o valor, retorna 1 (encontrado)
        elem = elem->prox;           // Avança para o próximo nó da lista
    }
    return 0;                        // Se não encontrar, retorna 0 (não encontrado)
}

void insere_lista_encadeada(no *lista, int x) {
    no *novo = (no *)malloc(sizeof(no)); // Aloca memória para o novo nó
    novo->x = x;                        // Define o valor do novo nó
    novo->prox = NULL;                  // O novo nó será o último, então prox é NULL

    // Percorre a lista até encontrar o último nó
    no *atual = lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Insere o novo nó no final da lista
    atual->prox = novo;
}

void insere_hash(th *hash, int x) {
    int indice = funcao_hash(x, hash->M); // Calcula o índice na tabela hash

    // Se a lista na posição `indice` estiver vazia, inicializa com um nó cabeça
    if (hash->tabela[indice] == NULL) {
        hash->tabela[indice] = (no *)malloc(sizeof(no));
        hash->tabela[indice]->prox = NULL;
    }

    // Insere o elemento na lista encadeada
    insere_lista_encadeada(hash->tabela[indice], x);
    hash->n++;
}

void remocao(th *hash, int x) {
    int indice = funcao_hash(x, hash->M); // calcula o índice na tabela hash
    no *atual = hash->tabela[indice];    // acessa a lista encadeada no índice no primeiro item da lista
    no *anterior = NULL;                 // inicializando como null pois antes do primeiro no da lista não existe nada

    // Percorre a lista para encontrar o nó com o valor 'x'
    while (atual != NULL) {
        if (atual->x == x) { // Se o valor for encontrado
            if (anterior == NULL) {// Caso especial: o nó a ser removido é o primeiro da lista
                hash->tabela[indice] = atual->prox;
            } else {// remove o nó ajustando os ponteiros nos demais casos
                anterior->prox = atual->prox;
            }
            free(atual);  // Libera a memória do nó removido
            hash->n--;    // Atualiza o contador de elementos
            return;       // Elemento removido com sucesso
        }
        // Avança para o próximo nó
        anterior = atual;
        atual = atual->prox;
    }
    // Se o loop terminar sem encontrar o valor, o elemento não existe na tabela
    printf("Elemento %d não encontrado na tabela hash.\n", x);
}

void destroi_hash(th *hash) {
    // Itera sobre cada posição da tabela
    for (int i = 0; i < hash->M; i++) {
        no *atual = hash->tabela[i]; // Ponteiro para o início da lista
        // Libera todos os nós na lista encadeada
        while (atual != NULL) {
            no *prox = atual->prox; // Salva o próximo nó
            free(atual);            // Libera o nó atual
            atual = prox;           // Move para o próximo nó
        }
    }
    // Libera o array de ponteiros (tabela)
    free(hash->tabela);
    // Libera a estrutura principal
    free(hash);
}

void imprime_hash(th *hash) {
    for (int i = 0; i < hash->M; i++) { // Itera sobre os índices da tabela
        no *atual = hash->tabela[i];
        printf("[%d]: ", i); // Exibe o índice da tabela

        if (atual == NULL) { // Se a lista estiver vazia
            printf("NULL");
        } else {
            atual = atual->prox; // Ignora o nó cabeça
            // Itera sobre os elementos da lista encadeada no índice atual
            while (atual != NULL) {
                printf("%d -> ", atual->x); // Imprime o valor do nó
                atual = atual->prox;       // Avança para o próximo nó
            }
            printf("NULL"); // Indica o final da lista encadeada
        }
        printf("\n"); // Quebra de linha para o próximo índice
    }
}


// Função principal
int main() {
    // Cria uma tabela hash de tamanho 7
    th *hash = cria_hash(20);

    // Insere vários itens na tabela
    int elementos[] = {10, 20, 15, 7, 8, 33, 22, 3, 18, 25,25,5,14};
    int n = sizeof(elementos) / sizeof(elementos[0]);

    for (int i = 0; i < n; i++) {
        insere_hash(hash, elementos[i]);
    }

    // Imprime a tabela hash
    printf("Conteúdo da tabela hash:\n");
    imprime_hash(hash);

    // Destrói a tabela hash e libera memória
    destroi_hash(hash);

    return 0;
}
