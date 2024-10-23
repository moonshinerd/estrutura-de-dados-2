#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

int remove_depois(celula *p) {
   if (p == NULL || p->prox == NULL) {
      // Não há próximo elemento para remover
      return 0;
   }
   celula *lixo = p->prox;
   p->prox = lixo->prox;
   free(lixo);
   return 1;  // Sucesso
}

void remove_elemento(celula *cabeca, int x) {
   celula *p = cabeca;
   while (p->prox != NULL && p->prox->dado != x) {
      p = p->prox;
   }
   if (p->prox != NULL) {
      remove_depois(p);  // Remove o elemento seguinte que contém x
   }
}

void remove_todos_elementos(celula *cabeca, int x) {
   celula *p = cabeca;
   while (p->prox != NULL) {
      if (p->prox->dado == x) {
         remove_depois(p);  // Remove a célula com o dado x
      } else {
         p = p->prox;  // Avança para a próxima célula
      }
   }
}
