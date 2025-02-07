#include <stdio.h>
#include <stdlib.h>

#define pai(i) (i-1)/2

#define esq(i) 2*i+1
#define dir(i) 2*i+2

typedef struct heap{
    int *v;
    int n; // n é o número de elementos inseridos no vetor
    int tam; // tam é o tamanho do vetor
} heap;

heap *cria_heap(int tam){
    heap *h = malloc(sizeof(heap)); // aloca memória para a estrutura heap
    h->v = malloc(tam * sizeof(int)); // aloca memória para o vetor de inteiros
    h->n = 0; // começa com 0 elementos pois não há nenhum elemento inserido
    h->tam = tam; // o tamanho do vetor é tam
    return h; // retorna o ponteiro para a estrutura heap
}  

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insere(heap *h, int x){
    if(h->n >= h->tam){
        h->v = realloc(h->v, 2 * h->tam *sizeof(int)); // realoca o vetor para o dobro do tamanho atual
        h->tam *= 2; // atualiza o tamanho do vetor pode ser h->tam = h->tam * 2
    }
    h->v[h->n] = x; // insere o elemento na última posição do vetor
    h->n++; // incrementa o número de elementos pois um novo elemento foi inserido
    // correção do heap
    int i = h->n-1; // i é a posição do elemento inserido
    while(i > 0 && h->v[pai(i)] >= h->v[i]){ // o que muda do heap mínimo para o máximo é a comparação
        // h->v[pai(i)] >= h->v[i] para heap mínimo
        // h->v[pai(i)] <= h->v[i] para heap máximo
        troca(&h->v[i], &h->v[pai(i)]); // troca o elemento inserido com o pai
        i = pai(i); // atualiza a posição do elemento inserido
    }
}

int extrai_maximo(heap *h){
    troca(&h->v[0], &h->v[h->n-1]); // troca o primeiro elemento com o último
    h->n--; // decrementa o número de elementos
    int i = 0; // i é a posição do elemento que será corrigido
    while((esq(i) < h->n && h->v[i] < h->v[esq(i)]) || 
        (dir(i) < h->n && h->v[i] < h->v[dir(i)])){
        // enquanto o elemento for menor que o filho esquerdo ou direito
        int maior_filho = esq(i); // suponha que o filho esquerdo é o maior
        if (dir(i) < h->n && h->v[dir(i)] > h->v[maior_filho]){ // se o filho direito for maior que o esquerdo
            maior_filho = dir(i); // o maior filho é o direito
        }
        if (h->v[i] < h->v[maior_filho]){ // se o pai for menor que o maior filho
            troca(&h->v[i], &h->v[maior_filho]); // troca o pai com o maior filho
            i = maior_filho; // atualiza a posição do pai
        }
    }
    return h->v[h->n]; // retorna o elemento que foi removido
}

void imprime(heap *h){
    for(int i = 0; i < h->n; i++){
        printf("%d ", h->v[i]);
    }
    printf("\n");
}

int main(){
    heap *h = cria_heap(10); // cria um heap com tamanho 10
    insere(h, 5); // insere o elemento 5
    imprime(h); // imprime o vetor
    insere(h, 3); // insere o elemento 3
    imprime(h); // imprime o vetor
    insere(h,5);
    imprime(h);
    insere(h, 7); // insere o elemento 7
    imprime(h); // imprime o vetor
    insere(h, 1); // insere o elemento 1
    imprime(h); // imprime o vetor
    return 0;
}