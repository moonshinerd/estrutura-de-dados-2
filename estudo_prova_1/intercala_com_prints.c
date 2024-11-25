#include <stdio.h>
#include <stdlib.h>

void intercala(int *v, int e, int m, int d) {
    int *aux = malloc((d - e + 1) * sizeof(int));
    int i = e, j = m + 1, k = 0;

    // Exibe o estado do vetor antes da intercalação
    printf("Antes de intercalar (intervalo %d-%d): ", e, d);
    for (int t = e; t <= d; t++) {
        printf("%d ", v[t]);
    }
    printf("\n");

    // Intercala as duas metades
    while (i <= m && j <= d) {
        if (v[i] <= v[j]) {
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
        }
    }

    // Copia os elementos restantes
    while (i <= m) aux[k++] = v[i++];
    while (j <= d) aux[k++] = v[j++];

    // Copia de volta para o vetor original
    for (i = e, k = 0; i <= d; i++, k++) {
        v[i] = aux[k];
    }

    // Exibe o estado do vetor após a intercalação
    printf("Após intercalar (intervalo %d-%d): ", e, d);
    for (int t = e; t <= d; t++) {
        printf("%d ", v[t]);
    }
    printf("\n\n");

    free(aux);
}

void mergesort(int *v, int e, int d) {
    if (e < d) {
        int m = (e + d) / 2;

        // Exibe o estado atual do vetor antes de dividir
        printf("Dividindo (intervalo %d-%d): ", e, d);
        for (int t = e; t <= d; t++) {
            printf("%d ", v[t]);
        }
        printf("\n");

        mergesort(v, e, m);
        mergesort(v, m + 1, d);
        intercala(v, e, m, d);
    }
}

int main() {
    int vetor[] = {5, 6, 8, 56, 3, 8, 8};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    // Ordena o vetor e exibe o progresso
    printf("Vetor original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    mergesort(vetor, 0, tamanho - 1);

    // Imprime o vetor ordenado
    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
