#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particiona(int *v, int e, int d){
    int i, pivo=v[e], pos=d+1;
    for (i=d; i>= e; i--) {
        if(v[i]>=pivo) troca(&v[i],&v[--pos]);
    }
    return pos;
}

void quicksort(int *v, int e, int d){
    if(e<=d){
        int p = particiona(v,e,d);
        quicksort(v,e,p-1);
        quicksort(v,p+1,d);
    }
}

int main() {
    int vetor[] = {9, 14, 11, 7, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); // Corrige o cálculo do tamanho

    quicksort(vetor, 0, tamanho - 1); // Passa o índice correto

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}