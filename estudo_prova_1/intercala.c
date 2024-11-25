#include <stdio.h>
#include <stdlib.h>

void intercala(int *v, int e, int m, int d) {
    int *aux = malloc((d - e + 1) * sizeof(int));
    int i = e, j = m + 1, k = 0; // o k serve para guardar a posição em que o auxiliar está guardando as coisas

    while (i <= m && j <= d) {
        if (v[i] <= v[j]) {
            aux[k++] = v[i++];    
        } else {
            aux[k++] = v[j++];
        }
    }

    while (i <= m) aux[k++] = v[i++]; // copia os elementos restantes da metade esquerda do vetor original para o vetor auxiliar se ainda existirem elementos na metade esquerda que não foram processados no laço principal
    while (j <= d) aux[k++] = v[j++];// copia os elementos restantes da metade direita do vetor original para o vetor auxiliar se ainda existirem elementos na metade direita que não foram processados no laço principal

    k = 0;
    i = e;
    while (i <= d) {
        v[i++] = aux[k++];
    }

    free(aux);
}

void mergesort(int *v, int e, int d) {
    if (e < d) {
        int m = (e + d) / 2;
        mergesort(v, e, m);
        mergesort(v, m + 1, d);
        intercala(v, e, m, d);
    }
}

int main() {
    int vetor[] = {5, 6, 8, 56, 3, 8, 8};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); // Corrige o cálculo do tamanho

    mergesort(vetor, 0, tamanho - 1); // Passa o índice correto

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
