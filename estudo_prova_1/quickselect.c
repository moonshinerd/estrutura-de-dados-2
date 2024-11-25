#include <stdio.h>
#include <stdlib.h>
// o quickselect serve para selecionar o k-ésimo menor/maior elemento de um conjunto
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

int main() {
    int vetor[] = {1, 3, 6, 10, 11, 13, 14};
    int k = 1;
    int a = quickselect(vetor, 0, 6, k);
    printf("%d\n", a);
    return 0;
}
