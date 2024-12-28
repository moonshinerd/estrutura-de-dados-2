#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *tb; // tabela hash
  int M;      // tamanho da tabela hash
  int N;      // total de chaves presentes na tabela
} TH;

void THredimensiona(TH *h, int M){
    int *tb = malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) { // inicializa a nova tabela
        tb[i] = -1;
    }
    for (int i = 0; i < h->M; i++) { // reinserindo os elementos na nova tabela
        if (h->tb[i] != -1) {
            int j = h->tb[i] % M;
            while (tb[j] != -1) {
                j = (j + 1) % M;
            }
            tb[j] = h->tb[i];
        }
    }
    free(h->tb);
    h->tb = tb;
    h->M = M;
}

void THinsere(TH *h, int ch){
    if (h->N > h->M/2) {
        THredimensiona(h, aumentaTamanho(h->M));
    }
    int i = ch % h->M; // obtem o indice da tabela
    while (h->tb[i] != -1) {
        if (h->tb[i] == ch) return; // impede duplicatas na tabela
        i = (i + 1) % h->M; // insere na proxima posicao caso a posicao atual esteja ocupada
    }
    h->tb[i] = ch; 
    h->N++;
}

int THremove(TH *h, int ch) {
    int i = ch % h->M;
    while (h->tb[i] != ch && h->tb[i] != -1) {
        i = (i + 1) % h->M;
    }
    if (h->tb[i] == -1) return -1; // Chave não encontrada

    // Marca o índice como "removido"
    h->tb[i] = -1;
    h->N--;

    // Reinsere as chaves subsequentes para manter a sequência válida
    i = (i + 1) % h->M;
    while (h->tb[i] != -1) {
        int chaveParaReinserir = h->tb[i];
        h->tb[i] = -1;
        h->N--;
        THinsere(h, chaveParaReinserir);
        i = (i + 1) % h->M;
    }

    return 0;
}


int THbusca(TH *h, int ch){
    int i = ch % h->M;
    while (h->tb[i] != ch && h->tb[i] != -1) {
        i = (i + 1) % h->M;
    }
    if (h->tb[i] == -1) return 0;
    return 1;
}
