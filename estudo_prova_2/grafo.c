#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
    int n; // número de vértices
    int **adj; // matriz de adjacência
} grafo;

grafo *cria_grafo(int n){
    grafo *g = malloc(sizeof(grafo)); // aloca memória para a estrutura grafo
    g->adj = malloc(n * sizeof(int*)); // aloca memória para as linhas da matriz
    for (int i = 0; i < n; i++){
        g->adj[i] = calloc(n, sizeof(int)); // aloca memória para as colunas da matriz
    }
    g->n = n; // o número de vértices é n
    return g; // retorna o ponteiro para a estrutura grafo
}

void insere_aresta(grafo *g, int i, int j){
    g->adj[i][j] = 1; // insere a aresta i -> j
    g->adj[j][i] = 1; // insere a aresta j -> i (grafo não direcionado)
    // para um grafo direcionado, basta remover a linha `g->adj[v][u] = 1;`	
}

void remove_aresta(grafo *g, int i, int j){
    g->adj[i][j] = 0; // remove a aresta i -> j
    g->adj[j][i] = 0; // remove a aresta j -> i (grafo não direcionado)
    // para um grafo direcionado, basta remover a linha `g->adj[j][i] = 0;`
}

int grau(grafo *g, int v){ // v é o vértice
    int grau = 0; // inicializa o grau do vértice v
    for (int i = 0; i < g->n; i++){
        grau += g->adj[v][i]; // soma 1 ao grau se houver uma aresta v -> i
    }
    return grau; // retorna o grau do vértice v
}

