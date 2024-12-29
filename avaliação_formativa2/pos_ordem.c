#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

void pos_ordem(no *raiz) {
    if (raiz == NULL) return;

    no *stack[100];
    int top = -1;
    no *current = raiz;
    no *last = NULL;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->esq;
        }

        current = stack[top];
        if (current->dir == NULL || current->dir == last) {
            printf("%d ", current->dado);
            last = current;
            top--;
            current = NULL;
        } else {
            current = current->dir;
        }
    }
}