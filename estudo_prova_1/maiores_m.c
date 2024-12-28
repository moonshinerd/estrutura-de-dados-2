#include <stdio.h>
#include <stdlib.h>
void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particiona(int *v, int e, int d) {
    int pivo = v[e];
    int pos = d + 1;
    for (int i = d; i > e; i--) {
        if (v[i] >= pivo) { // para encontrar o k-ésimo maior elemento deve-se trocar esse ir para v[i] <= pivô
            troca(&v[i], &v[--pos]);
        }
    }
    troca(&v[e], &v[--pos]);
    return pos;
}

int quickselect(int *v, int e, int d, int k) {
    if (e <= d) {
        int p = particiona(v, e, d);
        if (p == k) return v[p];
        else if (k < p) return quickselect(v, e, p - 1, k);
        else return quickselect(v, p + 1, d, k);
    }
    return -1;
}

void quicksort(int *v, int e, int d){
    if(e<=d){
        int p = particiona(v,e,d); // obtem o pivo ordenado
        quicksort(v,e,p-1); // ordena  da esquerda até o pivo sem incluir o pivo
        quicksort(v,p+1,d); // ordena do pivo ate a direita sem incluir o pivo
    }
}

void imprimeTopM(int *v, int n, int m){
    quickselect(v,0,n-1,n-m);
    quicksort(v, 0, n-m);
    for (int i = n-m; i<n; i++){
        printf("%d ", v[i]);
    }
}

int main(){
    int vetor[]= {12,41,23,123,412,123,43,23,12,53,6,4575,100,86,12,345,12,353,43,54,34};
    imprimeTopM(vetor, 20, 10);
}