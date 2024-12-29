#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

void pre_ordem(no *raiz) {
    if (raiz == NULL) return;

    no *stack[100];
    int top = -1;
    stack[++top] = raiz;

    while (top >= 0) {
        no *current = stack[top--];
        printf("%d ", current->dado);

        if (current->dir != NULL) {
            stack[++top] = current->dir;
        }
        if (current->esq != NULL) {
            stack[++top] = current->esq;
        }
    }
}