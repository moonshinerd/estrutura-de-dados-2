#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particiona(int *v, int e, int d){
    int i;
    int pivo=v[e]; //define o item mais a esquerda como o pivo
    int pos=d+1; // coloca a posição ultrapassando d para decrementar quando o valor v[i] for >= ao pivô
    for (i=d; i>= e; i--) { // faz a comparação iterada
        if(v[i]>=pivo) troca(&v[i],&v[--pos]);
    }
    return pos; // retorna onde o pivo parou
}

void quicksort(int *v, int e, int d){
    if(e<=d){
        int p = particiona(v,e,d); // obtem o pivo ordenado
        quicksort(v,e,p-1); // ordena  da esquerda até o pivo sem incluir o pivo
        quicksort(v,p+1,d); // ordena do pivo ate a direita sem incluir o pivo
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