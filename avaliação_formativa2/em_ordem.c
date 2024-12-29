#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

void em_ordem(no *raiz) {
    if (raiz == NULL) return;

    no *stack[100];
    int top = -1;
    no *current = raiz;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->esq;
        }

        current = stack[top--];
        printf("%d ", current->dado);

        current = current->dir;
    }
}